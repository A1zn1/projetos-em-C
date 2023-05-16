#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

float soma = 0;
int quantidade = 0;
char entrada[10];
char saida;

int main(void) {

    do {
        printf("Digite um número:\n[X] para finalizar o programa:\n");
        scanf("%s", entrada);
        entrada[0]=toupper(entrada[0]);
        if (toupper(entrada[0]) == 'X') {
            break;
        }

        float numero = atof(entrada);
        soma += numero;
        quantidade += 1;

    } while (1);
    if(quantidade==0){
            printf("Nenhum número foi inserido!");
    }
    else printf("A soma dos números é %.2f e a média é %.2f\n", soma, soma / quantidade);

    return 0;
}
