#define ESQUERDA 'a'
#define DIREITA 'd'
#define BAIXO 's'
#define CIMA 'w'
#define BOMBA 'B'


char tratandoEntradaUsuario();

int ehDirecao(char letra);

int ehParede(MAPEANDO* m, int y, int x);

int ehVazio(MAPEANDO* m, int y, int x);

int ehBomba(MAPEANDO* m, int y, int x );

void fazAndar (MAPEANDO* m, LOCALIZA* h, int y, int x, const char personagem);

int geraRandomico();

int geraNumeros();

int ehFantasma(MAPEANDO*m, int y, int x);



int posicaoFantasma(MAPEANDO *m, int y, int x);

int posicaoHeroi(MAPEANDO *m, int y, int x);