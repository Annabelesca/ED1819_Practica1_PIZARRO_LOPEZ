#ifndef LLISTA_H_INCLUDED
#define LLISTA_H_INCLUDED

typedef struct Node Node;

struct Node //Mida Node= mida(element)+mida(punter)=8B
{
    int info;
    Node* encadenament;
};

typedef struct  //Mida Lista=8+[mida(element)+4]*NumElems
{
    Node *primer, *anterior;
    //Node* anterior;

}Llista;

extern Llista Crear_Llista();

extern Llista Inserir_Llista(Llista L, int E);

extern Llista Esborrar_Llista(Llista L);

extern int Actual_Llista(Llista L);

extern int EsBuida_Llista(Llista L);

extern Llista Principi_Llista(Llista L);

extern Llista Seguent_Llista(Llista L);

extern int EsFinal_Llista(Llista L);

extern Llista Fusiona_Llista(Llista L1, Llista L2);

extern void Print_Llista(Llista L);

#endif
