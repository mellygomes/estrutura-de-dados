#ifndef FRACAO
#define FRACAO

typedef struct {
    int chave;
} item;


typedef struct {
   item *array;
   int tamanho;
   int capacidade; 
} lista;

lista *criarLista(int capacidade) {
    //operaçoes
}

#endif