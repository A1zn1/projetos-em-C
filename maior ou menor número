// Programa: Encontrar o maior e o menor valor de uma sequência de números
// Descrição: Este programa solicita ao usuário que digite números e armazena o maior e o menor valor encontrados. O usuário pode encerrar a sequência digitando 'x' (maiúsculo ou minúsculo).
 
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>

int big = 0, small = INT_MAX;  // Variáveis para armazenar o maior e o menor valor
char numb[4];  // Array para armazenar a entrada do usuário

int main(void) {
    while (1) {
        printf("Digite números\n[x] para sair\n\a");
        scanf("%3s", &numb[0]);

        if (toupper(numb[0]) == 'X') {
            break;
        }

        int n = atoi(&numb[0]);

        if (n > big) {
            big = n;
        }
        if (n < small) {
            small = n;
        }
    }

    printf("O maior da sequência é %d e o menor valor é %d\n", big, small);

    return 0;
}
