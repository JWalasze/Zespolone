#include <iostream>
#include <cstring>
#include <cassert>
#include "BazaTestu.hh"

using namespace std;

/*
 * Tablica, ktora jest widoczna tylko w tym module.
 * Zawiera ona tresc latwego testu.
 */
static WyrazenieZesp  TestLatwy[] =
  { {{2,1}, Op_Dodaj, {1,2}},
    {{1,0}, Op_Odejmij, {0,1}},
    {{3,0}, Op_Mnoz, {0,3}},
    {{4,8}, Op_Dziel, {0,0}},
  };

/*
 * Analogicznie zdefiniuj test "trudne"
 *
 */

static WyrazenieZesp  TestTrudny[] =
  { {{2.5,10}, Op_Dodaj, {1,9}},
    {{4.2,5.7}, Op_Odejmij, {-2.5,17}},
    {{8,2}, Op_Mnoz, {-1,4}},
    {{7,1}, Op_Dziel, {3.8,4.1}},
  };



/*
 * W bazie testu ustawia wybrany test jako biezacy test i indeks pytania
 * ustawia na pierwsze z nich.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu,
 *    wskTabTestu  - wskaznik na tablice zawierajaca wyrazenia arytmetyczne
 *                   bedace przedmiotem testu,
 *    IloscElemTab - ilosc pytan w tablicy.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskTabTestu zawiera wskaznik na istniejaca tablice.
 *      - Parametr IloscPytan zawiera wartosc, ktora nie przekracza ilosci elementow
 *        w tablicy dostepnej poprzez wskTabTestu.
 */
void UstawTest( BazaTestu *wskBazaTestu, WyrazenieZesp *wskTabTestu, unsigned int IloscPytan )
{
  wskBazaTestu->wskTabTestu = wskTabTestu;
  wskBazaTestu->IloscPytan = IloscPytan;
  wskBazaTestu->IndeksPytania = 0;
}




/*
 * Inicjalizuje test kojarzac zmienna dostepna poprzez wskaznik wskBazaTestu
 * z dana tablica wyrazen, ktora reprezentuje jeden z dwoch dopuszczalnych
 * testow.
 * Parametry:
 *    wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *    sNazwaTestu  - wskaznik na napis wybranego typu testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr sNazwaTestu musi wskazywac na jedna z nazw tzn. "latwe" lub "trudne".
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i test zostanie poprawnie
 *              zainicjalizowany,
 *       false - w przypadku przeciwnym.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char *sNazwaTestu )
{
  if (!strcmp(sNazwaTestu,"latwy")) {
    UstawTest(wskBazaTestu,TestLatwy,sizeof(TestLatwy)/sizeof(WyrazenieZesp));
    return true;
  }
  /*
   * Analogicznie zrob inicjalizacje dla testu trudne
   */

  if (!strcmp(sNazwaTestu,"trudny")) {
    UstawTest(wskBazaTestu,TestTrudny,sizeof(TestTrudny)/sizeof(WyrazenieZesp));
    return true;
  }

  cerr << "Otwarcie testu '" << sNazwaTestu << "' nie powiodlo sie." << endl;
  return false;
}



/*!
 * Funkcja udostepnia nastepne pytania o ile jest odpowiednia ich ilosc.
 * Parametry:
 *       wskBazaTestu - wskaznik na zmienna reprezentujaca baze testu.
 *       wskWyrazenie - wskaznik na zmienna, do ktorej zostanie wpisane
 *                      kolejne wyrazenie z bazy testu.
 *
 * Warunki wstepne:
 *      - Parametr wskBazaTestu nie moze byc pustym wskaznikiem. Musi zawierac adres
 *        zmiennej reprezentujacej baze testu, ktora wczesniej zostal poprawnie
 *        zainicjalizowany poprzez wywolanie funkcji InicjalizujTest.
 *      - Parametr wskWyrazenie nie moze byc pustym wskaznikiem. Musi wskazywac na
 *        istniejaca zmienna.
 *
 * Zwraca:
 *       true - gdy operacja sie powiedzie i parametrowi *wskWyrazenie zostanie
 *              przypisane nowe wyrazenie zespolone z bazy,
 *       false - w przypadku przeciwnym.
 */
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu, WyrazenieZesp *wskWyrazenie )
{
  if (wskBazaTestu->IndeksPytania >= wskBazaTestu->IloscPytan) return false;

  *wskWyrazenie = wskBazaTestu->wskTabTestu[wskBazaTestu->IndeksPytania];
  ++wskBazaTestu->IndeksPytania;
  return true;
}


/*double procent_popr(statystyka l)
{
  double Wynik;

  Wynik = l.liczba_poprawnych / l.liczba_pytan;
  return Wynik;
}*/

void inicjuj_podsumowanie(statystyka &S)
{
 if(S.liczba_poprawnych > S.liczba_pytan)
 {
 cout << "Blad. Niepoprawna ilosc pytan" << endl;
 }
}

void dodaj_dobra(statystyka &S)
{
  S.liczba_poprawnych++;
}

void dodaj_pyt(statystyka &S)
{
  S.liczba_pytan++;
}

int zwroc_liczbe_poprawnych(statystyka &S)
{
 return S.liczba_poprawnych;
}

int zwroc_liczbe_pytan(statystyka &S)
{
  return S.liczba_pytan;
}

int zwroc_procent_dobrych(statystyka &S)
{
 return S.liczba_poprawnych * 100 / S.liczba_pytan;
}

std::ostream & operator << (ostream & strm, statystyka &S)
{
 strm << "Ilosc dobrych odpowiedzi: " << zwroc_liczbe_poprawnych(S) << endl;
 strm << "Ilosc blednych odpowiedzi: " << zwroc_liczbe_pytan(S) - zwroc_liczbe_poprawnych(S) << endl;
 strm << "Wynik procentowy poprawnych odpowiedzi: " << zwroc_procent_dobrych(S) << '%' << endl;
 return strm;
}
