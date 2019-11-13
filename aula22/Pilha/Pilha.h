#ifndef PILHA_HEADER
#define PILHA_HEADER
typedef struct elemento ELEM;
typedef struct controlador CONTROL;
CONTROL*criarPilha();
void inserirElemento(CONTROL *ctr,int valor);
void removerElemento(CONTROL *ctr);
void liberarPilha(CONTROL *ctr);
void imprimirPilha(CONTROL *crl);
#endif // PILHA_HEADER
