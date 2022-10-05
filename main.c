//
// Created by César de Souza on 03/10/22.
//

#include <stdio.h>
#include <math.h>
#include "pilha.h"

int main() {

    PSE *pse = criar_pilha();
    empilhar(pse, 1);
    empilhar(pse, 2);
    empilhar(pse, 3);
    empilhar(pse, 4);

    PE *pe = PSE_PE(pse);
    for(int i = 0; i<N; i++){
        printf("\nFOR DA MAIN %i\n", pe->vetor[i]);
    }
    return 0;
}

//PSE *i = pse->inicial; i != NULL; i = i->proximo