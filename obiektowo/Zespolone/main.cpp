#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"
#include "Statystyka.hh"

using namespace std;




int main(int argc, char **argv)
{

  /*LZespolona L1 = utworz(-2.5,3);
  //wypisz(L1);

  LZespolona L2 = utworz(3,4);
  wypisz(L2);

  LZespolona L3 = L1 / L2;
  wypisz(L3);

  LZespolona L4 = utworz(3,-3);
  wypisz(L4);
  LZespolona L5 = sprzezenie(L4);
  wypisz(L5);

  LZespolona L6 = utworz(3,4);
  wypisz(L6);
  double L7 = new_modul(L6);
  wypiszdouble(L7);
  //LZespolona L7 = modul(L6);
  //wypisz(L7);
  cout << 16 / 4;

  //Wczytaj(L1);
  LZespolona &A = L1;
  WyrazenieZesp Z = Stworz(L1, L2, Op_Dziel);
  Wypisz(Z);
  LZespolona L = Oblicz(Z);
  wypisz(L);
  //PorownajZesp(L1, L2);

  if(Wczytaj(A)==true)
  {
  cout << "ok";
  }
  else
  {
  cout << "nie ok";
  }*/




if (argc < 2) {
    cout << endl;
    cout << " Brak opcji okreslajacej rodzaj testu." << endl;
    cout << " Dopuszczalne nazwy to:  latwy, trudny." << endl;
    cout << endl;
    return 1;
  }





  BazaTestu   BazaT = { nullptr, 0, 0 };

  if (InicjalizujTest(&BazaT,argv[1]) == false) {
    cerr << " Inicjalizacja testu nie powiodla sie." << endl;
    return 1;
  }



  cout << endl;
  cout << " Start testu arytmetyki zespolonej: " << argv[1] << endl;
  cout << endl;

  WyrazenieZesp   WyrZ_PytanieTestowe;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {
    /*cout << " Czesc rzeczywista pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.re << endl;
    cout << " Czesc urojona pierwszego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg1.im << endl;
    cout << " Operator wyrazenia ";
    //cout << WyrZ_PytanieTestowe.Op << endl;
     switch (WyrZ_PytanieTestowe.Op)
  {
  case Op_Dodaj : cout << "  " << '+' << "  "<< endl; break;

  case Op_Odejmij : cout << "  " << '-' << "  "<< endl; break;

  case Op_Mnoz : cout << "  " << '*' << "  "<< endl; break;

  case Op_Dziel : cout << "  " << '/' << "  "<< endl; break;
  }
    cout << " Czesc rzeczywista drugiego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg2.re << endl;
    cout << " Czesc urojona drugiego argumentu: ";
    cout << WyrZ_PytanieTestowe.Arg2.im << endl;*/

    cout << "Podaj wynik operacji: ";
    Wypisz(WyrZ_PytanieTestowe);

    LZespolona Odpowiedz;
    //&L = Odpowiedz;
    cin >> Odpowiedz.re >> Odpowiedz.im;
    cout << "Twoja odpowiedz: " << '(' << Odpowiedz.re << showpos << Odpowiedz.im << 'i' << noshowpos << ')';
    //Wczytaj(L);


    LZespolona Wynik;
    Wynik = Oblicz(WyrZ_PytanieTestowe);

    if(PorownajZesp(Wynik, Odpowiedz)==false)
    {
    wypisz(Wynik);
    }

    cout << endl;
    cout << endl;
  }


  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;










}
