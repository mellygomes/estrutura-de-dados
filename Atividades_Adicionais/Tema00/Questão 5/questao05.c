#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char arquivo01[5];
    char arquivo02[5];
    char conteudoArquivo01[50];
    char conteudoArquivo02[50];

    // abrir primeiro arquivo
    printf("Informe o nome de um arquivo: ");
    fflush(stdin);
    gets(arquivo01);

    arquivo = fopen(arquivo01, "r");
        if(arquivo == NULL) {
            printf("Nao foi possivel encontrar um arquivo com esse nome!\n");
            exit(1);
        }

        fscanf(arquivo, "%s", conteudoArquivo01);
    fclose(arquivo);

    //abrir segundo arquivo
    printf("Informe o nome de um segundo arquivo: ");
    fflush(stdin);
    gets(arquivo02);

    arquivo = fopen(arquivo02, "r");
        if(arquivo == NULL) {
            printf("Nao foi possivel encontrar um arquivo com esse nome!\n");
            exit(1);
        }

        fscanf(arquivo, "%s", conteudoArquivo02);
    fclose(arquivo);

    //criar terceiro arquivo
    arquivo = fopen("terceiroAquivo.txt", "a");
        if(arquivo == NULL) {
            printf("Erro ao criar novo arquivo!\n");
            exit(1);
        }

        fprintf(arquivo, "%s\n%s", conteudoArquivo01, conteudoArquivo02);
    fclose(arquivo);

    return 0;
}