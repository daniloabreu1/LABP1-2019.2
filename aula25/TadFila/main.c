#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
int menu(){
    int op;
    printf("\t\tFILA DINAMICA\n");
    printf("\n1 - INSERIR ELEMENTOS\n");
    printf("2 - MOSTRAR ELEMENTOS DA FILA\n");
    printf("3 - REMOVER ELEMENTOS\n");
    printf("4 - CONTAR ELEMENTOS\n");
    printf("5 - SAIR\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    putchar('\n');
    return op;
}
main(){
    FILA *fi = criarFila();
    int o;
    while((o=menu())!=5){
        switch(o){
        case 1:
            system("cls");
            inserirElemento(fi);
            mostrarFila(fi);
            break;
        case 2:
            system("cls");
            mostrarFila(fi);
            break;
        case 3:
            system("cls");
            removerElemento(fi);
            mostrarFila(fi);
            break;
        case 4:
            system("cls");
            printf("\n%d ELEMENTOS\n",contarElementos(fi));
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
        printf("\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n\n");
        setbuf(stdin,NULL);
        getchar();
        system("cls");
    }
    liberarFila(fi);
}
