// Prosze dopisac pliki *.h oraz *.cpp.

// Celem zadania jest implementacja listy jednokierunkowej.
// Każdy element listy jednokierunkowej zawiera dane oraz wskaźnik na kolejny element
// listy. Dla ostatniego elementu listy wskaźnik ten jest ustawiony na NULL (nullptr).

// Zadanie najprosciej jest rozwiazac tworzac dwie struktury:
// node (wezel) - odpowiadajaca jednemu elementowi listy. Powinna zawierac dane oraz
// wskaznik do nastepnego elementu.
// struktura glowna (List) - zawierajaca adres początku listy czyli pierwszego elementu (head).

// Niektóre z funkcji nie zmieniają listy i z tego powodu powinny odbierać
// stały wskaźnik do struktury List.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod, a takze dokumentacje).

// Pliku main.cpp nie wolno modyfikowac (oczywiście w trakcie pracy można sobie
// komentować fragmenty).

// CMakeLists.txt dolaczony do rozwiazania powinien tworzyc plik wykonywalny
// o nazwie Lab05. Program nalezy kompilowac z flagami -Wall -g.
// Prosze zadbac o dobre zarzadzanie pamiecia.

// Przy wykonaniu zadania nie wolno korzystać z internetu, notatek,
// ani żadnych innych materiałów (w tym własnych wcześniej
// przygotowanych plików)

// Rozwiązanie (archiwum zip) należy przesłać na UPeL do godziny 9:30.

// Przypominam, ze nie oceniam programow, ktore sie nie kompiluja.
//


// Powodzenia!

#include <iostream>
#include <cstring>
#include "lab05.h"
#include "lab05.h"

using namespace std;
int main() {
  List testList;
  cout << "Przygotowuje liste do wstawiania danych." << endl;
  prepare(&testList);
  const List* lptr = &testList;
  char buffer[100];
  
  cout << "Kopiuje nazwe..." << endl;
  strcpy(buffer, "Jakaś");
  add(&testList, buffer);
  
  strcpy(buffer, "lista");
  add(&testList, buffer);
  
  strcpy(buffer, "jednokierunkowa.");
  add(&testList, buffer);
    
  cout << "Elementy dodane" << endl;
  std::cout << "empty() " << empty(lptr) << std::endl;
  std::cout << lptr->head->data << std::endl;
  std::cout << lptr->head->next->data << std::endl;

  cout << "Wypisuje cala liste:" << endl;
  dump(lptr);
  std::cout << "\n";

  
  List testList2;
  prepare(&testList2);
  strcpy(buffer, "Moja kolejna");
  add(&testList2, buffer);

  strcpy(buffer, "lista");
  add(&testList2, buffer);


  
  clear(&testList);
  std::cout << "empty() " << empty(lptr) << std::endl;
  dump(lptr);
  std::cout << "\n";
  
  cout << "Druga lista:" << endl;
  dump(&testList2);
  std::cout << "\n";
  
  clear(&testList2);
}

// Przygotowuje liste do wstawiania danych.
/*
Przygotowuje liste do wstawiania danych.
Kopiuje nazwe...
Elementy dodane
empty() 0
Jakaś
lista
Wypisuje cala liste:
Jakaś lista jednokierunkowa.
empty() 1

Druga lista:
Moja kolejna lista
*/
