#include"lista.h"
#include"funcionarios.h"

struct nodo{
	void* info;
	struct nodo* proximo;
};

struct fila{
	Nodo* diretores;
	Nodo* coordenadores;
	Nodo* funcionarios;
};

Lista* criaFila(){
	Fila* l = (Fila*) malloc(sizeof(Lista));
	l->diretores = NULL;
	l->coordenadores = NULL;
	l->funcionarios = NULL;
	return l;
}

int ramoVazio(Nodo* fila){
	if (fila==NULL){
		return 1;
	}
	return 0;
}

int estaVazia(Fila* fila){
	if (ramoVazio(fila->diretores) && ramoVazio(fila->coordenadores) && ramoVazio(fila->funcionarios)){
		return 1;
	}
	return 0;
}

void desalocaFila(Fila* fila){
	Nodo* no = fila->diretores;
	while (no!=NULL){
		Nodo* aux = no->proximo;
		free(no);
		no = aux;
	}
	Nodo* no = fila->coordenadores;
	while (no!=NULL){
		Nodo* aux = no->proximo;
		free(no);
		no = aux;
	}
	Nodo* no = fila->diretores;
	while (no!=NULL){
		Nodo* aux = no->proximo;
		free(no);
		no = aux;
	}
	printf("Lista desalocada com sucesso!");
}

Funcionario* preenche(int tipo){
	Funcionario* novo = (Funcionario*) malloc(sizeof(Funcionario));
	char nome[50];
	float salario;
	printf("Informe o nome: ");
	scanf("%s", &nome);
	printf("Informe o salario: ");
	scanf("%f", &salario);
	novo->nome = nome;
	novo->salario = salario;
	if (tipo==1){
		strcpy(novo->cargo, "funcionario");
	} else if (tipo==2){
		strcpy(novo->cargo, "coordenador");
	} else if (tipo==3){
		strcpy(novo->cargo, "diretor");
	}
	return novo;	
}

void insere(Fila* fila, int tipo){
	Funcionario* novo = preenche(tipo);
	Nodo* no = (Nodo*) malloc(sizeof(Nodo));
	no->info = novo;
	no->proximo = NULL;
	if (strcmp(novo->cargo, "funcionario")==0){
		if (ramoVazio(fila->funcionarios)){
			fila->funcionarios = no;
		} else{
			Nodo* aux = fila->funcionarios;
			while (aux->proximo!=NULL){
				aux = aux->proximo;
			}
			aux->proximo = no;
		}
	} else if (strcmp(novo->cargo, "coordenador")==0){
		if (ramoVazio(fila->coordenadores)){
			fila->coordenadores = no;
		} else{
			Nodo* aux = fila->coordenadores;
			while (aux->proximo!=NULL){
				aux = aux->proximo;
			}
			aux->proximo = no;
		}
	} else if (strcmp(novo->cargo, "diretor")==0){
		if (ramoVazio(fila->diretores)){
			fila->diretores = no;
		} else{
			Nodo* aux = fila->diretores;
			while (aux->proximo!=NULL){
				aux = aux->proximo;
			}
			aux->proximo = no;
		}
	}
}

Funcionario* desenfileira(Fila* fila){
	if estaVazia(fila){
		return NULL;
	} else{
		if (!ramoVazio(fila->diretores)){
			Nodo* no = fila->diretores;
			fila->diretores = no->proximo;
		} else if (!ramoVazio(fila->coordenadores)){
			Nodo* no = fila->coordenadores;
			fila->coordenadores = no->proximo;
		} else if (!ramoVazio(fila->funcionarios)){
			Nodo* no = fila->funcionarios;
			fila->funcionarios = no->proximo;
		}
		Funcionario* resultado = no->info;
		free(no);
		return resuldado;
	}
}

void imprimeFuncionario(Funcionario* funcionario){
	printf("---------------\n";)
	printf("Nome: %s\n", funcionario->nome);
	printf("Cargo: %s\n", funcionario->cargo);
}

void imprimeRamo(Nodo* fila){
	do {
		Nodo* aux = fila;
		Funcionario* func = aux->info;
		imprime(func);
		aux = aux->proximo;
	} while (aux != NULL);
}

void imprimeFila(Fila* fila){
	if estaVazia(fila){
		printf("A fila esta vazia.");
	} else{
		if (!ramoVazio(fila->diretores)){
			Nodo* aux = fila->diretores;
			imprimeRamo(aux);
		}
		if (!ramoVazio(fila->coordenadores)){
			Nodo* aux = fila->coordenadores;
			imprimeRamo(aux);
		}
		if (!ramoVazio(fila->funcionarios)){
			Nodo* aux = fila->funcionarios;
			imprimeRamo(aux);
		}
	}
}
