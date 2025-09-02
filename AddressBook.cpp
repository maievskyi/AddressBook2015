// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.cpp

#ifndef _msc_ver
#pragma warning(disable : 4786)
#endif

#include <iostream> // For print() function

#include "AddressBook.h"

int AddressBook::nextId_ = 1;

AddressBook::AddressBook()
{
}

AddressBook::~AddressBook()
{
}

int AddressBook::insertAddress(const Address& addr, 
                               int recordId) throw (DuplicateId)
{
  if (recordId == 0)
    // If recordId is not specified, create a new record id.
    recordId = nextId_++; // присв-ть номер и постинкрементировать nextId_
  else if (recordId >= nextId_)
    // Make sure nextId is always higher than any known record id.
    nextId_ = recordId + 1;
  else if (getById(recordId) != notFound)
    // Explicitly-specified ID is not unique
    throw DuplicateId();

  // Append record onto vector.
  addresses_.push_back(addr);

  // Assign an Id to the record
  addresses_.back().recordId(recordId);

  return recordId;
}

int AddressBook::getById(int recordId) const
{
  for (int i = 0; i < addresses_.size(); ++i)
    if (addresses_[i].recordId() == recordId)
      return i;

  return notFound;
}

void AddressBook::eraseAddress(int recordId) 
  throw (AddressNotFound)
{
  int index = getById(recordId);
  if (index == notFound)
    throw AddressNotFound();

  // Move element from end of vector to location being erased.
  addresses_[index] = addresses_.back();

  // Remove the now unused last element of the vector.
  addresses_.pop_back();
}

void AddressBook::replaceAddress(const Address& addr, int recordId)
  throw (AddressNotFound)
{
  if (recordId == 0)
    recordId = addr.recordId();

  int index = getById(recordId);
  if (index == notFound)
    throw AddressNotFound();

  addresses_[index] = addr;
  addresses_[index].recordId(recordId);
}

const Address& AddressBook::getAddress(int recordId) const
  throw (AddressNotFound)
{
  int index = getById(recordId);
  if (index == notFound)
    throw AddressNotFound();

  return addresses_[index];
}

void AddressBook::print() const
{
  std::cout << "******************************************\n";
  for (int i = 0; i < addresses_.size(); ++i)
  {
    const Address& a = addresses_[i];
    std::cout << "Record Id: " << a.recordId() << '\n'
              << a.firstname() << ' ' << a.lastname() << '\n'
              << a.address() << '\n' << a.phone() << '\n' 
	      << std::endl;
  }
}
