/*
    Calculadora de Raízes Quadráticas
    
    Este programa calcula as raízes de uma equação quadrática da forma ax^2 + bx + c = 0,
    onde o usuário insere os valores de a, b e c. O programa verifica o valor do discriminante
    (delta) e imprime as raízes correspondentes. Se delta for negativo, as raízes serão complexas
    e, caso contrário, serão reais.
*/

#include <stdio.h>
#include <math.h>
#include <complex.h>

void printHeader() {
    printf("===================================\n");
    printf("     Calculadora de Raízes         \n");
    printf("        Quadráticas                \n");
    printf("===================================\n\n");
}

int main(void) {
    float a, b, c;
    float delta;
    
    printHeader();
    
    printf("Coloque o valor de A:\n");
    scanf("%f", &a);

    printf("Coloque o valor de B:\n");
    scanf("%f", &b);

    printf("Coloque o valor de C:\n");
    scanf("%f", &c);

    delta = (b * b) - (4 * a * c);
    
    if (delta < 0) {
        // Delta é negativo, raízes complexas
        float complex raiz1 = (-b + csqrtf(delta)) / (2 * a);
        float complex raiz2 = (-b - csqrtf(delta)) / (2 * a);
        
        printf("\nAs raízes são %.2f + %.2fi e %.2f - %.2fi\n",
               crealf(raiz1), cimagf(raiz1), crealf(raiz2), cimagf(raiz2));
    }
    else {
        // Delta é maior ou igual a zero, raízes reais
        float raiz1 = (-b + sqrt(delta)) / (2 * a);
        float raiz2 = (-b - sqrt(delta)) / (2 * a);
    
        printf("\nAs raízes são %.2f e %.2f\n", raiz1, raiz2); 
    }
    
    return 0;
}