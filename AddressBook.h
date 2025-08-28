// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.h

#ifndef AddressBook_dot_h
#define AddressBook_dot_h

#include <vector>
#include "Address.h"

class AddressBook
{
public:
  AddressBook();
  ~AddressBook();

  // Exception classes
  class AddressNotFound { };      // несуществующий идентиф номер ______________________
  class DuplicateId { };          // задублированный идентиф номер______________________
  /*    Исключением называется специальное событие при возникновении которого запускается
  специальная подпрограмма.
        Запуском исключения называется инициализация специальной процедуры, назначенной
    данному исключению.
        Класс исключения представляет собой спец класс, который выступает параметром
  выражения запуска исключения. Выражение запуска исключения использует объект класса
  исключения для взаимодействия с программным кодом обработки исключения
  */

// 1
  int insertAddress(const Address& addr, int recordId = 0) //вставка уникального
    throw (DuplicateId);                    // .... //переход если дублированный идентификационный номер ID
// 2
  void eraseAddress(int recordId) throw (AddressNotFound);  // удалить запись в книге по переданному ID
                                                            //переход если ID не найден 
// 3
  void replaceAddress(const Address& addr, int recordId = 0) //перезаписать по нов запись в книге
    throw (AddressNotFound);                                //переход если ID не найден        
// 4
  const Address& getAddress(int recordId) const    //получить-возвратить запись адреса
    throw (AddressNotFound);                        //переход если ID не найден   

  // Test routine to print out contents of address book
  void print() const; //

private:
  // Disable copying
  AddressBook(const AddressBook&); //       ----------------- конструктор копий
  //
  AddressBook& operator=(const AddressBook&); //    --------------- оператор присваивания 
  //
  static int nextId_;
  std::vector<Address> addresses_;     //    vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

  // Get the index of the record with the specified ID.
  // Returns notFound if not found.
  int getById(int recordId) const;  //
  enum { notFound = -1 };       //
};

#endif // AddressBook_dot_h
