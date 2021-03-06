#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>

struct statystyka {
  int liczba_poprawnych;
  int liczba_pytan;
};

int zwroc_liczbe_poprawnych(statystyka &S);

int zwroc_procent_dobrych(statystyka &S);

int zwroc_liczbe_pytan(statystyka &S);

std::ostream & operator << (std::ostream & strm, statystyka &S);

void inicjuj_podsumowanie(statystyka &S);

void dodaj_dobra(statystyka &S);

void dodaj_pyt(statystyka &S);


#endif
