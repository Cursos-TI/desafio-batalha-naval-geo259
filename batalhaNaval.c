#include <stdio.h>

int main() {
     int tabuleiro[5][5] = {0};

    // Coordenadas do navio vertical (coluna 1, linhas 1 a 3)
    int x_vert = 1;
    int y_vert = 1;

    for (int i = 0; i < 3; i++) {
        tabuleiro[x_vert + i][y_vert] = 1;
    }

    // Coordenadas do navio horizontal (linha 3, colunas 0 a 2)
    int x_horiz = 3;
    int y_horiz = 0;

    for (int j = 0; j < 3; j++) {
        tabuleiro[x_horiz][y_horiz + j] = 1;
    }

    // Exibir as coordenadas dos navios
    printf("Coordenadas das partes dos navios:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (tabuleiro[i][j] == 1) {
                printf("Navio em: [%d][%d]\n", i, j);
            }
        }
    }

    return 0;
}
#include <stdio.h>

int main() {
    int tabuleiro[10][10] = {0};

    // Navio vertical: coluna 2, linhas 1 a 4
    int x_vert = 1;
    int y_vert = 2;
    for (int i = 0; i < 4; i++) {
        tabuleiro[x_vert + i][y_vert] = 3;
    }

    // Navio horizontal: linha 5, colunas 4 a 7
    int x_horiz = 5;
    int y_horiz = 4;
    for (int j = 0; j < 4; j++) {
        tabuleiro[x_horiz][y_horiz + j] = 3;
    }

    // Navio diagonal descendente ↘ (começa em 0,0)
    int x_diag1 = 0;
    int y_diag1 = 0;
    for (int i = 0; i < 4; i++) {
        tabuleiro[x_diag1 + i][y_diag1 + i] = 3;
    }

    // Navio diagonal ascendente ↗ (começa em 6,3 e sobe)
    int x_diag2 = 6;
    int y_diag2 = 3;
    for (int i = 0; i < 4; i++) {
        tabuleiro[x_diag2 - i][y_diag2 + i] = 3;
    }

    // Exibir o tabuleiro completo
    printf("Tabuleiro 10x10 (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

// Função para exibir matriz
void exibirMatriz(int matriz[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0};

    // Preencher padrão CONE
    for (int i = 0; i < 3; i++) {
        for (int j = 2 - i; j <= 2 + i; j++) {
            cone[i][j] = 1;
        }
    }

    // Preencher padrão CRUZ
    for (int i = 0; i < 5; i++) {
        cruz[2][i] = 1;  // linha central
        cruz[i][2] = 1;  // coluna central
    }

    // Preencher padrão OCTAEDRO
    cone[0][2] = cone[1][1] = cone[1][2] = cone[1][3] = 0; // limpar cone pra mostrar octaedro separado
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int distancia = abs(i - 2) + abs(j - 2);
            if (distancia <= 2) {
                octaedro[i][j] = (distancia == 2 || distancia == 1 || distancia == 0) ? 1 : 0;
            }
        }
    }

    // Exibir os padrões
    printf("\nHabilidade em CONE:\n");
    exibirMatriz(cone);

    printf("\nHabilidade em CRUZ:\n");
    exibirMatriz(cruz);

    printf("\nHabilidade em OCTAEDRO:\n");
    exibirMatriz(octaedro);

    return 0;
}


