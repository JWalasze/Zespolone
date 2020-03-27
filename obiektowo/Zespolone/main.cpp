#include <iostream>
#include "BazaTestu.hh"
#include "LZespolona.hh"
#include "WyrazenieZesp.hh"

using namespace std;




int main(int argc, char **argv)
{



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

  WyrazenieZesp WyrZ_PytanieTestowe;
  WyrazenieZesp &WyrZ = WyrZ_PytanieTestowe;

  statystyka Stat = { 0, 0 };
  statystyka &S = Stat;

  while (PobierzNastpnePytanie(&BazaT,&WyrZ_PytanieTestowe)) {

    cout << "Podaj wynik operacji: ";
    cout << WyrZ;

    LZespolona Odpowiedz;
    LZespolona &L = Odpowiedz;
    cout << "Twoja odpowiedz: ";
    cin >> L;
    if ( cin.fail() ) {
    cerr << "Blad formatu liczby zespolonej. Sprobuj jeszcze raz"; cout << endl << "Zostaly 3 proby" << endl;
    cin.clear();
    cin.ignore( 1000, '\n' );
    cout << "Twoja odpowiedz: ";
    cin >> L;
    if ( cin.fail() ) {
    cerr << "Blad formatu liczby zespolonej. Sprobuj jeszcze raz"; cout << endl << "Zostaly 2 proby" << endl;
    cin.clear();
    cin.ignore( 1000, '\n' );
    cout << "Twoja odpowiedz: ";
    cin >> L;
    if ( cin.fail() ) {
    cerr << "Blad formatu liczby zespolonej. Sprobuj jeszcze raz"; cout << endl << "Zostala 1 proba" << endl;
    cin.clear();
    cin.ignore( 1000, '\n' );
    cout << "Twoja odpowiedz: ";
    cin >> L;
    if ( cin.fail() ) {
    cerr << "Blad formatu liczby zespolonej. Brak prob";
    cin.clear();
    cin.ignore( 1000, '\n' );
    }}}}


    LZespolona Wynik;
    Wynik = Oblicz(WyrZ_PytanieTestowe);

    if(Wynik == Odpowiedz)
    {
    cout << endl << "Odpowiedz poprawna" << endl;
    dodaj_dobra(S);
    }
    else
    {
    cout << endl << "Blad. Prawidlowym wynikiem jest: ";
    cout << Wynik;
    }

    dodaj_pyt(S);

    cout << endl;
    cout << endl;
  }

  cout << S;

  cout << endl;
  cout << " Koniec testu" << endl;
  cout << endl;

}
