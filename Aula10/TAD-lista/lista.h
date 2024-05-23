#ifndef LISTA_H
#define LISTA_H

#define ERRO 1

typedef struct {
    int chave; //podem ser inseridos outros campos
} item;

//definindo a moldura da lista
typedef struct {
    int capacidade;
    int tamanho;
    item *array;
} lista;

lista *criarLista(int capacidade);
void inserirItem(lista *L, item x);

#endif