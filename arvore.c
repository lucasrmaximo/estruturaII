#include <stdio.h>
#include <stdlib.h>

typedef struct _no {            // estrutura principal
	int id;
	struct _no *esq;
	struct _no *dir;
	struct _no *pai;
} NO;

=================
===inicializa====
=================

void inicializa(NO **root){             // a função ira setar null no ponteiro auxiliar
	*root = NULL;                   // I am ROOT
	
}

================
====inserir=====
================

void inserir(NO **root, int id){
	NO *novo;			// cria um novo nó
	NO *aux;
	NO *catra;     //variavel original(papai) eh muito gay, mas foi o sergio que colocou
                            
	novo = (NO *) malloc(sizeof(NO));  // reserva o espaço no sistema
	
	novo->id = num;
	novo->pai = NULL;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if(isEmpty(*root))		// verifica se se a arvore está vazia
		*root = novo;		
	
	else {
		aux = *root;                 
		while (aux != NULL) {            //  verificar qual posição vamos setar o novo numero
			catra = aux;
			if (num == aux->id)
				return 0;
			
			if (num < aux->esq)
				aux = aux->esq;
			else
				aux = aux->dir;
		}

		aux->pai = catra;        // variavel papai
		
		if(num < catra->id)
			catra->esq = novo;
		else
			catra->dir = novo;

		return 1;
	}
}

=================
===funcao main===
=================

int main(
	No *arvore;
	int ret;
	
	inicializa(&arvore);
	
	ret = inserir(&arvore, 12);
);