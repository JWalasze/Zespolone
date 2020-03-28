#include <iostream>
#include "Statystyka.hh"

using namespace std;


void inicjuj_podsumowanie(statystyka &S)
{
 if(S.liczba_poprawnych > S.liczba_pytan)
 {
 cout << "Blad. Niepoprawna ilosc pytan" << endl;
 }
}

void dodaj_dobra(statystyka &S)
{
  S.liczba_poprawnych++;
}

void dodaj_pyt(statystyka &S)
{
  S.liczba_pytan++;
}

int zwroc_liczbe_poprawnych(statystyka &S)
{
 return S.liczba_poprawnych;
}

int zwroc_liczbe_pytan(statystyka &S)
{
  return S.liczba_pytan;
}

int zwroc_procent_dobrych(statystyka &S)
{
 return S.liczba_poprawnych * 100 / S.liczba_pytan;
}

std::ostream & operator << (ostream & strm, statystyka &S)
{
 strm << "Ilosc dobrych odpowiedzi: " << zwroc_liczbe_poprawnych(S) << endl;
 strm << "Ilosc blednych odpowiedzi: " << zwroc_liczbe_pytan(S) - zwroc_liczbe_poprawnych(S) << endl;
 strm << "Wynik procentowy poprawnych odpowiedzi: " << zwroc_procent_dobrych(S) << '%' << endl;
 return strm;
}
