#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Pessoa {
    char Nome[1024];
    int Idade;
    float Altura;
    float Peso;
};

struct Pessoa CriarPessoa();
float calcularIMC(struct Pessoa X);

void main() {
    struct Pessoa Fulano = CriarPessoa();
    printf("\n\n%s:\n %d\n %.2f\n %2.f\n%d\n\n", Fulano.Nome, Fulano.Idade, Fulano.Altura, Fulano.Peso);
    printf("%3.f", calcularIMC(Fulano));
}

struct Pessoa CriarPessoa() {
    struct Pessoa X;
    printf("Digite o nome: ");
    fflush(stdin);
    gets(X.Nome);

    printf("Digite a idade: ");
    fflush(stdin);
    scanf("%d", &X.Idade);

    printf("Digite a altura: ");
    fflush(stdin);
    scanf("%f", &X.Altura);

    printf("Digite o peso: ");
    fflush(stdin);
    scanf("%f", &X.Peso);

    // e necessario retornar o mesmo tipo de variavel para uma funcao
    return(X);
}

float calcularIMC(struct Pessoa X) {
    float IMC = X.Peso / pow(X.Altura, 2);
    return(IMC);
}
