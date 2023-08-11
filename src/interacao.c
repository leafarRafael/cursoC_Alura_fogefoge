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


int temBomba;

int comeuF1;
int comeuF2;
int comeu;

int acabaJogo;

int xH;
int yH;
int xF;
int yF;
int yf;
int xf;

void comeFantasma(MAPEANDO *m, int y, int x){
   
    if(posicaoHeroi(m, yH, xH) == posicaoFantasma(m, yF, xF)) {
        
        if(comeuF1 >=1){
            return;
        }else{
            comeuF1++;
            comeu++;
            temBomba--;
            printf("Comeu o fantasma [%c]\n", m->matriz[yF][xF]);
            m->matriz[yF][xF] = VAZIO;
        }
    }else if(posicaoHeroi(m, yH, xH) == posicaoFantasma(m, yf, xf)) {

        if(comeuF2 >= 1){
            return;
        }else{
            comeuF2++;
            comeu++;
            temBomba--;
            printf("Comeu o fantasma [%c]\n", m->matriz[yf][xf]);
            m->matriz[yf][xf] = VAZIO;
        }
    }

}

void movimentoFantasmaMAIUSCULO(MAPEANDO* m, LOCALIZA* l, const char qualPerso){
    int caso = escolheRandomico(qualPerso);

    if(comeuF1 >=1)return;
    yF = l->localizaY;
    xF = l->localizaX;
    
    if (temBomba >= 1){

    } else{
        if(posicaoFantasma(m, yF, xF) == posicaoHeroi(m, yH, xH)){

            fazAndar(m, l, yF, xF, qualPerso);
            imprimeArquivo(m);

            printf("\n\n\nVoce PERDEU!!!\n\n\n");
            printf("\n\n\n\nO fantasma matou o heroi\n\n\n");

            exit(1);
        }
    }  

    movimento(caso, &yF, &xF);
    evitaTravamento(m, l, &yF, &xF);

    if(ehBomba(m, yF, xF)) return;
    fazAndar(m, l, yF, xF, qualPerso);


}

void movimentoFantasma(MAPEANDO* m, LOCALIZA* l, const char qualPerso){
    int caso = escolheRandomico(qualPerso);
    if(comeuF2 >=1)return;
    yf = l->localizaY;
    xf = l->localizaX;    
    
    if (temBomba >= 1){
    }else{
    if(posicaoFantasma(m, yf, xf) == posicaoHeroi(m, yH, xH)){

        fazAndar(m, l, yf, xf, qualPerso);
        imprimeArquivo(m);

        printf("\n\n\nVoce PERDEU!!!\n\n\n");
        printf("\n\n\n\nO fantasma matou o heroi\n\n\n");

        exit(1);
    }
    }
 
    
    movimento(caso, &yf, &xf);   
    evitaTravamento(m, l, &yf, &xf);

    if(ehBomba(m, yf, xf)) return;
    fazAndar(m, l, yf, xf, qualPerso);

}

void movimentaPersonagem(MAPEANDO* m, LOCALIZA* h, const char qualPerso){    
    char entrada = tratandoEntradaUsuario();

    if(!ehDirecao(entrada)) return;

    xH = h->localizaX;
    yH = h->localizaY;



    
    atribuiEscolhaDeMovimento(entrada, &yH, &xH);


    if (ehBomba(m, yH, xH)){
        temBomba++;
    }

    printf("Quantidade de Bombas [%d]\n", temBomba);

    

    if (temBomba >= 1){
        comeFantasma(m, yH, xH);
    }
        if(!ehParede(m, yH, xH))return;
        fazAndar(m, h, yH, xH, HEROI);

}

void controlaOsHeroiFantasma(MAPEANDO* m, LOCALIZA* l, const char qualPerso){


    if(qualPerso == FANTASMA1){
        if (comeuF1 >= 1 && temBomba >= 1) return;
        movimentoFantasmaMAIUSCULO(m, l, FANTASMA1);
        
    
    
    
    }else if(qualPerso == FANTASMA2){
        if (comeuF2 >=1 && temBomba >= 1) return;
        movimentoFantasma(m, l, FANTASMA2);

    
    
    
    
    }else if (qualPerso == HEROI){
        movimentaPersonagem(m, l, HEROI);     
    }


    if(comeu >= 2){
        imprimeArquivo(m);

        printf("\n\n\nVoce GANHOU!!!\n\n\n");
        printf("\n\n\n\nO HEROI DERROTOU os FANTASMAS\n\n\n");

        exit(1);
    }


    
}