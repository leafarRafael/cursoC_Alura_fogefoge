#include <stdio.h>
#include <stdlib.h>
#include "selecionaArquivos.h"
#include "alocacaoDinamicaMemoria.h"
#include "personagens.h"
#include <ctype.h>
#include <time.h>
#include "fantasma.h"
#include "heroi.h"
#include "interacao.h"
#include "ui.h"




int escolheRandomico(const char qualPerso){
    int caso;
    
    if (qualPerso == 'F'){
        caso = geraRandomico();
    }else if(qualPerso == 'f'){
        caso = geraNumeros();
    }

    return caso;
}

int movimento(int caso, int *y, int *x){

        switch (caso) {
    case 0:
        (*y)++;
        break;
    case 1:
        (*y)--;
        break;
    case 2:
        (*x)++;
        break;
    case 3:
        (*x)--;
        break;
    
    default:

        break;
    }


}

void evitaTravamento(MAPEANDO* m, LOCALIZA* l, int* y, int* x){
    if(!ehParede(m, *y, *x) || !ehFantasma(m, *y, *x)){
        (*x) = l->localizaX;
        (*y) = l->localizaY;
        (*x)--;

    }
    
     if(!ehParede(m, *y, *x) || !ehFantasma(m, *y, *x)){
        (*x) = l->localizaX;
        (*y) = l->localizaY;
        (*x)++;
        
    }
    
     if(!ehParede(m, *y, *x) || !ehFantasma(m, *y, *x) ){
        (*x) = l->localizaX;
        (*y)= l->localizaY;
        (*y)++;
        
    }
    
     if(!ehParede(m, *y, *x) || !ehFantasma(m, *y, *x)){
        (*x) = l->localizaX;
        (*y) = l->localizaY;
        (*y)--;
       
    }


}

