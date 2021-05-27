#ifndef CUA_H_INCLUDED
#define CUA_H_INCLUDED

/**
* Definim el tipus pila. Aquesta estructura contindrà una vector com a base on guardar els elements (ints en aquest cas)
* i una variable entera que marcarà el nombre d'elements continguts a l'estructura i el cim
**/
typedef struct
{
    int NumElems,MaxElems,Primer,Ultim;
    int *info;
}Cua;

extern Cua Crear_Cua(int max_elem);

extern int EsBuida_Cua(Cua c);

extern int Cap_Cua(Cua c);

extern Cua Encuar_Cua(Cua c, int elem);

extern Cua Desencuar_Cua(Cua c);

extern int EsPlena_Cua(Cua c);

extern void Destruir_Cua(Cua c);

#endif
