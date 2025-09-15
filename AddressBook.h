// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.h

#ifndef AddressBook_dot_h
#define AddressBook_dot_h
//������� �����-������� �� ���� �

#include <vector>
#include "Address.h"

class AddressBook
{
public:
    AddressBook();
    ~AddressBook();

    // Exception classes
    class AddressNotFound {};      // �������������� ������� ����� ______________________
    class DuplicateId {};          // ��������������� ������� �����______________________
    /*    ����������� ���������� ����������� ������� ��� ������������� �������� �����������
    ����������� ������������.
          �������� ���������� ���������� ������������� ����������� ���������, �����������
      ������� ����������.
          ����� ���������� ������������ ����� ���� �����, ������� ��������� ����������
    ��������� ������� ����������. ��������� ������� ���������� ���������� ������ ������
    ���������� ��� �������������� � ����������� ����� ��������� ����������
    */
    /*
    �-���-����� ������ AddresBook
    Public:
    1. int insert... - ������� ����� ������
    2. void erase... - �������� ������
    3. void replase... - ������-����������� ������
    4. const Adress*& getAddres...() const - ��������� � ������ ������ �� Id
    Private:
       getById      - �������� ������������� ����������� Id
    */

    // 1
    int insertAddress(const Address& addr, int recordId = 0) //������� �����������
        throw (DuplicateId);                    // .... //������� ���� ������������� ����������������� ����� ID
    // 2
    void eraseAddress(int recordId) throw (AddressNotFound);  // ������� ������ � ����� �� ����������� ID
    //������� ���� ID �� ������ 
// 3
    void replaceAddress(const Address& addr, int recordId = 0) //������������ �� ��� ������ � �����
        throw (AddressNotFound);                                //������� ���� ID �� ������        
    // 4
    const Address& getAddress(int recordId) const    //��������-���������� ������ ������
        throw (AddressNotFound);                        //������� ���� ID �� ������   

    // Temp Test routine to print out contents of address book
    void print() const; //   �������� ����

private:
    // Disable copying
    AddressBook(const AddressBook&); //       ----------------- ����������� �����
    //
    AddressBook& operator=(const AddressBook&); //    --------------- �������� ������������ 
    //
    static int nextId_;
    std::vector<Address> addresses_;     //    vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

    // Get the index of the record with the specified ID.
    int getById(int recordId) const;  //��������-������� �� ������������� ������ � AddressBook
    // � ����� recordId, ��� ������� ������� -1   " enum { notFound = -1 } "
    // Returns notFound if not found.
    enum { notFound = -1 };       // ��������� � ���� ������������
};

#endif // AddressBook_dot_h
