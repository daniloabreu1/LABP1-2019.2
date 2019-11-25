#include "listaDupla.h"
#include <stdio.h>
int menu(){
    int op;
    printf("\n0 - SAIR\n");
    printf("1 - MOSTRAR LISTA DE CONTATOS\n");
    printf("2 - TAMANHO DA LISTA\n");
    printf("3 - INSERIR\n");
    printf("4 - REMOVER\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    putchar('\n');
    system("cls");
    return op;
}

main(){
    LISTAD *li = criarLista();
    int o,pos;
    while((o=menu())!=0){
        switch(o){
            case 1:
                system("cls");
                imprimirLista(li);
                break;
            case 2:
                system("cls");
                printf("tamanho da lista: %d\n",tamanhoLista(li));
                break;
            case 3:
                system("cls");
                inserir(li);
                imprimirLista(li);
                break;
            case 4:
                system("cls");
                imprimirLista(li);
                if(tamanhoLista(li)){
                    printf("DIGITE O CODIGO DO CONTATO QUE SERA REMOVIDO >> ");
                    scanf("%d",&pos);
                    remover(li,pos);
                    imprimirLista(li);
                }
                break;
            default:
                printf("OPCAO INVALIDA\n");
        }
        printf("\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n\n");
        setbuf(stdin,NULL);
        getchar();
        system("cls");
    }
    liberarLista(li);
}
