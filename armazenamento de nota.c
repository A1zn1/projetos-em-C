/*************************************************************
 *  Programa: Cálculo de Médias dos Alunos
 *  Descrição: Este programa permite calcular as médias dos
 *             alunos em um determinado número de bimestres.
 *             As notas são inseridas pelo usuário e, em seguida,
 *             são calculadas as médias individuais de cada aluno.
 *************************************************************/

#include <stdio.h>
#define bimestre 4
#define notas 4

float alunos[notas][bimestre] = {0};
float soma[notas] = {0};
float media = 0;
int cont = 1;

int main(void) {
    printf("=== Cálculo de Médias dos Alunos ===\n\n");

    printf("Insira as 4 notas do Aluno 1\n");
    
    // Loop para coletar as notas dos alunos
    for (int nota = 0; nota < notas; nota++) {
        // Inicializa a variável 'media' para o cálculo da média
        float media = 0;

        // Loop para coletar as notas de cada bimestre do aluno atual
        for (int bimestral = 0; bimestral < bimestre; bimestral++) {
            printf("A nota do Aluno %d no %d° Bimestre: ", bimestral + 1, nota + 1);
            scanf("%f", &alunos[nota][bimestral]);

            // Soma as notas para o cálculo da média
            media += alunos[nota][bimestral];
        }

        // Calcula a média das notas do aluno e armazena em 'soma'
        soma[nota] += media / bimestre;

        // Reinicia a variável 'media' para o próximo aluno
        media = 0;

        cont++;

        // Verifica se todas as notas dos alunos foram coletadas
        if (cont == 5) {
            break;
        }

        printf("Insira as 4 notas do Aluno %d\n", cont);
    }

    printf("\n");
    printf("As médias são:\n");
    
    // Exibe as médias dos alunos
    for (int nota = 0; nota < notas; nota++) {
        printf("A média do Aluno %d é %.2f\n", nota + 1, soma[nota]);
    }

    return 0;
}