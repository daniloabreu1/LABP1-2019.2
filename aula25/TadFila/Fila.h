#ifndef FILA_HEADER
#define FILA_HEADER
static int M=1;
typedef struct aluno ALUNO;
typedef struct elemento ELEM;
typedef struct controlador FILA;
FILA* criarFila();
void inserirElemento(FILA *fila);
void removerElemento(FILA *fila);
void mostrarFila(FILA *fila);
int contarElementos(FILA *fila);
void liberarFila(FILA *fila);
void novoAluno(ELEM *e);
#endif // FILA_HEADER
