#include <stdio.h>
#include <stdlib.h>
#include "TADs.h"

#define MAX_ELEMS 10

int main()
{


    /*********************************************************  Joc de proves de la Pila  *********************************************************/
    printf("Joc de proves de la Pila\n");
    printf("Creem Pila amb espai per a %i elements\n", MAX_ELEMS);
    Pila P = Crear_Pila(MAX_ELEMS);                                         //Creem una pila amb espai reservat per a 10 elements
    printf("Intentem desapilar, encara que es buida\n");

    printf("\nEmplenem la pila amb %i elements\n", MAX_ELEMS);              //Emplenem estructura al màxim
    printf("La pila conté els seguents elements: ");
    for (int i=0;i<MAX_ELEMS;i++){
        P = Apilar_Pila(P,i+1);
        printf("%i ",i+1);
    }

    printf("\nEn aquest moment el cim de la nostra pila hauria de ser l'ultim element inserit en aquest cas, un 10. Ho comprovem cridant la funció de cim");

    printf("\nEl cim de la pila és: %i\n", Cim_Pila(P));

    printf("\nLa nostra pila hauria de ser plena i si intentessim apilar un element saltaría error. Ho comprovem intentant apilar un altre element\n");
    P = Apilar_Pila(P, MAX_ELEMS+1);
    printf("Comprovem que el cim de la nostra pila segueix sent el mateix, un 10, cridant la funció de cim");
    printf("\nEl cim de la pila és: %i\n", Cim_Pila(P));

    printf("Desapilem un parell d'elements (10 i 9) i tornem a cridar la funció cim per asegurar-nos que s'han desapilat correctament\n");
    printf("\tDesapilem %i: ", Cim_Pila(P));
    P = Desapilar_Pila(P);
    printf("El cim de la pila és: %i\n", Cim_Pila(P));
    printf("\tDesapilem %i: ", Cim_Pila(P));
    P = Desapilar_Pila(P);
    printf("El cim de la pila és: %i\n", Cim_Pila(P));

    Destruir_Pila(P);                                                         //Un cop finalitzades les proves amb la pila, alliberem l'espai utilitzat

    /*********************************************************  Joc de proves de la Cua  *********************************************************/
    printf("\n\nJoc de proves de la Cua\n");
    printf("Creem Cua amb espai per a %i elements\n", MAX_ELEMS);
    Cua C = Crear_Cua(MAX_ELEMS);                                              //Creem una cua amb espai reservat per a 10 elements
    printf("Intentem desapilar, encara que es buida\n");
    C= Desencuar_Cua(C);

    printf("\nEmplenem la cua amb %i elements\n", MAX_ELEMS);              //Emplenem estructura al màxim
    printf("La Cua conté els seguents elements: ");
    for (int i=0;i<MAX_ELEMS;i++){
        C = Encuar_Cua(C,i+1);
        printf("%i ",i+1);                                                    //Intentem desencuar, encara que es buida -> Printejarà l'error
    }

    printf("\nEn aquest moment el cap de la nostra cua hauria de ser el primer element inserit en aquest cas, un 1. Ho comprovem cridant la funció de cap");

    printf("\nEl cap de la cua és: %i\n", Cap_Cua(C));

    printf("\nLa nostra cua hauria de ser plena i si intentessim encuar un element saltaría error. Ho comprovem intentant encuar un altre element\n");
    C = Encuar_Cua(C, MAX_ELEMS+1);
    printf("Comprovem que el cap de la nostra cua segueix sent el mateix, un 1, cridant la funció de cap");
    printf("\nEl cap de la cua és: %i\n", Cap_Cua(C));

    printf("Desencuem un parell d'elements (1 i 2) i tornem a cridar la funció cap per asegurar-nos que s'han desencuat correctament\n");
    printf("\tDesencuem %i: ", Cap_Cua(C));
    C = Desencuar_Cua(C);
    printf("El cap de la cua és: %i\n", Cap_Cua(C));
    printf("\tDesencuem %i: ", Cap_Cua(C));
    C = Desencuar_Cua(C);
    printf("El cap de la cua és: %i\n", Cap_Cua(C));

    printf("Intentem afegir un nou element per comprovar si la cua circular funciona correctament i s'afegeix el nou element donada la volta:\n");
    C = Encuar_Cua(C,MAX_ELEMS+1);
    printf("Comprovem que el cap no s'ha modificat. El cap de la cua és: %i\n", Cap_Cua(C));
    printf("Printejem el valor que es troba a la ultima posició de la cua, que hauria de ser %i\n",MAX_ELEMS+1);
    printf("L'ultim element de la cua és: %i\n", C.info[C.Ultim]);




    Destruir_Cua(C);                                                         //Un cop finalitzades les proves amb la cua, alliberem l'espai utilitzat

    /*********************************************************  Joc de proves de la Llista  *********************************************************/

    printf("\n\nJoc de proves de la Llista amb PDI amb gestió dinàmica de la memòria\n");
    printf("Creem la llista\n");
    Llista L = Crear_Llista();                                              //Creem una llista
    printf("Intentem esborrar l'element apuntat pel PDI, que deuria ser un null ja que es buida\n");
    L = Esborrar_Llista(L);
    printf("\nAfegim el nostre primer element (un 1) a la llista");
    L = Inserir_Llista(L,1);
    printf("\nAfegim un 2 a la llista. Com el PDI es troba a la dreta del tot, aquest element s'inserirà a la ultima posició (darrere del 1)\n");
    L = Inserir_Llista(L,2);
    Print_Llista(L);
    printf("\nIntentem moure el PDI un lloc a la dreta. Com ja es troba a la dreta del tot, saltara error\n");
    L = Seguent_Llista(L);
    printf("\nMovem el PDI al principi de la llista\n");
    L = Principi_Llista(L);

    printf("\nInserim un 3 a la llista. Com el PDI es troba al principi (apuntant l'element 1), el nou element s'inserirà davant del 1\n");
    L = Inserir_Llista(L,3);
    Print_Llista(L);
    printf("Esborrem l'element referenciat pel PDI: %i\n", Actual_Llista(L));
    L=Esborrar_Llista(L);
    Print_Llista(L);

    printf("\nCreem una segona llista que contindrà els elements 4,5,6\n");
    Llista L2 = Crear_Llista();
    L2 = Inserir_Llista(L2, 4);
    L2 = Inserir_Llista(L2, 5);
    L2 = Inserir_Llista(L2, 6);
    Print_Llista(L2);

    printf("Volem concatenar ambdues llistes, ho fem cridant la funció de Fusionar\n");
    L = Fusiona_Llista(L,L2);
    Print_Llista(L);

    printf("Com les llistes estan construides amb referencies, si alterem alguna de les dues llistes concatenades, la llista unida es veurà afectada també. Esborrem l'element referenciat pel "
           "PDI de la llista 1\n");
    L=Esborrar_Llista(L);
    Print_Llista(L);

    return 0;
}
