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



int atribuiEscolhaDeMovimento(char entrada, int* y, int* x){
     switch (entrada){
        
        case ESQUERDA:
            (*x)--;

        break;

        case DIREITA:
            (*x)++;

        break;

        case CIMA:
            (*y)--;

        break;

        case BAIXO:
            (*y)++;

        break;
    }
}

