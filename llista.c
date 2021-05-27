#include <stdio.h>
#include <stdlib.h>
#include "llista.h"

/**********************************************************
Crear_Llista
Constructor del tipus Llista. Crea una estructura de dades
de tipus Llista i inicialitza les seves variables.
Retorna: Estructura de tipus Llista buida
**********************************************************/
Llista Crear_Llista(){
    Llista L;
    Node* P;
    P = malloc(sizeof(Node));  //Reservem espai per un node, que ocupara 8B (4B de l'element i 4B del punter)
    if (P==NULL){               //Si el punter es un NULL, no hi haurà espai disponible per crear la llista
        printf("No hi ha espai suficient per crear la llista");
    }else{
        L.primer=P;
        L.anterior=P;
        P->encadenament=NULL;
    }

    return L;
}

/**********************************************************
EsFinal_Llista
Mètode que comprova si el PDI es troba al final de la llista
Paràmetres:
    L: Llista de la qual es vol comprovar el PDI
Retorna:
    1 si PDI a la dreta del tot, 0 altrament
**********************************************************/
int EsFinal_Llista(Llista L){
    return(L.anterior->encadenament==NULL);
}

/**********************************************************
Actual_Llista
Mètode que retorna l'element de la llista que està sent
apuntat per el PDI
Paràmetres:
    L: Llista de la qual es vol obtenir l'element del PDI
Retorna:
    Enter amb el valor al qual apunta al PDI o error si el
    PDI es troba a la dreta del tot i no apunta a res
**********************************************************/
int Actual_Llista(Llista L){
    Node* PDI;
    if(EsFinal_Llista(L)) printf("Error. PDI a la dreta");
    else PDI=L.anterior->encadenament;
    return (PDI->info);
}

/**********************************************************
Seguent_Llista
Mètode que mou el PDI un element cap a la dreta
Paràmetres:
    L: Llista de la qual es vol moure el PDI
Retorna:
    Llista amb el PDI mogut o Error si el PDI es troba ja a
    la dreta del tot
**********************************************************/
Llista Seguent_Llista(Llista L){
    if (EsFinal_Llista(L))printf("No es pot fer avançar el PDI. PDI a la dreta");
    else   L.anterior=L.anterior->encadenament;

    return L;
}

/**********************************************************
Principi_Llista
Mètode que mou el PDI al començament de la llista
Paràmetres:
    L: Llista de la qual es vol moure el PDI
Retorna:
    Llista amb el PDI mogut
**********************************************************/
Llista Principi_Llista(Llista L){
    L.anterior=L.primer;
    return L;
}

/**********************************************************
Inserir_Llista
Mètode que s'encarrega d'inserir un element davant del PDI
sense moure'l.
Paràmetres:
    L: Llista de la qual es vol moure el PDI
    E: Enter que es vol inserir
Retorna:
    Llista amb el nou element emmagatzemat o error si no hi
    ha espai per crear el nou Node.
**********************************************************/
Llista Inserir_Llista(Llista L, int E){
    Node *P,*PDI;
    P = malloc(sizeof(Node));                           //Reservem espai per un node, que ocupara 8B (4B de l'element i 4B del punter)
    if (P==NULL){                                       //Si el punter es un NULL, no hi haurà espai disponible per crear el nou node
        printf("No hi ha espai suficient per inserir l'element");
    }else{
        P->info=E;
        PDI=L.anterior->encadenament;
        L.anterior->encadenament=P;
        P->encadenament=PDI;
        L.anterior=P;
    }
    return L;
}

/**********************************************************
EsBuida_Llista
Mètode que comprova si la llista es buida
Paràmetres:
    L: Llista la qual es vol comprovar
Retorna:
    1 si es buida, 0 altrament
**********************************************************/
int EsBuida_Llista(Llista L){
    return (L.primer->encadenament==NULL);
}

/**********************************************************
Esborrar_Llista
Mètode que esborra l'element de la llista que està sent
referenciat per el PDI. El nou PDI de la llista serà el
seguent element.
Paràmetres:
    L: Llista de la qual es vol esborrar un element
Retorna:
    Llista amb el element escindit i amb un nou PDI. Error
    si el PDI es troba a la dreta del tot.
**********************************************************/
Llista Esborrar_Llista(Llista L){
    Node *PDI;
    if(EsFinal_Llista(L)){
        printf("No es pot eliminar. PDI a la dreta");
    }else{
        PDI=L.anterior->encadenament;
        L.anterior->encadenament=PDI->encadenament;
        free(PDI);
    }
    return L;
}


/**********************************************************
Print_Llista
Mètode que imprimeix per pantalla la llista
Paràmetres:
    L: Llista la qual es vol imprimir
**********************************************************/
void Print_Llista(Llista L){
    Node* P=L.primer->encadenament;
    if (P==NULL) printf("Llista buida");
    else{
        Node* P=L.primer->encadenament;
        while (P!=NULL){
            printf("%i",P->info);
            P=P->encadenament;
            if (P!=NULL) printf(" -> ");
            else printf("\n");
        }
    }
}

/**********************************************************
Fusiona_Llista
Mètode que fusiona dos llistes en una sola, enllaçant la
segona llista amb la primera.
Paràmetres:
    L1: Llista a la qual es vol concatenar una altra llista
    L2: Llista que es vol afegir
Retorna:
    Llista amb els elements de les dues llistes. El seu PDI
    coincidirà amb la L1.
**********************************************************/
Llista Fusiona_Llista(Llista L1, Llista L2){
    Node* P=L1.primer;
    while (P->encadenament!=NULL){
        P=P->encadenament;
    }
    P->encadenament=L2.primer->encadenament;
    return L1;
}
