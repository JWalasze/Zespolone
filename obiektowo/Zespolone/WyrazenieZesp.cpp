#include "WyrazenieZesp.hh"
#include "LZespolona.hh"

using namespace std;

/*!
 * Tu nalezy zdefiniowac funkcje, ktorych zapowiedzi znajduja sie
 * w pliku naglowkowym.
 */

/*bool Wczytaj(LZespolona &L)
{
  char znak;
  cin >> znak;
  if(znak != '(')
  {
  return false;
  }
  cin >> L.re >> L.im;
  cin >> znak;
  if(znak != ')')
  {
  return false;
  }
  return true;
}*/



WyrazenieZesp Stworz(LZespolona L1, LZespolona L2, Operator L3)
{
  WyrazenieZesp  Wynik;

  Wynik.Arg1 = L1;
  Wynik.Arg2 = L2;
  Wynik.Op = L3;
  return Wynik;
}

void Wypisz(WyrazenieZesp WyrZ)
{
  wypisz(WyrZ.Arg1);
  switch (WyrZ.Op)
  {
  case Op_Dodaj : cout << "  " << '+' << "  "; break;

  case Op_Odejmij : cout << "  " << '-' << "  "; break;

  case Op_Mnoz : cout << "  " << '*' << "  "; break;

  case Op_Dziel : cout << "  " << '/' << "  "; break;
  }
  wypisz(WyrZ.Arg2);
  cout << "  " << '=' << "  " << endl;
}

LZespolona Oblicz(WyrazenieZesp  WyrZ)
{
  LZespolona Wynik;
  switch (WyrZ.Op)
  {
    case Op_Dodaj : Wynik = WyrZ.Arg1 + WyrZ.Arg2; return Wynik;

    case Op_Odejmij : Wynik = WyrZ.Arg1 - WyrZ.Arg2; return Wynik;

    case Op_Mnoz : Wynik = WyrZ.Arg1 * WyrZ.Arg2; return Wynik;

    case Op_Dziel : Wynik = WyrZ.Arg1 / WyrZ.Arg2; return Wynik;
  }
}

/*bool PorownajZesp(LZespolona Z1, LZespolona Z2)
{
  if(Z1.re != Z2.re || Z1.im != Z2.im)
  {
  cout << endl << "Blad. Prawidlowym wynikiem jest: ";
  return false;
  }
  else
  {
  cout << endl << "Odpowiedz poprawna";
  return true;
  }
}*/

std::istream & operator >> (std::istream &strm, WyrazenieZesp &WZ) {
  strm >> WZ.Arg1 >> WZ.Op >> WZ.Arg2;
  return strm;
}

std::istream & operator >> (std::istream &strm, Operator &Op) {
  char znak;
  strm >> znak;
  switch(znak)
  {
  case '+' : Op = Op_Dodaj; return strm;

  case '-' : Op = Op_Odejmij; return strm;

  case '*' : Op = Op_Mnoz; return strm;

  case '/' : Op = Op_Dziel; return strm;
  }
}

std::ostream & operator << (std::ostream &strm, WyrazenieZesp &WZ) {
 strm << WZ.Arg1 << WZ.Op << WZ.Arg2 << endl;
 return strm;
}

std::ostream & operator << (std::ostream &strm, Operator &Op) {
  switch(Op)
  {
  case Op_Dodaj : strm << '+'; return strm;

  case Op_Odejmij : strm << '-'; return strm;

  case Op_Mnoz : strm << '*'; return strm;

  case Op_Dziel : strm << '/'; return strm;
  }
}

/*std::istream & operator >> (std::istream &strm, WyrazenieZesp &WZ) {
  char znak;
  strm >> WZ.Arg1 >> znak >> WZ.Arg2;
  switch(znak) {
  case '+' : WZ.Op = Op_Dodaj; return strm;

  case '-' : WZ.Op = Op_Odejmij; return strm;

  case '*' : WZ.Op = Op_Mnoz; return strm;

  case '/' : WZ.Op = Op_Dziel; return strm;
  }
}*/








