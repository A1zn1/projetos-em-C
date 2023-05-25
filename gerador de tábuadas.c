/**************************************************************
 * Programa: Jogo de Adivinhação                               *
 * Descrição: O programa gera um número secreto e o jogador    *
 *            deve tentar adivinhar esse número. A pontuação   *
 *            do jogador é calculada com base no número de     *
 *            tentativas e no nível de dificuldade escolhido.  *
 **************************************************************/

#include <stdio.h>

int main(void) {
    int i, multiplo, numero;

    printf("Qual número desejado?\n");
    scanf("%d", &numero);

    // Solicitação do valor do múltiplo até que um valor positivo seja fornecido
    do {
        printf("Até qual múltiplo você deseja?\n");
        scanf("%d", &multiplo);
        if (multiplo <= 0) {
            printf("O valor do múltiplo deve ser positivo. Tente novamente.\n");
        }
    } while (multiplo <= 0);

    // Cálculo e exibição dos múltiplos
    for (i = 1; i <= multiplo; i++) {
        printf("%dx%d: %d\t", i, numero, numero * i);
        if (i % 10 == 0) {
            printf("\n");
        }
    }

    return 0;
}
