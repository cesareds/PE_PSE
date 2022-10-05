//
// Created by César de Souza on 04/10/22.
//


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void inicializaPE(PE *pe){
    pe->topo=-1;
}
int vaziaPE(PE *pe){
    if(pe->topo==-1){
        return 1;
    }else{
        return 0;
    }
}
int cheiaPE(PE *pe){
    if(pe->topo==N-1){
        return -1;
    }else{
        return 0;
    }
}
void inserePE(PE *pe, int x){
    if(cheiaPE(pe)){
        printf("ERRO: Pilha cheia");
    }else{
        pe->topo++;
        pe->vetor[pe->topo] = x;
    }
}
int retiraPE(PE *pe){
    int aux;
    if(vaziaPE(pe)==1){
        printf("\nERRO: Pilha vazia\n");
        return 0;
    }else{
        aux=pe->vetor[pe->topo];
        pe->topo--;
        return aux;
    }
}
PE *PSE_PE(PSE *pse){

    PSE *pilha_aux = criar_pilha();
    No *no_aux = pse->inicial;
    int contador = 0;

    while(no_aux){
        No *desempilhado = desempilhar(pse);
        printf("desempilhado\n");
        empilhar(pilha_aux, desempilhado->x);
        printf("empilhado\n");
        free(desempilhado);
        no_aux = no_aux->prox;
        contador++;
    }

    PE *pe = malloc(sizeof (PE));
    inicializaPE(pe);
    pe->vetor = malloc(contador*sizeof (int));

    for(int i = 0; i<contador; i++){
        inserePE(pe, desempilhar(pilha_aux)->x);
    }

    return pe;
}
PSE* criar_pilha(){
    PSE *novo = malloc(sizeof(PSE));
    novo->inicial = NULL;
    return  novo;
}
void destruir_pilha(PSE *pse){
    if (pse->inicial != NULL)
    {
        No *atual = pse->inicial;
        while (atual!=NULL)
        {
           No *aux = atual->prox;
           free(atual);
           atual = aux;
        }
        free(pse);
    }
}
void empilhar(PSE *pilha, int x){

    No *novo = malloc(sizeof(No));
    novo->x=x;

    if(pilha->inicial!=NULL){
        printf("pilha->inicial!=NULL");
        No *aux = pilha->inicial;
        while (aux->prox){
            aux = aux->prox;
        }
        novo->prox=NULL;
        aux->prox=novo;

    } else{
        printf("pilha->inicial==NULL");
        pilha->inicial = novo;
    }
}
No* desempilhar(PSE *pse){

    if(pse->inicial!=NULL){
        printf("\npse->inicial\n");
        No *atual = pse->inicial;
        if(atual->prox){
            printf("atual->prox\n");
            while (atual->prox->prox){
                atual = atual->prox;
                printf("%i\n", atual->x);
            }
            No *aux2 = atual->prox->prox;
            atual->prox->prox = NULL;
            return aux2;
        }else{
            pse->inicial = NULL;
            return atual;
        }
    }else{
        printf("pilha vazia!\n");
        return NULL;
    }
}

