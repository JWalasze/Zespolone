#include "LZespolona.hh"

using namespace std;

/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */
LZespolona operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = (Skl1.re * Skl2.re - Skl1.im * Skl2.im);
  Wynik.im = (Skl1.re * Skl2.im + Skl1.im * Skl2.re);
  return Wynik;
}

LZespolona operator / (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona Wynik;

  Wynik = (Skl1 * sprzezenie(Skl2)) / pow(new_modul(Skl2), 2);
  return Wynik;
}

LZespolona operator / (LZespolona  Skl1,  double Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re / Skl2);
  Wynik.im = (Skl1.im / Skl2);
  return Wynik;
}

LZespolona sprzezenie(LZespolona  Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
  return Wynik;
}

/*LZespolona modul(LZespolona  Skl1)
{
  LZespolona  Wynik;

  Wynik.re = sqrt(pow(Skl1.re, 2) + pow(Skl1.im, 2));
  Wynik.im = 0;
  return Wynik;
}*/

double new_modul(LZespolona Skl1)
{
  double Wynik;

  Wynik = sqrt(pow(Skl1.re, 2) + pow(Skl1.im, 2));
  return Wynik;
}

LZespolona utworz( double a, double b )
{
  LZespolona l;
  l.re = a;
  l.im = b;

  return l;
}

void wypisz(LZespolona l)
{
   cout << '(' << l.re << showpos << l.im << 'i' << ')' << noshowpos;
}

/*void wypiszdouble(double l)
{
  cout << l << endl;
}*/


