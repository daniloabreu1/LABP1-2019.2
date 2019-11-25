#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDupla.h"
struct dado{
    char nome[31];
    char telefone[18];
};

struct elemento{
    DADO dados;
    ELEM *ant;
    ELEM *prox;
};
struct lista{
    ELEM *inicio;
};
void pegarDado(ELEM *e){
    printf("DIGITE O NOME DO CONTATO: ");
    setbuf(stdin,NULL);//LIMPA O BUFFER DO TECLADO (COMANDO PARA WINDOWS)
    gets(e->dados.nome);//ADICIONA O CONTEÚDO AO CAMPO NOME
    strupr(e->dados.nome);
    printf("DIGITE O TELEFONE (XX)XXXXX-XXXX: ");
    setbuf(stdin,NULL);
    gets(e->dados.telefone);
}

LISTAD* criarLista(){
    LISTAD *li = (LISTAD*)malloc(sizeof(LISTAD));
    if(li!=NULL){
        li->inicio = NULL;
    }
    return li;
}
void liberarLista(LISTAD *li){
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
int tamanhoLista(LISTAD *li){
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
void inserir(LISTAD *li){
    if(li==NULL){
        printf("\nERRO DE ALOCACAO\n");
    }else{
        ELEM *novo = (ELEM*) malloc(sizeof(ELEM));
        if(novo != NULL){
            pegarDado(novo);
            if(li->inicio==NULL){
                novo->prox=NULL;
                novo->ant=NULL;
                li->inicio=novo;
            }else{//LISTA NAO VAZIA
                if(strcmp(li->inicio->dados.nome,novo->dados.nome)>0){//INSERÇÃO NO INICIO
                    novo->ant=NULL;
                    novo->prox=li->inicio;
                    li->inicio->ant=novo;
                    li->inicio=novo;
                }else{//INSERÇÃO NO MEIO OU FIM
                    ELEM *ante,*aux=li->inicio;
                    while((aux!=NULL)&&(strcmp(aux->dados.nome,novo->dados.nome)<=0)){
                        ante=aux;
                        aux=aux->prox;
                    }
                    ante->prox=novo;
                    novo->ant=ante;
                    novo->prox=aux;
                    if(aux!=NULL)
                        aux->ant=novo;
                }

            }
            printf("\nELEMENTO INSERIDO\n");
        }
        else  //SE MINHA LISTA NAO ESTIVER ALOCADA...
        {
            printf("\nERRO DE ALOCACAO\n");
        }
    }
}
void remover(LISTAD *li, int pos){
    if(li->inicio!=NULL){
        if(li->inicio==NULL)
            return;
        ELEM *aux=li->inicio;
            int cont=1;
            if(cont==pos){
                li->inicio=aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=NULL;
                free(aux);
            }else{
                ELEM *ant;
                while((aux!=NULL)&&(cont != pos)){
                    ant=aux;
                    aux=aux->prox;
                    cont++;
                }
                if(aux==NULL){
                    printf("\nPOSICAO INVALIDA\n");
                    return;
                }
                ant->prox = aux->prox;
                if(aux->prox!=NULL)
                    aux->prox->ant=ant;
                free(aux);
            }
            printf("\nELEMENTO REMOVIDO\n");
    }
}

void imprimirLista(LISTAD *li){
    if(li!=NULL){
        ELEM *aux=li->inicio;
        if(aux!=NULL){
            int cont=0;//VARIAVEL PARA CONTAR OS CONTATOS
            ELEM* aux = li->inicio;//CRIA-SE UM ELEMENTO AUXILIAR PARA PERCORRER A LISTA. RECERÁ O ENDEREÇO DO PRIMEIRO ELEMENTO DA LISTA
            printf("#\tNOME\t\tTELEFONE\n");
            while(aux != NULL){
                cont++;
                printf("%d\t%s\t\t",cont,aux->dados.nome);//APRESENTA O NOME DO CONTATO
                printf("%s\n",aux->dados.telefone);//APRESENTA O NOME DO CONTATo
                aux = aux->prox;//O ELEMENTO AUXILIAR RECEBE O ENDEREÇO DO PRÓXIMO ELEMENTO
            }
        }else{
            printf("Lista Vazia\n");
        }

    }
}
