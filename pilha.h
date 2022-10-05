//
// Created by César de Souza on 03/10/22.
//

#ifndef UNTITLED_PILHA_H
#define UNTITLED_PILHA_H
#define N 50

typedef struct pe{
    int *vetor;
    int topo;
} PE;

typedef struct no{
    int x;
    struct no *prox;
}No;

typedef struct pse{
    No *inicial;
} PSE;

void inicializaPE(PE *pe);
int vaziaPE(PE *pe);
int cheiaPE(PE *pe);
void inserePE(PE *pe, int x);
int retiraPE(PE *pe);

PSE* criar_pilha();
void destruir_pilha(PSE *pse);
void empilhar(PSE *pilha, int x);
No* desempilhar(PSE *pse);

PE *PSE_PE(PSE *pse);



#endif //UNTITLED_PILHA_H
