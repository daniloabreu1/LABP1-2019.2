#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"
int menu(){
    int op;
    printf("\t\tPILHA DINAMICA\n");
    printf("\n1 - INSERIR ELEMENTOS\n");
    printf("2 - MOSTRAR ELEMENTOS DA PILHA\n");
    printf("3 - REMOVER ELEMENTOS\n");
    printf("4 - SAIR\n");
    printf("\nOPCAO: ");
    scanf("%d",&op);
    putchar('\n');
    return op;
}
main(){
    CONTROL *ctr = criarPilha();
    int o,dado;
    while((o=menu())!=4){
        switch(o){
        case 1:
            system("cls");
            printf("DIGITE UM NOVO NUMERO ");
            scanf("%d",&dado);
            inserirElemento(ctr,dado);//CHAMA A FUNÇÃO QUE INSERE UM ELEMENTO NA PILHA. PARÂMENTROS: ENDEREÇO DA PILHA CRIADA E OS DADOS DE ALUNOS RECEM DIGITADOS
            imprimirPilha(ctr);//CHAMA A FUNÇÃO MOSTRAR. PARÂMETRO: ENDEREÇO DA PILHA CRIADA (ctr É UM PONTEIRO)
            break;
        case 2://OPÇÃO QUE MOSTRA OS ELEMENTOS DA PILHA
            system("cls");
            imprimirPilha(ctr);//CHAMA A FUNÇÃO MOSTRAR. PARÂMETRO: ENDEREÇO DA PILHA CRIADA (ctr É UM PONTEIRO)
            break;
        case 3://OPÇÃO PARA REMOÇÃO DO PRIMEIRO ELEMENTO DA PILHA.
            system("cls");
            removerElemento(ctr);//CHAMA A FUNÇÃO DE REMOÇAO. PARÂMETRO: ENDEREÇO DA PILHA CRIADA
            imprimirPilha(ctr);//CHAMA A FUNÇÃO MOSTRAR. PARÂMETRO: ENDEREÇO DA PILHA CRIADA (ctr É UM PONTEIRO)
            break;
        case 4://OPCAO PARA TERMINAR O LAÇO E SAIR DO PROGRAMA
            break;
        default:
            printf("OPCAO INVALIDA\n\n");
        }
        printf("\n\nPRESSIONE QUALQUER TECLA PARA CONTINUAR...\n\n");
        setbuf(stdin,NULL);
        getchar();
        system("cls");
    }
    liberarPilha(ctr);
}
