#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "cidades.h"

int main() {
    const char *nomeArquivo = "teste.txt";
    double menorVizinhanca = calcularMenorVizinhanca(nomeArquivo);
    printf("%d", menorVizinhanca);

    return 0;
}
