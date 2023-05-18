// Programa: Organizar 3 variaveis
// Descrição:Este programa recebe três números do usuário e os ordena em ordem crescente ou decrescente de acordo com a escolha do usuário.

#include <stdio.h>
float numero1, numero2, numero3, temp;
int opcao;

int main(void) {
    // Solicitar ao usuário que escolha a opção de ordenação
    printf("[1] Crescente  [2] Decrescente\n");
    printf("Escolha a opção de ordenação: ");
    scanf("%d", &opcao);

    // Capturar os três números digitados pelo usuário
    printf("Digite o primeiro número: ");
    scanf("%f", &numero1);

    printf("Digite o segundo número: ");
    scanf("%f", &numero2);

    printf("Digite o terceiro número: ");
    scanf("%f", &numero3);

    // Ordenar os números em ordem crescente
    if (numero1 > numero2) {
        temp = numero2;
        numero2 = numero1;
        numero1 = temp;
    }
    if (numero2 > numero3) {
        temp = numero3;
        numero3 = numero2;
        numero2 = temp;
    }
    if (numero1 > numero2) {
        temp = numero2;
        numero2 = numero1;
        numero1 = temp;
    }

    // Exibir os números em ordem crescente ou decrescente, de acordo com a opção escolhida
    if (opcao == 1) {
        printf("Os valores em ordem crescente: %.2f %.2f %.2f\n", numero1, numero2, numero3);
    } else if (opcao == 2) {
        printf("Os valores em ordem decrescente: %.2f %.2f %.2f\n", numero3, numero2, numero1);
    } else {
        printf("Opção inválida.\n");
    }

    return 0;
}
