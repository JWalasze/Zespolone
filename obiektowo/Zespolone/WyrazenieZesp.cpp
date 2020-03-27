#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

using namespace std;

/*!
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
  switch (WyrZ.Op)
  {
    case Op_Dodaj : Wynik = WyrZ.Arg1 + WyrZ.Arg2; break;//return Wynik;

    case Op_Odejmij : Wynik = WyrZ.Arg1 - WyrZ.Arg2; break;//return Wynik;

    case Op_Mnoz : Wynik = WyrZ.Arg1 * WyrZ.Arg2; break;//return Wynik;

    case Op_Dziel : Wynik = WyrZ.Arg1 / WyrZ.Arg2; break;//return Wynik;
  }
  return Wynik;
}

std::istream & operator >> (std::istream &strm, WyrazenieZesp &WZ) {
  strm >> WZ.Arg1 >> WZ.Op >> WZ.Arg2;
  return strm;
}

std::istream & operator >> (std::istream &strm, Operator &Op) {
  char znak;
  strm >> znak;
  switch(znak)
  {
  case '+' : Op = Op_Dodaj; break;//return strm;

  case '-' : Op = Op_Odejmij; break;//return strm;

  case '*' : Op = Op_Mnoz; break;//return strm;

  case '/' : Op = Op_Dziel; break;//return strm;
  }
  return strm;
}

std::ostream & operator << (std::ostream &strm, const WyrazenieZesp &WZ) {
 strm << WZ.Arg1 << WZ.Op << WZ.Arg2 << endl;
 return strm;
}

std::ostream & operator << (std::ostream &strm, const Operator &Op) {
  switch(Op)
  {
  case Op_Dodaj : strm << '+'; break;//return strm;

  case Op_Odejmij : strm << '-'; break;//return strm;

  case Op_Mnoz : strm << '*'; break;//return strm;

  case Op_Dziel : strm << '/'; break;//return strm;
  }
  return strm;
}

