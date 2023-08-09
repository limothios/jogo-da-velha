#include <stdio.h>

void imprimir_tabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int vitoria(char tabuleiro[3][3]) {
     int a, b, c;
    for (int i = 0; i < 3; i++) {
        
        if (tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2] && tabuleiro[i][0] != '.') {
            a = (tabuleiro[i][0] == 'x') ? 1 : 2;
            return a;
        }
        if (tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i] && tabuleiro[0][i] != '.') {
            b = (tabuleiro[0][i] == 'x') ? 1 : 2;
            return b;
        }
    }
    if ((tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2] && tabuleiro[1][1] != '.') ||
        (tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0] && tabuleiro[1][1] != '.')) {
        c = (tabuleiro[1][1] == 'x') ? 1 : 2;
        return c;
    }
    return 0;
}

int jogada_invalida(char tabuleiro[3][3], int x, int y) {
    return (x < 0 || x > 2 || y < 0 || y > 2 || tabuleiro[x][y] != '.');
}

int main() {
    char tabuleiro[3][3];
    int turno = 1;
    int acabou = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = '.';
        }
    }

    while (acabou == 0) {
        imprimir_tabuleiro(tabuleiro);

        int vencedor = vitoria(tabuleiro);
        if (vencedor == 1 || vencedor == 2) {
            printf("Jogador %d venceu!\n", vencedor);
            acabou = 1;
            continue;
        }

        int empate = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (tabuleiro[i][j] == '.') {
                    empate = 0;
                    break;
                }
            }
            if (empate == 0) {
                break;
            }
        }
        if (empate == 1) {
            printf("Velha, Empatou!!\n");
            acabou = 1;
            continue;
        }

        printf("Turno do jogador %d [%c]:\n", turno, (turno == 1 ? 'x' : 'o'));

        int x, y;
        scanf("%d %d", &x, &y);

        if (jogada_invalida(tabuleiro, x, y)) {
            printf("Jogada invalida, perdeu a vez.\n");
            turno = 3 - turno; 
        } else {
            tabuleiro[x][y] = (turno == 1 ? 'x' : 'o');
            turno = 3 - turno; 
        }
    }

    return 0;
}
