/**************************************************************
 * Programa: Jogo de Adivinhação                               *
 * Descrição: O programa gera um número secreto e o jogador    *
 *            deve tentar adivinhar esse número. A pontuação   *
 *            do jogador é calculada com base no número de     *
 *            tentativas e no nível de dificuldade escolhido.  *
 **************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char numb[30];
    int numero;
    int cont;
    int numbsecret;
    double pontos = 1000;  // Variável para armazenar a pontuação inicial do jogador
    int nivel;
    int dificuldade;
    int segundos = time(0);
    srand(segundos);
    int random = rand();
    numbsecret = random % 100;  // Gera um número aleatório entre 0 e 99

    printf("Escolha o nível de dificuldade:\n[1] Fácil\n[2] Médio\n[3] Difícil\n");
    scanf("%d", &nivel);

    switch (nivel) {
        case 1:
            dificuldade = 15;  // Define a quantidade de tentativas para o nível fácil
            break;
        case 2:
            dificuldade = 10;  // Define a quantidade de tentativas para o nível médio
            break;
        case 3:
            dificuldade = 5;  // Define a quantidade de tentativas para o nível difícil
            break;
    }

    for (cont = 1; cont <= dificuldade; cont++) {
        printf("Adivinhe o número de 1 a 100:\nDigite [X] para desistir:\n");
        scanf("%s", numb);

        if (numb[0] == 'x' || numb[0] == 'X') {
            break;  // Sai do loop se o jogador digitar 'x' ou 'X'
        }

        printf("Sua %dª tentativa!\n\n", cont);

        numero = atoi(numb);  // Converte a string digitada pelo jogador para um número inteiro

        if (numero > numbsecret) {
            printf("Seu chute foi maior.\n");
            pontos -= 20 * nivel;  // Penaliza a pontuação do jogador por fazer um chute muito alto
        } else if (numero < numbsecret && numero > 0) {
            printf("Seu chute foi menor.\n");
            pontos -= 20 * nivel;  // Penaliza a pontuação do jogador por fazer um chute muito baixo
        } else if (numero < 0) {
            printf("Opção inválida (apenas números positivos).\n");
        } else if (numero == numbsecret) {
            break;  // Sai do loop se o jogador acertar o número
        }
    }

    if (numero == numbsecret) {
        printf("Você acertou o número!\nSua pontuação é %.f\n", pontos);
    } else {
        printf("Você não encontrou o número e finalizou o programa!\nSua pontuação é 0!\n");
    }

    return 0;
}
