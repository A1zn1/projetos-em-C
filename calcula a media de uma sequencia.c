// Programa: Cálculo de soma e média
// Descrição: Este programa solicita ao usuário que digite números, realiza a soma desses números e calcula a média.
//              O programa encerra quando o usuário digita 'X' ou 'x'.
    
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float soma = 0;
int quantidade = 0;
char entrada[10];
char saida;

int main(void) {
    // Loop principal do programa
    do {
        printf("Digite um número:\n[X] para finalizar o programa:\n");
        scanf("%s", entrada);
        entrada[0] = toupper(entrada[0]);
        
        // Verifica se o usuário deseja encerrar o programa
        if (toupper(entrada[0]) == 'X') {
            break;
        }

        // Converte a entrada para um número float
        float numero = atof(entrada);
        soma += numero;
        quantidade += 1;

    } while (1);
    
    // Verifica se algum número foi inserido
    if (quantidade == 0) {
        printf("Nenhum número foi inserido!");
    } else {
        // Calcula a média e exibe o resultado
        printf("A soma dos números é %.2f e a média é %.2f\n", soma, soma / quantidade);
    }

    return 0;
}
