testAnnabelPizarroLopez : test.o pila.o cua.o llista.o
	gcc test.o pila.o cua.o llista.o -o testAnnabelPizarroLopez 

pila.o : pila.c pila.h
	gcc -Wall -c pila.c -o pila.o

cua.o : cua.c cua.h
	gcc -Wall -c cua.c -o cua.o

llista.o : llista.c llista.h
	gcc -Wall -c llista.c -o llista.o

test.o : test.c TADs.h
	gcc -Wall -c test.c -o test.o

clean : 
	rm *.o 

