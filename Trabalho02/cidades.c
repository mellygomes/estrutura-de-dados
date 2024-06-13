#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "cidades.h"

Estrada *getEstrada(const char *nomeArquivo) {

    FILE *Arquivo = fopen(nomeArquivo, "r");

    if (Arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    //Chamando a struct e alocando memoria
    Estrada *Y = (Estrada *)malloc(sizeof(Estrada));
    if (Y == NULL) {
        printf("Erro ao alocar memória para Estrada\n");
        fclose(Arquivo);
        return(NULL);
    }

    //ler comprimento da estrada  e numero da e numero de cidades
    fscanf(Arquivo, "%d", &Y->T);
    fscanf(Arquivo,"%d", &Y->N);

    //AS RESTRICOES
    //para T
    if ((Y->T <= 3) || (Y->T >= pow(10, 6))) {
        printf("\nERRO: Algo nos valores de entrada nao atende as restricoes\n");
        return NULL;
        exit(1);
    }
    //para N
    if ((Y->N < 2) || (Y->N >= pow(10, 4))) {
        printf("\nERRO: Algo nos valores de entrada nao atende as restricoes\n");
        return NULL;
        exit(1);
    }

    printf("\nteste 01\n");
    printf("Comprimento da estrada: %i | Total de cidades:  %i\n\n", Y->T, Y->N);

    //alocar memória para o vetor de cidades
    Y->C = (Cidade *)malloc(Y->N * sizeof(Cidade));

    // for (int i = 0; i < Y->N; i++) {
    //     fscanf(Arquivo, "%d", &Y->C[i].Posicao);
    //     fgetc(Arquivo); // Consumir o espaço ou nova linha após o número
    //     fgets(Y->C[i].Nome, sizeof(Y->C[i].Nome), Arquivo);

    //     Y->C[i].Nome[strcspn(Y->C[i].Nome, "\n")] = '\0'; // Remover nova linha

    //     printf("Posicao da cidade: %i | Nome da cidade: %s\n", Y->C[i].Posicao, Y->C[i].Nome);
    // }   

    // for(int i = 0; i < Y->N; i++) {
    //     fscanf(Arquivo, "%d", &Y->C[i].Posicao);
    //     fgets(Y->C[i].Nome, sizeof(Y->C[i].Nome), Arquivo);

    // printf("\nteste 02\n");
    // printf("Posicao da cidade: %d | Nome da cidade:  %s\n", Y->C[i].Posicao, Y->C[i].Nome); 

    // }

    // Lê as posições e os nomes das cidades do arquivo
    for (int i = 0; i < Y->N; i++)
    {
        if (fscanf(Arquivo, "%d ", &Y->C[i].Posicao) != 1)
        {
            // Caso ocorra um erro ao ler a posição da cidade, imprime uma mensagem de erro, fecha o arquivo, libera a memória alocada e retorna NULL
            fprintf(stderr, "Erro ao ler posicao da cidade %d\n", i);
            fclose(Arquivo);
            free(Y->C);
            free(Y);
            return NULL;
        }
        // Lê o nome da cidade (até 256 caracteres) e remove o caractere de nova linha
        fgets(Y->C[i].Nome, 256, Arquivo);
        Y->C[i].Nome[strcspn(Y->C[i].Nome, "\n")] = '\0';

        // Verifica se há cidades com posições duplicadas
        for (int j = 0; j < i; j++)
        {
            if (Y->C[i].Posicao == Y->C[j].Posicao)
            {
                // Caso ocorra uma duplicação de posições, imprime uma mensagem de erro, fecha o arquivo, libera a memória alocada e retorna NULL
                fprintf(stderr, "Erro: posicao da cidade duplicada\n");
                fclose(Arquivo);
                free(Y->C);
                free(Y);
                return NULL;
            }
        }
    }

    // //liberar memoria
    // free(Y->C);
    // free(Y);

    fclose(Arquivo);

    return Y;
}

//funcao para o uso do qsort
int compararPosicoes(const void *a, const void *b) {
    Cidade *cidadeA = (Cidade *)a;
    Cidade *cidadeB = (Cidade *)b;
    return cidadeA->Posicao - cidadeB->Posicao;
}

double calcularMenorVizinhanca(const char *nomeArquivo) {

    // //Chamando a struct e alocando memoria

    Estrada *S = getEstrada(nomeArquivo);

    // Ordenar cidades pela posição
    qsort(S->C, S->N, sizeof(Cidade), compararPosicoes);

    // Exibir cidades ordenadas
    printf("\nCidades ordenadas por posição (do menor para o maior):\n");
    for (int i = 0; i < S->N; i++) {
        printf("Posicao da cidade: %d\n", S->C[i].Posicao);
    }

    double inicioVizinhanca, fimVizinhanca;
    double menorVizinhanca = S->T;

    //calcular vizinhanca usando o ponto médio
    // for(int i = 0; i < S->N - 1; i++) {

    //     if(i == 0) {
    //         inicioVizinhanca = 0;
    //         printf("Deu 0: %d", inicioVizinhanca);
    //     } else {
    //         inicioVizinhanca = S->C[i].Posicao + S->C[i - 1].Posicao / 2.0;
    //     }

    //     if(i == S->N - 1) {
    //         fimVizinhanca = S->T;
    //     } else {
    //         fimVizinhanca = S->C[i].Posicao + S->C[i + 1].Posicao / 2.0;
    //         printf("fim: %d", fimVizinhanca);
    //     }

    //     double vizinhanca = fimVizinhanca - inicioVizinhanca;

    //     //trocar valores
    //     if (vizinhanca < menorVizinhanca) {
    //         menorVizinhanca = vizinhanca;
    //     }
    // }

    // Calcular vizinhança
    for (int i = 0; i < S->N - 1; i++) {
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
            printf("fim: %d", fimVizinhanca);
            fimVizinhanca = (S->C[i].Posicao + S->C[i + 1].Posicao) / 2.0;
        }

        double vizinhanca = fimVizinhanca - inicioVizinhanca;

        // Atualizar menor vizinhança
        if (vizinhanca < menorVizinhanca) {
            menorVizinhanca = vizinhanca;
        }
    }

    //Calcular vizinhança
    // for (int i = 0; i < S->N -1; i++) {

    //     if (i == 0) {
    //         inicioVizinhanca = 0;
    //         printf("Deu 0: %d", inicioVizinhanca);
    //     } else {
    //         inicioVizinhanca = (S->C[i].Posicao + S->C[i - 1].Posicao) / 2.0;
    //         printf("Inicio: %d", inicioVizinhanca);
    //     }

    //     if (i == S->N - 1) {
    //         fimVizinhanca = S->T;
    //         printf("Deu o total: %d", inicioVizinhanca);
    //     } else {
    //         printf("fim: %d", fimVizinhanca);
    //         fimVizinhanca = (S->C[i].Posicao + S->C[i + 1].Posicao) / 2.0;
    //     }

    //     double vizinhanca = fimVizinhanca - inicioVizinhanca;

    //     // Atualizar menor vizinhança
    //     if (vizinhanca < menorVizinhanca) {
    //         menorVizinhanca = vizinhanca;
    //     }
    // }
    
    if (S != NULL) {
        // Processar a estrutura Estrada conforme necessário

        // Liberação de memória
        free(S->C);
        free(S);
    }

    return menorVizinhanca;
}


