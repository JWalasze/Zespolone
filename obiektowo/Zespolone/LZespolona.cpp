#include "LZespolona.hh"
#include <cassert>

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
  assert(modul(Skl2)!=0);
  Wynik = (Skl1 * sprzezenie(Skl2)) / pow(modul(Skl2), 2);
  return Wynik;
}

LZespolona operator / (LZespolona  Skl1,  double Skl2)
{
  LZespolona Wynik;

  Wynik.re = (Skl1.re / Skl2);
  Wynik.im = (Skl1.im / Skl2);
  return Wynik;
}

LZespolona sprzezenie (LZespolona  Skl1)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re;
  Wynik.im = -Skl1.im;
  return Wynik;
}

bool operator == (LZespolona L1, LZespolona L2)
{
  if(L1.re!=L2.re || L1.im!=L2.im)
  {
    return false;
  }
    return true;
}

bool operator != (LZespolona L1, LZespolona L2)
{
  if(L1.re!=L2.re || L1.im!=L2.im)
  {
    return true;
  }
    return false;
}

double modul(LZespolona Skl1)
{
  double Wynik;

  Wynik = sqrt(pow(Skl1.re, 2) + pow(Skl1.im, 2));
  return Wynik;
}

std::istream & operator >> (std::istream &strm, LZespolona &Skl)
{
  char znak;
  strm >> znak;
  if (znak != '(')
    strm.setstate(std::ios::failbit);
  strm >> Skl.re >> Skl.im >> znak;
  if (znak != 'i')
    strm.setstate(std::ios::failbit);
  strm >> znak;
  if (znak != ')')
    strm.setstate(std::ios::failbit);
  strm.ignore();
  return strm;
}

std::ostream & operator << (std::ostream &strm, const LZespolona &Skl)
{
  return strm << '(' << Skl.re << showpos << Skl.im << 'i' << ')' << noshowpos;
}





