#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario Funcionario;

typedef struct fila Fila;

typedef struct nodo Nodo;

Fila* criaFila();

Funcionario* preenche(int tipo);

void imprimeFuncionario(Funcionario* funcionario);

int ramoVazio(Nodo* fila)

int estaVazia(Fila* fila);

void desalocaFila(Fila* fila);

void insere(Fila* fila, int tipo);

Nodo* desenfileira(Fila* fila);

void imprimeRamo(Nodo* fila);

void imprimeFila(Fila* fila);

