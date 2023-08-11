#include <stdio.h>
#include <stdlib.h>
#include "selecionaArquivos.h"
#include "alocacaoDinamicaMemoria.h"
#include "ui.h"

FILE*f;

void lendoArquivo(char *caminho, MAPEANDO* m){
    
    f=fopen(caminho, "r");
    fscanf(f, "%d %d", &m->linhas, &m->colunas);

    if(f == NULL){
        printf("Erro ao abrir aquivo");
        exit(1);
    }
}

void scaneiaArquivo(MAPEANDO* m){
    
    for (int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->matriz[i]);
    }    
}


void imprimeAleatorio(MAPEANDO *m){

    fscanf(f, "%s", m->matriz[1]);
    printf("%s\n", m->matriz[1]);



}

void localizaNoArquivo(MAPEANDO* m, LOCALIZA* h, char caracter){

    for (int y = 0; y < m->linhas; y++ ){
        for (int x = 0; x < m->colunas; x++ ){
            if(m->matriz[y][x] == caracter){
                h->localizaY = y;
                h->localizaX = x;
                printf("localizei na linha[%d] coluna [%d]\n", y, x);
            }
        }
    }
}

