#include <stdio.h>
#include <stdlib.h>


/* estrutura do noh da arvore -------------------------- */
typedef struct _no {
    int id;
    struct _no *esq;
    struct _no *dir;
    struct _no *pai;	
} NO;


/* funcao que inicializa a arvore ---------------------- */
void inicializa(NO **root) {
	*root = NULL;	
}


/* funcao que verifica se a arvore esta vazia ---------- */
int estaVazia (NO *root) {
    if (root == NULL)
        return 1;
    else
        return 0;
}


/* funcao que insere um noh na arvore ------------------ */
int inserir(NO **root, int num) {
	NO *novo;
	NO *aux;
	NO *papai;
	
	novo = (NO *) malloc(sizeof(NO));
	
	novo->id = num;
	novo->pai = NULL;
	novo->esq = NULL;
	novo->dir = NULL;
	
	if (estaVazia(*root))
		*root = novo;
	
    else {
		aux = *root;
		while (aux != NULL) {
			papai = aux;

            if(num == aux->id)
				return 0;       /* nao insere noh duplicado */
			
            if(num < aux->id)
				aux = aux->esq;
			else
				aux = aux->dir;			
		}
		
		novo->pai = papai;
		
		if(num < papai->id)
			papai->esq = novo;
		else
			papai->dir = novo;
		
	}	
    
    return 1;  /* inseriu com sucesso */
}


/* funcao de busca em pre-ordem ------------------------ */
void preOrdem (NO *root) {
    if (root != NULL) {
       printf("%d  ", root->id);
       preOrdem(root->esq);
       preOrdem(root->dir);
    }
}


/* funcao de busca em pos-ordem ------------------------ */
void posOrdem (NO *root) {
    if (root != NULL) {
       posOrdem(root->esq);
       posOrdem(root->dir);
       printf("%d  ", root->id);
    }
}


/* funcao de busca em ordem ---------------------------- */
void emOrdem (NO *root) {
    if (root != NULL) {
       emOrdem(root->esq);
       printf("%d  ", root->id);
       emOrdem(root->dir);
    }
}


/* ===================================================== */
/* FUNCAO MAIN                                                     */
/* ===================================================== */
int main() {
    NO *arvore;
	
	inicializa(&arvore);
    
	if (!inserir(&arvore, 12)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 15)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 21)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 14)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 1)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 13)) printf("Valor duplicado\n");
	if (!inserir(&arvore, -5)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 0)) printf("Valor duplicado\n");
	if (!inserir(&arvore, 1)) printf("Valor duplicado\n");

    preOrdem(arvore); printf("\n");
    posOrdem(arvore); printf("\n");
    emOrdem(arvore); printf("\n");

    return 0;
}