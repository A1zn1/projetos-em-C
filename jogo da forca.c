#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_TENTATIVAS 5
#define NUM_PALAVRAS 100

int achou = 0;
int tentativas = 0;
char chutes[24];
char palavrasecreta[NUM_PALAVRAS];
int letras_acertada[26];
char palavras[NUM_PALAVRAS]; 
char dicas[NUM_PALAVRAS];
char dica[NUM_PALAVRAS];

int contarPalavras(){
    FILE* arquivo = fopen("banco_dados", "r");
    if (arquivo == NULL) {
        printf("Sem Banco de Dados!\n");
        exit(1);
    }

    int totalPalavras = 0;
    while (fscanf(arquivo, "%s %s",&palavras[totalPalavras],&dicas[totalPalavras]) != EOF) {
        totalPalavras++;
    }

    fclose(arquivo);
    return totalPalavras;
}


void escolherpalavra(){
    int totalPalavras = contarPalavras();
    if (totalPalavras == 0) {
        printf("Sem palavras no banco de dados. Adicione palavras antes de jogar.\n");
        exit(1);
    }

    srand(time(NULL));
    int randomico = rand() % totalPalavras;

    FILE* arquivo = fopen("banco_dados", "r");
    if (arquivo == NULL) {
        printf("Sem Banco de Dados!\n");
        exit(1);
    }

    for (int i = 0; i <= randomico; i++) {
        fscanf(arquivo, "%s %s", palavrasecreta, dicas);
    }

    fclose(arquivo);
}

void verificaletra() {
    for (int i = 0; i < strlen(palavrasecreta); i++) {
        if (letras_acertada[palavrasecreta[i] - 'A'] == 1) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

void inicializar_letra_acertada() {
    for (int i = 0; i < 26; i++) {
        letras_acertada[i] = 0;
    }
}

void desenhar_forca() {
    int erros = tentativas;
    printf("  ___       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 5 ? '/' : ' '), (erros >= 5 ? '\\' : ' '));
    printf(" |              \n");
    printf("|__           \n\n");
}

void chutarletra() {
    char chute;
    printf("A dica: %s\n", dicas);
    printf("Chute uma letra: ");
    scanf(" %c", &chute);
    chute = toupper(chute);

    int letra_repetida = 0;
    for (int i = 0; i < tentativas; i++) {
        if (chutes[i] == chute) {
            letra_repetida = 1;
            break;
        }
    }

    if (letra_repetida) {
        printf("\nLetra já chutada! Tente novamente\n\n");
    } else {
        int achou = 0;
        for (int i = 0; i < strlen(palavrasecreta); i++) {
            if (palavrasecreta[i] == chute) {
                letras_acertada[palavrasecreta[i] - 'A'] = 1;
                achou = 1;
            }
        }

        if (achou) {
            printf("\nVocê acertou a letra %c\n\n", chute);
        } else {
            chutes[tentativas] = chute;
            tentativas++;
            printf("\nLetra %c não encontrada na palavra.\n\n", chute);
        }
    }
}

void adicionarpalavra() {
    FILE* arquivo = fopen("banco_dados", "a"); 
    if (arquivo == NULL) {
        printf("Sem Banco de Dados!\n");
        exit(1);
    }
    char palavra[100];
    char dica[100];

    printf("A palavra para ser adicionada: ");
    scanf("%s", palavra);
    
    for (int i = 0; palavra[i]; i++) {
    palavra[i] = toupper(palavra[i]);
}
    printf("Dica da palavra adicionada: ");
    scanf("%s", dica);
    
    for (int i = 0; palavra[i]; i++) {
    dica[i] = toupper(dica[i]);
}
    fprintf(arquivo, "%s %s\n", palavra, dica);
    printf("Palavra adicionada e dica!\n");
    fclose(arquivo);
}

int main(void) {
    int opcao;
    while(opcao!=1){
    printf("-------------------\n");
    printf(":  JOGO DA FORCA  :\n");
    printf("-------------------\n");
    printf("1. Jogar\n");
    printf("2. Adicionar Palavras\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            contarPalavras(); 
            break;
        case 2:
            adicionarpalavra();
            break;
        default:
            printf("Opção inválida!\n");
            return 1;
    }
    }
    do {
        escolherpalavra();
        inicializar_letra_acertada();

        while (1) {
            desenhar_forca();
            verificaletra();
            chutarletra();

            int letras_acertadas = 0;
            for (int i = 0; i < strlen(palavrasecreta); i++) {
                if (letras_acertada[palavrasecreta[i] - 'A'] == 1) {
                    letras_acertadas++;
                }
            }

            if (letras_acertadas == strlen(palavrasecreta)) {
                printf("       _____      \n");
                printf("      '.=====.'     \n");
                printf("      .-\\:      /-.    \n");
                printf("     | (|:.     |) |    \n");
                printf("      '-|:.     |-'     \n");
                printf("        \\::.    /      \n");
                printf("         '::. .'        \n");
                printf("           ) (          \n");
                printf("         .' '.        \n");
                printf("        '-------'       \n\n");
                printf("  Parabéns, você ganhou! ");
                break;
            }

            if (tentativas > MAX_TENTATIVAS) {
                printf("    _____         \n");
                printf("   /               \\       \n");
                printf("  /                 \\      \n");
                printf("//                   \\/\\  \n");
                printf("\\|   XXXX     XXXX   | /   \n");
                printf(" |   XXXX     XXXX   |/     \n");
                printf(" |   XXX       XXX   |      \n");
                printf(" |                   |      \n");
                printf(" \\__      XXX      __/     \n");
                printf("   |\\     XXX     /|       \n");
                printf("   | |           | |        \n");
                printf("   | I I I I I I I |        \n");
                printf("   |  I I I I I I  |        \n");
                printf("   \\_             _/       \n");
                printf("     \\_         _/         \n");
                printf("       \\___/           \n");
                printf("\n     Você perdeu!         \n");
                break;
            }
        }
        char jogar_novamente;
        printf("\nDeseja jogar novamente? (S/N) ");
        scanf(" %c", &jogar_novamente);
        jogar_novamente = toupper(jogar_novamente);
        if (jogar_novamente == 'N') {
            break;
        } else {
            tentativas = 0;
        }
    } while (1);
    return 0;
}