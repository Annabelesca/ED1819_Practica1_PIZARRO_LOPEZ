#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/**********************************************************
Crear_Pila
Constructor del tipus pila. Crea una estructura de dades
de tipus Pila i inicialitza les seves variables.
Paràmetres:
    max_elem: enter que representa el nombre ḿàxim
    d'elementsque podrà contenir l'estructura.
Retorna: Estructura de tipus Pila buida
**********************************************************/
Pila Crear_Pila(int max_elem){
    Pila P;
    P.NumElems=0;
    P.MaxElems=max_elem;
    P.info=(int *)malloc(max_elem*sizeof(int));
    return P;
}

/**********************************************************
missatgeError_Pila
Mètode que s'encarrega de printejar els errors que es
produeixen i fa que la funció que l'ha cridat s'acabi.
Paràmetres:
    i: enter que representa quin tipus d'error s'ha produit
    (1 si l'estructura es buida, 0 si es plena)
**********************************************************/
void missatgeError_Pila(int i){
    switch (i){
    case 0:
        printf("Error. Pila Buida\n");
        break;

    case 1:
        printf("Error. Pila Plena\n");
        break;
    }
}

/**********************************************************
EsBuida_Pila
Mètode que comprova si l'estructura es plena
Paràmetres:
    P: Pila la qual es vol comprovar
Retorna:
    1 si l'estructura es buida, 0 altrament
**********************************************************/
int EsBuida_Pila(Pila p){
    return(p.NumElems==0);
}

/**********************************************************
EsPlena_Pila
Mètode que comprova si l'estructura es plena
Paràmetres:
    P: Pila la qual es vol comprovar
Retorna:
    1 si l'estructura es plena, 0 altrament
**********************************************************/
int EsPlena_Pila(Pila p){
    return(p.NumElems==p.MaxElems);
}

/**********************************************************
Cim_Pila
Mètode retorna l'ultim element apilat (Cim) de l'estructura
Paràmetres:
    P: Pila de la qual es vol obtenir el cim
Retorna:
    Enter amb el valor del cim o un error si estructura
    es buida
**********************************************************/
int Cim_Pila(Pila p){
    int cim;
    if (EsBuida_Pila(p)) {
        missatgeError_Pila(0);
    }else cim=p.info[p.NumElems-1];
    return cim;
}

/**********************************************************
Apilar_Pila
Mètode que afegeix un element a l'estructura
Paràmetres:
    P: Pila a la qual es vol inserir l'element
Retorna:
    Pila amb l'element emmagatzemat o error si estructura
    es plena
**********************************************************/
Pila Apilar_Pila(Pila p, int elem){
    if (p.NumElems==p.MaxElems) missatgeError_Pila(1);
    else{
        p.info[p.NumElems]=elem;
        p.NumElems++;
    }
    return p;
}

/**********************************************************
Desapilar_Pila
Mètode que elimina l'element que es troba al cim de
l'estructura
Paràmetres:
    P: Pila de la qual es vol esborrar l'element
Retorna:
    Pila amb un nou cim o error si estructura es buida
**********************************************************/
Pila Desapilar_Pila(Pila p){
    if (EsBuida_Pila(p)) missatgeError_Pila(0);
    else p.NumElems--;
    return p;
}

/**********************************************************
Destruir_Pila
Mètode que allibera l'espai reservat per la pila
Paràmetres:
    P: Pila espai del qual es vol alliberar
**********************************************************/
void Destruir_Pila(Pila p){
    free(p.info);
}

