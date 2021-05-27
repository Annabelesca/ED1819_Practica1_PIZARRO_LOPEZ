#include <stdio.h>
#include <stdlib.h>
#include "cua.h"

/**********************************************************
Crear_Cua
Constructor del tipus Cua. Crea una estructura de dades de
tipus Cua i inicialitza les seves variables.
Paràmetres:
    max_elem: enter que representa el nombre ḿàxim
    d'elementsque podrà contenir l'estructura.
Retorna: Estructura de tipus Cua buida
**********************************************************/
Cua Crear_Cua(int max_elem){
    Cua C;
    C.NumElems=0;
    C.MaxElems=max_elem;
    C.Primer=0;
    C.Ultim=0;
    C.info=(int *)malloc(max_elem*sizeof(int));
    return C;
}

/**********************************************************
missatgeError_Cua
Mètode que s'encarrega de printejar els errors que es
produeixen i fa que la funció que l'ha cridat s'acabi.
Paràmetres:
    i: enter que representa quin tipus d'error s'ha produit
    (0 si l'estructura es buida, 1 si es plena)
**********************************************************/
void missatgeError_Cua(int i){
    switch (i){
    case 0:
        printf("Error. Cua Buida\n");
        break;

    case 1:
        printf("Error. Cua Plena\n");
        break;
    }
}

/**********************************************************
EsBuida_Cua
Mètode que comprova si l'estructura es buida.
Paràmetres:
    c: Cua la qual es vol comprovar
Retorna:
    1 si l'estructura es buida, 0 altrament
**********************************************************/
int EsBuida_Cua(Cua c){
    return(c.NumElems==0);
}

/**********************************************************
Cap_Cua
Mètode retorna el primer element (Cap) de l'estructura
Paràmetres:
    C: Cua de la qual es vol obtenir el cap
Retorna:
    Enter amb el valor del cap o un error si estructura
    es buida
**********************************************************/
int Cap_Cua(Cua c){
    int cap;
    if (EsBuida_Cua(c)) {
        missatgeError_Cua(0);
    }else cap=c.info[c.Primer];
    return cap;
}

/**********************************************************
Encuar_Cua
Mètode afegeix un element al final de l'estructura
Paràmetres:
    C: Cua a la qual es vol inserir l'element
Retorna:
    Cua amb l'element emmagatzemat o error si estructura es
    plena
**********************************************************/
Cua Encuar_Cua(Cua c, int elem){
    if (EsPlena_Cua(c)) missatgeError_Cua(1);
    else{
        if(EsBuida_Cua(c)){
          c.info[0]=elem;
          c.Primer=0;
          c.Ultim=0;
          //c.NumElems++;
        }
        else{
            c.Ultim=(c.Ultim+1)%(c.MaxElems);
            c.info[c.Ultim]=elem;
            //c.NumElems++;
        }
        c.NumElems++;

    }
    return c;
}

/**********************************************************
Desencuar_Cua
Mètode que elimina el primer element de l'estructura
Paràmetres:
    C: Cua de la qual es vol esborrar l'element
Retorna:
    Cua amb un nou cap o error si estructura es buida
**********************************************************/
Cua Desencuar_Cua(Cua c){
    if(EsBuida_Cua(c)){
        missatgeError_Cua(0);
    }
    else{
        c.Primer=(c.Primer+1)%(c.MaxElems);
        c.NumElems--;
    }
    return c;
}

/**********************************************************
EsPlena_Cua
Mètode que comprova si l'estructura es plena
Paràmetres:
    C: Cua la qual es vol comprovar
Retorna:
    1 si l'estructura es plena, 0 altrament
**********************************************************/
int EsPlena_Cua(Cua c){
    return(c.NumElems==c.MaxElems);
}

/**********************************************************
Destruir_Cua
Mètode que allibera l'espai reservat per la cua
Paràmetres:
    C: Cua espai del qual es vol alliberar
**********************************************************/
void Destruir_Cua(Cua c){
    free(c.info);
}
