// Codigo para saber se o triângulo existe e saber qual a categoria do triângulo

#include <stdio.h>
float lado1, lado2, lado3;
int main(void) {
    

    // Solicitar ao usuário para inserir cada lado do triângulo
    printf("Insira o comprimento do primeiro lado do triângulo: ");
    scanf("%f", &lado1);

    printf("Insira o comprimento do segundo lado do triângulo: ");
    scanf("%f", &lado2);

    printf("Insira o comprimento do terceiro lado do triângulo: ");
    scanf("%f", &lado3);

    // Verificar se os lados inseridos formam um triângulo
    if (lado1 >= lado2 + lado3 || lado2 >= lado1 + lado3 || lado3 >= lado1 + lado2) {
        printf("Os lados inseridos não formam um triângulo.\n");
    }
    // Verificar se o triângulo é equilátero
    else if (lado1 == lado2 && lado2 == lado3) {
        printf("O triângulo é equilátero.\n");
    }
    // Verificar se o triângulo é isósceles
    else if (lado1 == lado2 || lado2 == lado3 || lado1 == lado3) {
        printf("O triângulo é isósceles.\n");
    }
    // Caso contrário, o triângulo é escaleno
    else {
        printf("O triângulo é escaleno.\n");
    }

    return 0;
}
