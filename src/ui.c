#include <stdio.h>
#include <stdlib.h>
#include "selecionaArquivos.h"
#include "alocacaoDinamicaMemoria.h"
#include "personagens.h"
#include <ctype.h>
#include "fantasma.h"
#include "heroi.h"
#include "interacao.h"
#include "ui.h"

char desenhofantasma[4][7] = {
    {" .-.  " },
    {"| OO| " },
    {"|   | " },
    {"'^^^' " }
};

char desenhofantasma2[4][7] = {
    {" .-.  " },
    {"|OO | " },
    {"|   | " },
    {"'^^^' " }
};

char desenhoparede[4][7] = {
    {"......" },
    {"......" },
    {"......" },
    {"......" }
};

char desenhoheroi[4][7] = {
    {" .--. "  },
    {"/ _.-'"  },
    {"\\  '-." },
    {" '--' "  }
};

char desenhopilula[4][7] = {
    {"      "},
    {" .-.  "},
    {" '-'  "},
    {"      "}
};

char desenhovazio[4][7] = {
    {"      "},
    {"      "},
    {"      "},
    {"      "}
};


void imprimeParte(char desenho[4][7], int parte){
        printf("%s", desenho[parte]);

}

void imprimeArquivo(MAPEANDO* m){
    
    for (int i = 0; i < m->linhas; i++){

        for (int parte = 0; parte < 4; parte++){

            for (int j = 0; j < m->colunas; j++){

                switch (m->matriz[i][j]) {
                case FANTASMA1:
                    imprimeParte(desenhofantasma2, parte);
                    break;


                case FANTASMA2:
                    imprimeParte(desenhofantasma, parte);
                    break;

                case HEROI:
                    imprimeParte(desenhoheroi, parte);
                    break; 

                case PAREDE_HORIZONTAL:
                case PAREDE_VERTICAL:
                    imprimeParte(desenhoparede, parte);
                    break; 

                case VAZIO:
                    imprimeParte(desenhovazio, parte);
                    break; 

                case BOMBA:
                    imprimeParte(desenhopilula, parte);
                    break; 
                
                default:
                    break;
                }          

            }

            printf("\n"); 
        }
    }   
}