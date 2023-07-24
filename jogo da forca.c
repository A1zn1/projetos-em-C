#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>

#define TAMANHO_PALAVRAS 20
#define NUM_PALAVRAS 8

int achou = 0;
int tentativas = 0;
char chutes[24];
char palavrasecreta[20];

char palavras[NUM_PALAVRAS][TAMANHO_PALAVRAS]={
    "LARANJA"
    "GIRAFA"
    "AVIAO"
    "COMPUTADOR"
    "MONTANHA"
    "LIVRO"
    "CANETA"
    "BISCOITO"    
};
void escolherpalavra(){
    srand(time(NULL));
    int randomico = rand()%NUM_PALAVRAS;
    strcpy(palavrasecreta, palavras[randomico]);
}

void verificaletra(){   
    for (int i = 0; i < strlen(palavrasecreta); i++){
        achou = 0;
        for (int j = 0; j < tentativas; j++){
            if (chutes[j] == palavrasecreta[i]){
                achou = 1;
                break;
            } 
        }
        if (achou){
            printf("%c", palavrasecreta[i]);
        }
        else{
            printf("_ ");
        }    
    }
}

void chutarletra(){  
    char chute;
    printf("\nChute uma letra!");
    scanf(" %c", &chute);
    chute = toupper(chute);
    chutes[tentativas] = chute;
    tentativas++;   
}

int main(void){
    escolherpalavra(); 
    do {    
        verificaletra();
        chutarletra();   
    } while(1);
    return 0;
}