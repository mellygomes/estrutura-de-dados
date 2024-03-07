#include <stdio.h>
#include <stdlib.h>

char f(int x);

int main() {
    char ch = f(1); // var tipo f conertem para int automaticamente
    printf("\n");
    printf("Resposta: %c", ch);
    printf("\n");

}

char f (int x) {
    if (x == 1) return('C');
    else if (x == 2) return('D');
    else if (x == 3) return('E');
    else if (x == 4) return('B');
    else if (x == 5) return('E');
    else {
        printf("Não não sei oq la");
        exit(0);
    }
}