#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *arquivo;
    char nomeItem[20];
    int quantidade;
    float preco;
    float subtotal;
    float total;
    int i = 0;

    arquivo = fopen("atv04.txt", "r");

    if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    exit(1);
    }

    while (fscanf(arquivo, "%s %i %f", nomeItem, &quantidade, &preco) != EOF) {
        subtotal = quantidade * preco;
        i++;
        printf("\n%i) %s %i - %.2f\n",i, nomeItem, quantidade, preco);

        total = total + subtotal;
    }

    fclose(arquivo);
    arquivo = fopen("listadecompra.txt", "a"); 

    if(arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "\n\nTotal: R$ %.2f", total);

    printf("\nTotal R$: %.2f", total);

    fclose(arquivo);
    return 0;
}
