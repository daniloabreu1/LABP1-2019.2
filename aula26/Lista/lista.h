#ifndef LISTA_HEADER
#define LISTA_HEADER
typedef struct dado DADO;
typedef struct elemento ELEM;
typedef struct lista LISTA;
LISTA* criarLista();
void pegarDado(ELEM *e);
void liberarLista(LISTA *li);
int tamanhoLista(LISTA *li);
void inserir(LISTA *li);
void remover(LISTA *li, int num);
void imprimirLista(LISTA *li);
#endif // LISTA_HEADER

