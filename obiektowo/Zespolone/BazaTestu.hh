#ifndef BAZATESTU_HH
#define BAZATESTU_HH


#include "WyrazenieZesp.hh"


/*
 * Modeluje pojecie baze testu z zestawem pytan w tablicy
 * oraz informacji o maksymalnej ilosci pytan, jak
 * tez indeksem nastepnego pytania, ktore ma byc pobrane
 * z bazy.
 */
struct BazaTestu {
  WyrazenieZesp  *wskTabTestu;   /* Wskaznik na tablice zawierajaca pytania testu */
  unsigned int    IloscPytan;    /* Ilosc wszystkich pytan */
  unsigned int    IndeksPytania; /* Numer pytania, ktore ma byc pobrane jako nastepne */
};



/*
 * Inicjalizuje test powiazany z dana nazwa.
 */
bool InicjalizujTest( BazaTestu  *wskBazaTestu, const char*  sNazwaTestu );
/*
 * Udostepnia nastepne pytanie z bazy.
 */
bool PobierzNastpnePytanie( BazaTestu  *wskBazaTestu,  WyrazenieZesp *wskWyr );




struct statystyka {
  int liczba_poprawnych;
  int liczba_pytan;
};

int zwroc_liczbe_poprawnych(statystyka &S);

int zwroc_procent_dobrych(statystyka &S);

int zwroc_liczbe_pytan(statystyka &S);

std::ostream & operator << (std::ostream & strm, statystyka &S);

void inicjuj_podsumowanie(statystyka &S);

void dodaj_dobra(statystyka &S);

void dodaj_pyt(statystyka &S);

#endif
