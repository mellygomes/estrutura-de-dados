#include <stdio.h>

int calcularFatorial(int n) {
    int i;
    int fatorial = 1;

    for (i = n; i > 0; i--) {
        fatorial = fatorial * i;
    }

    return fatorial;
}

int main() {
    int n;
    
    printf("Digite um numero inteiro para receber seu fatorial: ");
    fflush(stdin);
    scanf("%i", &n);

    printf("%i", calcularFatorial(n));
    return 0;
} 