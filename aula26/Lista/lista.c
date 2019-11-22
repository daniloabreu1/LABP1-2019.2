#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
struct dado{
    int valor;
};

struct elemento{
    DADO d;
    ELEM *prox;
};
struct lista{
    ELEM *inicio;
};
void pegarDado(ELEM *e){
    printf("\nDigite um numero para ser armazenado >> ");
    scanf("%d",&e->d.valor);
}

LISTA* criarLista(){
    LISTA *li = (LISTA*)malloc(sizeof(LISTA));
    if(li!=NULL){
        li->inicio = NULL;
    }
    return li;
}
void liberarLista(LISTA *li){
    if(li!=NULL){
        ELEM *aux;
        while(li->inicio!=NULL){
            aux=li->inicio;
            li->inicio=aux->prox;
            free(aux);
        }
        free(li);
    }
}
int tamanhoLista(LISTA *li){
    int n=0;
    if(li->inicio!=NULL){
        ELEM *aux=li->inicio;
        while(aux!=NULL){
            n++;
            aux=aux->prox;
        }
    }
    return n;
}
void inserir(LISTA *li){
    if(li!=NULL){
        ELEM *e=(ELEM*)malloc(sizeof(ELEM));
        pegarDado(e);
        if(li->inicio==NULL){
            e->prox=NULL;
            li->inicio=e;
        }else{
            ELEM *aux=li->inicio;
            if(aux->d.valor > e->d.valor){
                e->prox=li->inicio;
                li->inicio=e;
            }else{
                ELEM *ant;
                while((aux!=NULL)&&(aux->d.valor < e->d.valor)){
                    ant=aux;
                    aux=aux->prox;
                }
                ant->prox=e;
                e->prox=aux;
            }
        }
    }
}
void remover(LISTA *li, int num){
    if(li->inicio!=NULL){
        if(li->inicio==NULL)
            return;
        ELEM *aux=li->inicio;
        if(aux->d.valor==num){
            li->inicio=aux->prox;
            free(aux);
        }else{
            ELEM *ant;
                while((aux!=NULL)&&(aux->d.valor != num)){
                    ant=aux;
                    aux=aux->prox;
                }
                if(aux==NULL){
                    printf("\nELEMENTO NAO ENCONTRADO\n");
                    return;
                }
                ant->prox = aux->prox;
                free(aux);
        }
    }
}
void imprimirLista(LISTA *li){
    if(li!=NULL){
        ELEM *aux=li->inicio;
        if(aux!=NULL){
            printf("Elementos da Lista\n\n");
            while(aux!=NULL){
                printf("%d\n",aux->d.valor);
                aux=aux->prox;
            }
        }else{
            printf("Lista Vazia\n");
        }

    }
}
