// TinyPIM (c) 1999 Pablo Halpern. File AddressBookTest.cpp
// Русский текст-коммент во всех ф

//#define _CRT_SECURE_NO_WARNINGS  //my orfogr mistakes ???  my
#include <windows.h>//my
#include <iostream>
#include "AddressBook.h"
#include <locale.h> /* Для русского языка ...........................*/
// проверка на кирилицу UTF-8 UTF-8


int main()
{
    //SetConsoleCP(1251);     // my +  #include <windows.h>   //my
   // SetConsoleOutputCP(1251); // my +  #include <windows.h>   //my
	//system("chcp 1251");
	setlocale(LC_ALL, "Rus"); /* Обязательно должно быть первым........ */

	std::cout << "*** Русский текст в cout ***\n";

  AddressBook book;     // конструктором класса AddressBook создаётся объект book
 
  Address a;  //созд-е объекта а (=записи=адреса)
  a.lastname("Smith"); // заполнение полей с помощью соответствующих 
  a.firstname("Joan");      // перегруженных методов класса Address
  a.phone("(617) 555-9876");
  a.address("The Very Big Corporation\nSomewhere, MA 01000");

  Address b;  //созд-е объекта b (=записи=адреса)
  b.lastname("Adams");
  b.firstname("Abigale");
  b.phone("(212) 555-3734");
  b.address("743 Broadway\nNew York, NY");

  Address c;  //созд-е объекта c (=записи=адреса)
  c.lastname("Neighborhood Video");
  c.phone("555-FILM");

  // в переменных сохр id номера записей AddressBook
  int a_id = book.insertAddress(a);
  int b_id = book.insertAddress(b);
  int c_id = book.insertAddress(c);
  std::cout << "*** Three Address Entries ***\n";
  book.print();

  //созд-е объекта d с дублированием 1го имени и 2го имени с объектом b
  //     Адрес d имеет те же имена в полях, что и b
  Address d;    
  d.lastname("Adams");
  d.firstname("Abigale");
  d.phone("(508) 555-4466");
  d.address("1 Small St.\nMarlboro, MA 02100");

  // Insert address with duplicate name вставка адреса с дубл именем
  int d_id = book.insertAddress(d);  // сохр в AddressBook
  std::cout << "*** After adding a duplicate Abigale Adams ***\n";
  book.print();  // появляется запись в книгу с новым id

  // Erase an address удаление
  book.eraseAddress(a_id);
  std::cout << "*** After erasing Joan Smith ***\n";
  book.print();

  // Replace an address исправление
  c.address("22 Main St.\nMy town, MA 02200");
  book.replaceAddress(c, c_id);
  std::cout << "*** After replacing Neighborhood Video ***\n";
  book.print();

  // Get and print address
  const Address& d2 = book.getAddress(d_id);
  std::cout << "*** Copy of d: ***\n"
            << d2.firstname() << ' ' << d2.lastname() << '\n'
            << d2.address() << '\n' << d2.phone() << '\n' 
            << std::endl;
  system("pause");
  return 0;
}
