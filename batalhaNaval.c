#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.

int main() {
    
    //Tamanhos fixos
    int tamTabuleiro = 10;
    int tamNavio = 3;
    int agua = 0;
    int navio = 4;

    int tabuleiro[10][10]; // Tabuleiro 10x10

    int vertical, horizontal;

    // Coordenadas inicias dos navios
    int linhaH = 2; 
    int colunaH = 4; 
    int linhaV = 5;
    int colunaV = 7;

    //Criação do tabuleiro 10x10 completo com água
    for (vertical = 0; vertical < tamTabuleiro; vertical++){
        for (horizontal = 0; horizontal < tamTabuleiro; horizontal++){
            tabuleiro[vertical][horizontal] = agua;
        }
    }

    //Posicionamento do navio na horizontal
    if (colunaH + tamNavio <= tamTabuleiro){
        for (horizontal = 0; horizontal < tamNavio; horizontal++ ){
            tabuleiro[linhaH][colunaH + horizontal] = navio;
        }
    } else {
        printf ("Navio fora dos limites do tabuleiro!\n");
        return 0;
    }

    //Posicionamento do navio na vertical
    if (linhaV + tamNavio <= tamTabuleiro){
        for (vertical = 0; vertical < tamNavio; vertical++ ){
            tabuleiro[linhaV + vertical][colunaV] = navio;
        }
    } else {
        printf("Navio fora dos limites do tabuleiro!\n");
        return 0;
    }

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

    printf ("\nLegenda: Água = 0, Navio = 4\n");
    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

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
