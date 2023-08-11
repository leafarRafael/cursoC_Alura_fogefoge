#define HEROI '@'
#define FANTASMA1 'F'
#define FANTASMA2 'f'
#define VAZIO '.'
#define PAREDE_VERTICAL '|'
#define PAREDE_HORIZONTAL '-'

struct mapeando {
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapeando MAPEANDO;

struct localiza {
    int localizaY;
    int localizaX;
};
typedef struct localiza LOCALIZA;


void lendoArquivo(char *caminho, MAPEANDO* m);

void scaneiaArquivo(MAPEANDO* m);

void localizaNoArquivo(MAPEANDO* m, LOCALIZA* h, char caracter);

void imprimeAleatorio(MAPEANDO *m);
