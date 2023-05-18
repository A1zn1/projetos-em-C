// Programa: Análise de Dados Pessoais
// Descrição: Este programa solicita ao usuário a idade e o estado civil de várias pessoas e realiza análises estatísticas
//              com base nos dados fornecidos, incluindo a quantidade de pessoas casadas, solteiras, viúvas, a média de idade
//               das pessoas viúvas e a porcentagem de pessoas desquitadas ou separadas em relação ao total de pessoas.
   

#include <stdio.h>
#include <ctype.h>

int idade;
char estadoCivil;
int casados = 0;
int solteiros = 0;
int viuvos = 0;
int somaIdadeViuvos = 0;
int totalPessoas = 0;

int main(void) {
    // Loop principal do programa para capturar os dados das pessoas
    while (1) {
        printf("Digite a idade da pessoa\nNúmero negativo para finalizar\n");
        scanf("%d", &idade);

        if (idade < 0) {
            break;
        }

        printf("Digite o estado civil da pessoa (C-casado, S-solteiro, V-viúvo, D-desquitado ou separado)\n");
        scanf(" %c", &estadoCivil);

        estadoCivil = toupper(estadoCivil);
        totalPessoas++;

        switch (estadoCivil) {
            case 'C':
                casados++;
                break;
            case 'S':
                solteiros++;
                break;
            case 'V':
                viuvos++;
                somaIdadeViuvos += idade;
                break;
            case 'D':
                totalPessoas--;
                break;
            default:
                printf("Estado civil inválido.\n");
                totalPessoas--;
                break;
        }

        printf("\n");
    }

    // Verificar se há pessoas para análise
    if (totalPessoas > 0) {
        // Calcular a média das idades das pessoas viúvas
        float mediaIdadeViuvos = (float) somaIdadeViuvos / viuvos;
        // Calcular a porcentagem de pessoas desquitadas ou separadas em relação ao total de pessoas
        float porcentagemDesquitados = (float) (totalPessoas - casados - solteiros - viuvos) / totalPessoas * 100;

        // Exibir os resultados da análise
        printf("Quantidade de pessoas casadas: %d\n", casados);
        printf("Quantidade de pessoas solteiras: %d\n", solteiros);
        printf("Média das idades das pessoas viúvas: %.2f\n", mediaIdadeViuvos);
        printf("Porcentagem de pessoas desquitadas ou separadas: %.2f%%\n", porcentagemDesquitados);
    } else {
        printf("Nenhuma pessoa analisada.\n");
    }

    return 0;
}
