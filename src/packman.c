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
#include <pthread.h>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>

MAPEANDO m;
LOCALIZA h;
LOCALIZA j;
LOCALIZA F;



int loping = 0;

// Função para verificar entrada do usuário sem bloqueio
int kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

void *animationThread(void *arg) {
    while (!loping) {
        system("clear");
        controlaOsHeroiFantasma(&m, &j, FANTASMA1);
        controlaOsHeroiFantasma(&m, &F, FANTASMA2);
        
        imprimeArquivo(&m);
        usleep(400000);
    }
    return NULL;
}

int main() {
    pthread_t animThread;
    int input;

    // Crie a thread de animação
    pthread_create(&animThread, NULL, animationThread, NULL);

    lendoArquivo("mapa.txt", &m);
    alocacaoDememoriaArquivo(&m);
    scaneiaArquivo(&m);
    
    localizaNoArquivo(&m, &h, HEROI);
    localizaNoArquivo(&m, &j, FANTASMA1);
    localizaNoArquivo(&m, &F, FANTASMA2);

    do {
        // Verifique a entrada do usuário
        if (kbhit()) {
            controlaOsHeroiFantasma(&m, &h, HEROI);
            // Faça algo com a entrada do usuário (input)
            if (input == 'q') {
                loping = 1;  // Encerra a animação
                break;
            }
        }
    } while (1);

    // Aguarde a thread de animação terminar
    pthread_join(animThread, NULL);

    liberaMemoriaArquivo(&m);

    return 0;
}