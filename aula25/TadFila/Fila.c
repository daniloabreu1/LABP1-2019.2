#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
struct aluno{
    char nome[31];
    int mat;
    float n1, n2;
};
struct elemento{
    ALUNO dado;
    ELEM *prox;
};

struct controlador{
    ELEM *inicio;
    ELEM *fim;
};

FILA* criarFila(){
    FILA *f = (FILA*)malloc(sizeof(FILA));
    if(f!=NULL){
        f->inicio=NULL;
        f->fim=NULL;
    }
    return f;
}
void novoAluno(ELEM *e){
    printf("Digite o nome do aluno: ");
    setbuf(stdin,NULL);
    gets(e->dado.nome);
    printf("Digite as notas: ");
    scanf("%f %f",&e->dado.n1,&e->dado.n2);
    e->dado.mat=M++;
}
void inserirElemento(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *novoElemento = (ELEM*)malloc(sizeof(ELEM));
        if(novoElemento!=NULL){
            novoAluno(novoElemento);
            novoElemento->prox=NULL;
            if(fila->inicio==NULL){
                fila->inicio=novoElemento;
            }else{
                fila->fim->prox=novoElemento;
            }
            fila->fim=novoElemento;
        }else{
            printf("\nELEMENTO NAO INSERIDO\n");
        }
    }
}
void removerElemento(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
            fila->inicio=fila->inicio->prox;
            free(aux);
            if(fila->inicio==NULL){
                fila->fim=NULL;
            }
        }
    }
}
void mostrarFila(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
           while(aux!=NULL){
                puts(aux->dado.nome);
                printf("mat.: %d\n",aux->dado.mat);
                printf("Notas: %.2f %.2f",aux->dado.n1,aux->dado.n2);
                printf("\n------------------------\n");
                aux=aux->prox;
           }
        }else{
            printf("FILA VAZIA\n");
        }
    }
}
int contarElementos(FILA *fila){
    int cont=0;
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
           while(aux!=NULL){
                cont++;
                aux=aux->prox;
           }
        }
    }
    return cont;
}
void liberarFila(FILA *fila){
    if(fila==NULL){
        printf("\nFILA NAO ALOCADA\n");
    }else{
        ELEM *aux=fila->inicio;
        if(fila->inicio!=NULL){
           while(aux!=NULL){
                fila->inicio=aux->prox;
                free(aux);
                aux=fila->inicio;
           }
           free(fila);
        }
    }
}

