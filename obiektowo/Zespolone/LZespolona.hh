#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>
#include <cmath>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Dalej powinny pojawic sie zapowiedzi definicji przeciazen operatorow
 */

LZespolona utworz( double a, double b );

void wypisz(LZespolona l);

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  LZespolona  Skl2);

LZespolona  operator / (LZespolona  Skl1,  double Skl2);

LZespolona sprzezenie(LZespolona  Skl1);

//LZespolona modul(LZespolona  Skl1);

double new_modul(LZespolona Skl1);

//void wypiszdouble(double l);

#endif
