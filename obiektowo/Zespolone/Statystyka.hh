#ifndef STATYSTYKA_HH
#define STATYSTYKA_HH

#include <iostream>


struct statystyka {
  int liczba_poprawnych;
  int liczba_pytan;
};

int zwroc_liczbe_poprawnych(statystyka &S);

int zwroc_procent_dobrych(statystyka &S);

void wyswietl_podsumowanie(statystyka &S);

void inicjuj_podsumowanie(statystyka &S);

void dodaj_dobra(statystyka &S);

void dodaj_zla(statystyka &S);


















#endif
