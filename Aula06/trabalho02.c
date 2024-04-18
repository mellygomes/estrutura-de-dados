#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float X;
    float Y;
} Ponto;

float CalcularAreaTriangulo(Ponto A, Ponto B, Ponto C) {
    float AreaTriangulo;
    float Dp1, Dp2, Dp3;
    float Ds1, Ds2, Ds3;
    float DiagonalDireita;
    float DiagonalEsquerda;
    float Det;

    Dp1 = A.X * B.Y * 1;
    Dp2 = A.Y * 1 * C.X;
    Dp3 = 1 * B.X * C.Y;
    DiagonalDireita = Dp1 + Dp2 + Dp3;

    Ds1 = 1 * B.Y * C.X;
    Ds2 = A.X * 1 * C.Y;
    Ds3 = A.Y * B.X * 1;
    DiagonalEsquerda = Ds1 + Ds2 + Ds3;

    Det = DiagonalDireita - DiagonalEsquerda;

    //garantindo valor absoluto para Det
    if (Det < 0) {
        Det = Det * (-1);
    }

    AreaTriangulo = (Det / 2); 

    printf("\nA area do triangulo e: %.2f", AreaTriangulo);

    return AreaTriangulo;
}

int main() {
    Ponto A, B, C;
    float NumeroVertices;
    // vetor de structs
    Ponto Poligono[10];
    FILE *arquivo;
    arquivo = fopen("vertices.txt", "r");

        if (arquivo == NULL) { //testar se a abertura do arquivo foi bem sucedida
            printf("Erro ao abrir o arquivo.\n");
            exit(1);
        }

// criar um vetor de structs em um for (ate n de vertices)
        fscanf(arquivo, "%f\n", &NumeroVertices);
        fscanf(arquivo, "%f %f", &Poligono[i].X, &Poligono[i].Y );
        
        
        
        
        //fscanf(arquivo, "%f %f", &B.X, &B.Y );
        //fscanf(arquivo, "%f %f", &C.X, &C.Y );

        printf("%.2f\n%.2f\t%.2f", NumeroVertices, A.X, A.Y);
        printf("\n%.2f\t%.2f", B.X, B.Y);
        printf("\n%.2f\t%.2f", C.X, C.Y);

        CalcularAreaTriangulo(A, B, C); 

    fclose(arquivo);

    return 0;
}