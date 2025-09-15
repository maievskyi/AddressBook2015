// TinyPIM (c) 1999 Pablo Halpern. File AddressBook.h

#ifndef AddressBook_dot_h
#define AddressBook_dot_h
//–усский текст-коммент во всех ф

#include <vector>
#include "Address.h"

class AddressBook
{
public:
    AddressBook();
    ~AddressBook();

    // Exception classes
    class AddressNotFound {};      // несуществующий идентиф номер ______________________
    class DuplicateId {};          // задублированный идентиф номер______________________
    /*    »сключением называетс€ специальное событие при возникновении которого запускаетс€
    специальна€ подпрограмма.
          «апуском исключени€ называетс€ инициализаци€ специальной процедуры, назначенной
      данному исключению.
           ласс исключени€ представл€ет собой спец класс, который выступает параметром
    выражени€ запуска исключени€. ¬ыражение запуска исключени€ использует объект класса
    исключени€ дл€ взаимодействи€ с программным кодом обработки исключени€
    */
    /*
    ‘-ции-члены класса AddresBook
    Public:
    1. int insert... - вставка новой записи
    2. void erase... - стирание записи
    3. void replase... - замена-исправление записи
    4. const Adress*& getAddres...() const - получение и чтение записи по Id
    Private:
       getById      - проверка существовани€ конкретного Id
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

    // Temp Test routine to print out contents of address book
    void print() const; //   “естова€ прог

private:
    // Disable copying
    AddressBook(const AddressBook&); //       ----------------- конструктор копий
    //
    AddressBook& operator=(const AddressBook&); //    --------------- оператор присваивани€ 
    //
    static int nextId_;
    std::vector<Address> addresses_;     //    vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv

    // Get the index of the record with the specified ID.
    int getById(int recordId) const;  //проверка-возврат на существование записи в AddressBook
    // с таким recordId, при неудаче возврат -1   " enum { notFound = -1 } "
    // Returns notFound if not found.
    enum { notFound = -1 };       //  онстанта в виде перечислени€
};

#endif // AddressBook_dot_h
