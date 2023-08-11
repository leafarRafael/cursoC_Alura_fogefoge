#include <stdio.h>
#include <stdlib.h>
#include "selecionaArquivos.h"
#include "alocacaoDinamicaMemoria.h"
#include "ui.h"

void alocacaoDememoriaArquivo(MAPEANDO* m){
    
    m->matriz = malloc(sizeof(char*) * m->linhas);

    if(m->matriz == NULL){
        printf("Erro na alocação de memoria");
        exit(1);
    }

    for (int i = 0; i < m->linhas; i++){
        m->matriz[i] = malloc(sizeof(char) * (m->colunas+1));
    }
}


void liberaMemoriaArquivo(MAPEANDO* m){
    for (int i = 0; i < m->linhas; i++){
       free(m->matriz[i]);
    }
    free(m->matriz);
}