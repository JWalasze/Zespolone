#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH
#include <iostream>


#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Funkcje ponizej nalezy zdefiniowac w module.
 *
 */

void Wypisz(WyrazenieZesp WyrZ);

WyrazenieZesp Stworz(LZespolona L1, LZespolona L2, Operator L3);

//void Wyswietl(WyrazenieZesp  WyrZ);

LZespolona Oblicz(WyrazenieZesp  WyrZ);

std::istream & operator >> (std::istream &strm, Operator &Op);

std::istream & operator >> (std::istream &strm, WyrazenieZesp &WZ);

std::ostream & operator << (std::ostream &strm, WyrazenieZesp &WZ);

std::ostream & operator << (std::ostream &strm, Operator &Op);

//bool Wczytaj(LZespolona &L);

//bool PorownajZesp(LZespolona Z1, LZespolona Z2);

#endif
