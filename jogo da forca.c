#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define MAX_TENTATIVAS 5
#define TAMANHO_PALAVRAS 20
#define NUM_PALAVRAS 8

int achou = 0;
int tentativas = 0;
char chutes[24];
char palavrasecreta[20];
int letras_acertada[26];
char palavras[NUM_PALAVRAS][TAMANHO_PALAVRAS]={
    "LARANJA",
    "GIRAFA",
    "AVIAO",
    "COMPUTADOR",
    "MONTANHA",
    "LIVRO",
    "CANETA",
    "BISCOITO"    
};

void escolherpalavra(){
    srand(time(NULL));
    int randomico = rand()%NUM_PALAVRAS;
    strcpy(palavrasecreta, palavras[randomico]);
}

void verificaletra(){   
    for (int i = 0; i < strlen(palavrasecreta); i++){
        if (letras_acertada[palavrasecreta[i] - 'A'] == 1){
            printf("%c ", palavrasecreta[i]);
        }
        else{
            printf("_ ");
        }
    }
    printf("\n");
}

void inicializar_letra_acertada(){
    for(int i = 0; i < 26; i++){
        letras_acertada[i] = 0;
    }
}

void desenhar_forca(){
    int erros = tentativas;
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros >= 1 ? '(' : ' '), (erros >= 1 ? '_' : ' '), (erros >= 1 ? ')' : ' '));
    printf(" |      %c%c%c  \n", (erros >= 3 ? '\\' : ' '), (erros >= 2 ? '|' : ' '), (erros >= 4 ? '/' : ' '));
    printf(" |       %c     \n", (erros >= 2 ? '|' : ' '));
    printf(" |      %c %c   \n", (erros >= 5 ? '/' : ' '), (erros >= 5 ? '\\' : ' '));
    printf(" |              \n");
    printf("_|___           \n\n");
}

void chutarletra(){  
    char chute;
    printf("\nChute uma letra!");
    scanf(" %c", &chute);
    chute = toupper(chute);
    
    int letra_repetida = 0;
    for(int i = 0; i < tentativas; i++){
        if(chutes[i]==chute){
            letra_repetida = 1;
            break;
        }
    }
    
    if(letra_repetida){
        printf("\nLetra já chutada! Tente novamente\n\n");
    }
    
    else{
        int achou = 0;
        for (int i = 0; i < strlen(palavrasecreta); i++){
            if (palavrasecreta[i]==chute){
            letras_acertada[palavrasecreta[i] - 'A'] = 1;
            achou = 1;
            }
        }
            
        if(achou){
            printf("\nVocê acertou a letra %c\n\n",chute);
        }
        else{
            chutes[tentativas] = chute;
            tentativas++;   
            printf("\nLetra %c não encontrada na palavra.\n\n", chute);
            }
        }
    }
int main(void){
    
    do{ 
    escolherpalavra(); 
    inicializar_letra_acertada();
       
    while(1){    
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
            printf("       ___________      \n");
		printf("      '._==_==_=_.'     \n");
		printf("      .-\\:      /-.    \n");
		printf("     | (|:.     |) |    \n");
		printf("      '-|:.     |-'     \n");
		printf("        \\::.    /      \n");
		printf("         '::. .'        \n");
		printf("           ) (          \n");
		printf("         _.' '._        \n");
		printf("        '-------'       \n\n");
        printf("  Parabéns você ganhou! ");    
            break;
        }

        if (tentativas > MAX_TENTATIVAS) {
            printf("    _______________         \n");
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
		printf("       \\_______/           \n");
        printf("\n     Você perdeu!         \n");    
            break;
        }
        
    }
        char jogar_novamente;
        printf("\nDeseja jogar novamente? (S/N)");
        scanf(" %c", &jogar_novamente);
        jogar_novamente = toupper(jogar_novamente);
        if(jogar_novamente == 'N'){
            break;
        }
        else{
            tentativas = 0;
        }
        }while(1);
    return 0;
}
