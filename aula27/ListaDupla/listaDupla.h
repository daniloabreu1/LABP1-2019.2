#ifndef LISTADUPLA_HEADER
#define LISTADUPLA_HEADER
typedef struct dado DADO;
typedef struct elemento ELEM;
typedef struct lista LISTAD;
LISTAD* criarLista();
void pegarDado(ELEM *e);
void liberarLista(LISTAD *li);
int tamanhoLista(LISTAD *li);
void inserir(LISTAD *li);
void remover(LISTAD *li, int pos);
void imprimirLista(LISTAD *li);
#endif // LISTADUPLA_HEADER
