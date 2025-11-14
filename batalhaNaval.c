#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

int main() {
    
    //Tamanhos fixos
    int tamTabuleiro = 10;
    int tamNavio = 3;
    int agua = 0;
    int navio = 3;

    int tabuleiro[10][10]; // Tabuleiro 10x10

    int vertical, horizontal;

    // Coordenadas inicias dos navios
    int linhaH = 2, colunaH = 4; // Horizontal

    int linhaV = 5, colunaV = 7; // Vertical

    // Coordenadas dos navios diagonais
    int linhaD1 = 1, colunaD1 = 1; // diagonal principal
    int linhaD2 = 8, colunaD2 = 2; // diagonal secundária 


    //Criação do tabuleiro 10x10 completo com água
    for (vertical = 0; vertical < tamTabuleiro; vertical++){
        for (horizontal = 0; horizontal < tamTabuleiro; horizontal++){
            tabuleiro[vertical][horizontal] = agua;
        }
    }

    //Posicionamento do navio na horizontal
    if (colunaH + tamNavio <= tamTabuleiro){
        for (horizontal = 0; horizontal < tamNavio; horizontal++ ){
            if (tabuleiro[linhaH][colunaH + horizontal] != agua){
                printf("Sobreposição detectada no navio horizontal!\n");
                return 0;
            }
        }
        for (horizontal = 0; horizontal < tamNavio; horizontal++ ){
            tabuleiro[linhaH][colunaH + horizontal] = navio;
        }
    } else {
        printf ("Navio fora dos limites do tabuleiro!\n");
        return 0;
    }

    //Posicionamento do navio na vertical
    if (linhaV + tamNavio <= tamTabuleiro){
        int sobreposicao = 0;
        for (vertical = 0; vertical < tamNavio; vertical++ ){
            if (tabuleiro[linhaV + vertical][colunaV] == navio) {
                sobreposicao = 1;
                break;
            }
        }
        if (!sobreposicao){
            for (vertical = 0; vertical < tamNavio; vertical++){
                tabuleiro[linhaV + vertical][colunaV] = navio;
            }
        } else {
            printf ("Os navios se sobrepõem!!!\n");
            return 0;
        }
    } else {
        printf("Navio fora dos limites do tabuleiro!\n");
        return 0;
    }

    //Posicionamento do navio na diagonal principal
    int valido = 1;
    if (linhaD1 + tamNavio <= tamTabuleiro &&
        colunaD1 + tamNavio <= tamTabuleiro) {

        for (int i = 0; i < tamNavio; i++) {
            if (tabuleiro[linhaD1 + i][colunaD1 + i] != agua)
                valido = 0;
        }

        if (valido) {
            for (int i = 0; i < tamNavio; i++)
                tabuleiro[linhaD1 + i][colunaD1 + i] = navio;
        } else {
            printf("Sobreposição detectada no navio diagonal 1!\n");
            return 0;
        }

    } else {
        printf("Navio diagonal 1 fora dos limites!\n");
        return 0;
    }

    //Posicionamento do navio na diagonal secundaria
    valido = 1;
    if (linhaD2 - (tamNavio - 1) >= 0 &&
        colunaD2 + tamNavio <= tamTabuleiro) {

        for (int i = 0; i < tamNavio; i++) {
            if (tabuleiro[linhaD2 - i][colunaD2 + i] != agua)
                valido = 0;
        }

        if (valido) {
            for (int i = 0; i < tamNavio; i++)
                tabuleiro[linhaD2 - i][colunaD2 + i] = navio;
        } else {
            printf("Sobreposição detectada no navio diagonal 2!\n");
            return 0;
        }

    } else {
        printf("Navio diagonal 2 fora dos limites!\n");
        return 0;
    }

    //Exibição do tabuleiro
    printf ("\n   *** BATALHA NAVAL *** \n\n");
    printf ("     ");
    //Linha horizontal de A até J
    for (horizontal = 0; horizontal < tamTabuleiro; horizontal++){
        printf ("%c ", 'A' + horizontal);
    }
    printf ("\n");
    printf ("    --------------------\n");

    //Linha vertical de 1 a 10
    for (vertical = 0; vertical < tamTabuleiro; vertical++){
        printf("%2d | ", vertical + 1);
        for (horizontal = 0; horizontal < tamTabuleiro; horizontal++){
            printf ("%d ", tabuleiro[vertical][horizontal]);
        }
        printf ("\n");
    }

    printf ("\nLegenda: Água = 0, Navio = 3\n");
    

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}
