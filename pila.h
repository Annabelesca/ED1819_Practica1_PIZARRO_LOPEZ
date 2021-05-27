#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

/**
* Definim el tipus pila. Aquesta estructura contindrà una vector com a base on guardar els elements (ints en aquest cas)
* i una variable entera que marcarà el nombre d'elements continguts a l'estructura i el cim
**/
typedef struct
{
    int NumElems, MaxElems;
    int *info;
}Pila;

extern Pila Crear_Pila(int max_elem);

extern int EsBuida_Pila(Pila p);

extern int Cim_Pila(Pila p);

extern Pila Apilar_Pila(Pila p, int elem);

extern Pila Desapilar_Pila(Pila p);

extern int EsPlena_Pila(Pila p);

extern void Destruir_Pila(Pila p);

#endif
