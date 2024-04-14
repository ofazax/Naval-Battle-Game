#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define TAMANHO_TABULEIRO 5

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

int linhaNavio, colunaNavio;

void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '~';
        }
    }
}

void exibirTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

void posicionarNavio() {
    linhaNavio = rand() % TAMANHO_TABULEIRO;
    colunaNavio = rand() % TAMANHO_TABULEIRO;
    tabuleiro[linhaNavio][colunaNavio] = 'N';
}

int main() {
    setlocale(LC_ALL, "portuguese");

    srand(time(NULL));
    int palpiteLinha, palpiteColuna;
    int turno;

    inicializarTabuleiro();
    posicionarNavio();

    printf("Bem-vindo ao Jogo de Batalha Naval!\n");
    printf("Escolha uma linha e uma coluna de 0 a 4 para atacar.\n");

    for (turno = 0; turno < 4; turno++) {
        printf("Turno %d\n", turno + 1);
        printf("Adivinhe a linha: ");
        scanf("%d", &palpiteLinha);
        printf("Adivinhe a coluna: ");
        scanf("%d", &palpiteColuna);

        if (palpiteLinha < 0 || palpiteLinha >= TAMANHO_TABULEIRO || palpiteColuna < 0 || palpiteColuna >= TAMANHO_TABULEIRO) {
            printf("Palpite fora do tabuleiro! Tente novamente.\n");
        } else if (tabuleiro[palpiteLinha][palpiteColuna] == 'X') {
            printf("Você já tentou esta posição. Tente novamente.\n");
        } else if (tabuleiro[palpiteLinha][palpiteColuna] == 'N') {
            printf("Parabéns! Você afundou o navio!\n");
            tabuleiro[palpiteLinha][palpiteColuna] = 'X';
            tabuleiro[linhaNavio][colunaNavio] = 'N';
            exibirTabuleiro();
            break;
        } else {
            printf("Você errou!\n");
            tabuleiro[palpiteLinha][palpiteColuna] = 'X';
        }
    }

    if (turno == 4) {
        printf("Fim do jogo! O navio estava na linha %d e coluna %d.\n", linhaNavio, colunaNavio);
        tabuleiro[linhaNavio][colunaNavio] = 'N';
        exibirTabuleiro();
    }

    return 0;
}
