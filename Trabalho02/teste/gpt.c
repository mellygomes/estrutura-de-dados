#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "cidades.h"

// Função para ler os dados da estrada e das cidades a partir do arquivo
Estrada *getEstrada(const char *nomeArquivo) {
    FILE *Arquivo = fopen(nomeArquivo, "r");
    if (Arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    // Alocar memória para a estrutura Estrada
    Estrada *Y = (Estrada *)malloc(sizeof(Estrada));

    // Ler comprimento da estrada e número de cidades
    fscanf(Arquivo, "%d", &Y->T);
    fscanf(Arquivo, "%d", &Y->N);

    // Verificar restrições
    if ((Y->T <= 3) || (Y->T >= pow(10, 6)) || (Y->N < 2) || (Y->N >= pow(10, 4))) {
        printf("\nERRO: Algo nos valores de entrada nao atende as restricoes\n");
        fclose(Arquivo);
        free(Y);
        exit(1);
    }

    printf("\nComprimento da estrada: %d | Total de cidades: %d\n\n", Y->T, Y->N);

    // Alocar memória para o vetor de cidades
    Y->C = (Cidade *)malloc(Y->N * sizeof(Cidade));

    // Ler posições e nomes das cidades
    for (int i = 0; i < Y->N; i++) {
        fscanf(Arquivo, "%d", &Y->C[i].Posicao);
        fgetc(Arquivo); // Consumir espaço em branco após a posição
        fgets(Y->C[i].Nome, sizeof(Y->C[i].Nome), Arquivo);
        Y->C[i].Nome[strcspn(Y->C[i].Nome, "\n")] = '\0'; // Remover a quebra de linha do nome

        printf("Posicao da cidade: %d | Nome da cidade: %s\n", Y->C[i].Posicao, Y->C[i].Nome);
    }

    fclose(Arquivo);
    return Y;
}

// Função para uso do qsort para comparar posições das cidades
int compararPosicoes(const void *a, const void *b) {
    Cidade *cidadeA = (Cidade *)a;
    Cidade *cidadeB = (Cidade *)b;
    return cidadeA->Posicao - cidadeB->Posicao;
}

// Função para calcular a menor vizinhança
double calcularMenorVizinhanca(const char *nomeArquivo) {
    Estrada *S = getEstrada(nomeArquivo);

    // Ordenar cidades pela posição
    qsort(S->C, S->N, sizeof(Cidade), compararPosicoes);

    // Exibir cidades ordenadas
    printf("\nCidades ordenadas por posição (do menor para o maior):\n");
    for (int i = 0; i < S->N; i++) {
        printf("Posicao da cidade: %d\n", S->C[i].Posicao);
    }

    double menorVizinhanca = S->T;

    // Calcular vizinhança
    for (int i = 0; i < S->N; i++) {
        double inicioVizinhanca, fimVizinhanca;

        // Calcula o ponto médio entre a posição atual e a anterior
        if (i == 0) {
            inicioVizinhanca = 0;
        } else {
            inicioVizinhanca = (S->C[i].Posicao + S->C[i - 1].Posicao) / 2.0;
        }

        // Atualiza o ponto médio para o próximo par de cidades
        if (i == S->N - 1) {
            fimVizinhanca = S->T;
        } else {
            fimVizinhanca = (S->C[i].Posicao + S->C[i + 1].Posicao) / 2.0;
        }

        double vizinhanca = fimVizinhanca - inicioVizinhanca;

        // Atualizar menor vizinhança
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    // Liberar memória
    free(S->C);
    free(S);

    return menorVizinhanca;
}

int main() {
    const char *nomeArquivo = "entrada.txt";
    double menorVizinhanca = calcularMenorVizinhanca(nomeArquivo);
    printf("\nA menor vizinhança é: %lf\n", menorVizinhanca);
    return 0;
}
