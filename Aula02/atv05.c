/*

Variaveis compostas
- homogênias
- Heterogênia
 
 Um vetor é uma variavel composta homogênia e unidirecional
 EX de array de interos :
 int numeros [5] = {1,2,3,4,5};

Ex de array de caracteres (string)
char nome[10] = "Exemplo";
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int tamString(char *str) {  //Maneira correta de passar string com parametro, como ponteiro. "Passagem de parametro por referencia"
    int tamanho;
    for (tamanho = 0; str[tamanho] =! '\0'; tamanho++);
    return(tamanho);
}

int main() {
    char nome[10] = "Exemplo";
    int tamanho1 = strlen(nome);
    printf("Tamanha da str: %d caracteres", tamanho1);
    int tamanho2 = tamString(nome);
    printf("Tamanha da str: %d caracteres", tamanho2);
    // o 8° caractere é o \0
}