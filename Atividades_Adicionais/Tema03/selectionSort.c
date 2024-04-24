#include <stdio.h>

void selectionSort(int array[], int QuantidadeElementos) {

    for (int i = 0; i < QuantidadeElementos - 1; i++) {
        int Posicao = i;

        for (int j = i + 1; j < QuantidadeElementos; j++) {
            if (array[j] < array[Posicao]) {
                Posicao = j;
            } 
        }

        int VarTemporaria = array[Posicao];
        array[Posicao] = array[i];
        array[i] = VarTemporaria; 
    }
}

int main() {
    int array[] = {11, 21, 14};
    int QuantidadeElementos = sizeof(array) / sizeof(array[0]);

    selectionSort(array, QuantidadeElementos);

    for (int i = 0; i < QuantidadeElementos; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}