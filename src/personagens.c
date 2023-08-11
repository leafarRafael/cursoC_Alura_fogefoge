#include <stdio.h>
#include <stdlib.h>
#include "selecionaArquivos.h"
#include "alocacaoDinamicaMemoria.h"
#include "personagens.h"
#include <ctype.h>
#include <time.h>
#include "heroi.h"
#include "interacao.h"
#include "ui.h"


char tratandoEntradaUsuario(){
    char entra;
    scanf(" %c", &entra);
    char entrada = tolower(entra);
    
    return entrada;
}

int ehDirecao(char letra){
     return letra == 'a' ||
            letra == 'd' || 
            letra == 's' || 
            letra == 'w';
    
}

int ehParede(MAPEANDO* m, int y, int x){
   return m->matriz[y][x] != PAREDE_VERTICAL && m->matriz[y][x] != PAREDE_HORIZONTAL;
}
 
int ehFantasma(MAPEANDO*m, int y, int x){
    return m->matriz[y][x] != FANTASMA1 && m->matriz[y][x] != FANTASMA2;
}

int ehVazio(MAPEANDO* m, int y, int x ){
   return m->matriz[y][x] != VAZIO;
}

int ehBomba(MAPEANDO* m, int y, int x ){
    if(m->matriz[y][x] == BOMBA){
        return 1;
    }else if (m->matriz[y][x] != BOMBA){
        return 0;
    }
}

void fazAndar (MAPEANDO* m, LOCALIZA* l, int y, int x, const char personagem){   
    m->matriz[y][x] = personagem;
    m->matriz[l->localizaY][l->localizaX] = VAZIO;
    m->matriz[l->localizaY = y][l->localizaX = x];
    
    
}

int geraRandomico(){
    unsigned int seed = time(NULL);
    int numeroRandomico;

    numeroRandomico = rand_r(&seed) % 4;
    return numeroRandomico;
}

int geraNumeros(){
    unsigned short semente[3];

    semente[0] = time(NULL);
    semente[1] = 983;
    semente[2] = 777;

    int numeroRandomico;

    numeroRandomico = nrand48(semente) % 4 ;

    return numeroRandomico;
}




int posicaoFantasma(MAPEANDO *m, int y, int x){
    return m->matriz[y][x];
}

int posicaoHeroi(MAPEANDO *m, int y, int x){
    return m->matriz[y][x];
    
}
