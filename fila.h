#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct fila Fila;

typedef struct nodo Nodo;

Lista* criaFila();

int estaVazia(Lista* lista);

void desalocaLista(Lista* lista);

void insere(Lista* lista);

