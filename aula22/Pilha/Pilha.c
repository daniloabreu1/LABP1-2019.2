#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
struct elemento{
    int dado;
    ELEM *prox;
};
struct controlador{
    ELEM *topo;
};
CONTROL*criarPilha(){
    CONTROL *ctr = (CONTROL*)malloc(sizeof(CONTROL));
    if(ctr!=NULL){
        ctr->topo=NULL;
    }
    return ctr;
}
void inserirElemento(CONTROL *ctr,int valor){
    if(ctr!=NULL){
        ELEM *novo = (ELEM*)malloc(sizeof(ELEM));
        if(novo!=NULL){
            novo->dado = valor;
            novo->prox = ctr->topo;
            ctr->topo = novo;
        }
    }
}
void removerElemento(CONTROL *ctr){
    if(ctr!=NULL){
        if(ctr->topo!=NULL){
            ELEM *removido = ctr->topo;
            ctr->topo = ctr->topo->prox;
            free(removido);
        }
    }
}
void liberarPilha(CONTROL *ctr){
    if(ctr!=NULL){
        ELEM *removido;
        while(ctr->topo!=NULL){
            removido = ctr->topo;
            ctr->topo = ctr->topo->prox;
            free(removido);
        }
    free(ctr);
    }
}
void imprimirPilha(CONTROL *ctr){
    if(ctr!=NULL){
        ELEM *elemento = ctr->topo;
        if(elemento!=NULL){
            while(elemento!=NULL){
                printf("\n%d\n",elemento->dado);
                elemento = elemento->prox;
            }
        }else{
            printf("\nPilha Vazia\n");
        }
    }
}
