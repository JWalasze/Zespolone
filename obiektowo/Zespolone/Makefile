
TRGDIR=./
OBJ=./obj
FLAGS= -Wall -pedantic -std=c++14 -iquote inc

__start__: ${TRGDIR}/test_arytm_zesp
	${TRGDIR}/test_arytm_zesp  latwy

${TRGDIR}/test_arytm_zesp: ${OBJ} ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o
	g++ -o ${TRGDIR}/test_arytm_zesp ${OBJ}/main.o ${OBJ}/LZespolona.o\
                     ${OBJ}/WyrazenieZesp.o ${OBJ}/BazaTestu.o ${OBJ}/Statystyka.o

${OBJ}:
	mkdir ${OBJ}

${OBJ}/main.o: main.cpp LZespolona.hh BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/main.o main.cpp

${OBJ}/LZespolona.o: LZespolona.cpp LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/LZespolona.o LZespolona.cpp

${OBJ}/WyrazenieZesp.o: WyrazenieZesp.cpp WyrazenieZesp.hh\
                       LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/WyrazenieZesp.o WyrazenieZesp.cpp

${OBJ}/BazaTestu.o: BazaTestu.cpp BazaTestu.hh WyrazenieZesp.hh\
                       LZespolona.hh
	g++ -c ${FLAGS} -o ${OBJ}/BazaTestu.o BazaTestu.cpp

${OBJ}/Statystyka.o: Statystyka.cpp Statystyka.hh WyrazenieZesp.hh\
                       LZespolona.hh  BazaTestu.hh
	g++ -c ${FLAGS} -o ${OBJ}/Statystyka.o Statystyka.cpp



clear:
	rm -f ${TRGDIR}/test_arytm_zesp ${OBJ}/*
