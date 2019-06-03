#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#define tamanho 100
#define buscando 20

struct tnode * new_tnode(int v);
void exibir(struct tnode *r);
void iserir(struct tnode **R, struct tnode *n);
struct tnode* pesquisa(struct tnode *R, int v);
void rd(struct tnode * x);
int tamanhoArvore(struct tnode *r);
void preencherArvore(struct tnode **R);
int max(int a, int b);
void exibirPesquisa(struct tnode *r);
void exibirTamArvore(struct tnode *r);

struct tnode{
	int v;
	struct tnode *l;
	struct tnode *r;
};

int main(int argc, char **argv){
	setlocale(LC_ALL, "Portuguese");
	struct tnode *R = NULL;
	/* //Inserir manual
	R = new_tnode(4);
	R->l = new_tnode(2);
	R->r = new_tnode(6);
	(R->l)->l = new_tnode(1);*/
	//iserir(&R, new_tnode(19));
	preencherArvore(&R);
	exibirTamArvore(R);
	exibir(R);
	exibirPesquisa(R);	
	return 0;
}

struct tnode * new_tnode(int v){
		struct tnode *w = (struct tnode*) malloc(sizeof (struct tnode));
		w->v = v;
		w->l = NULL;
		w->r = NULL;
		return w;
}

void iserir(struct tnode **R, struct tnode *n){
	if(*R == NULL)
		*R = n;
	else{
		if(n->v < (*R)->v)
			iserir(&((*R)->l), n);
		else
			iserir(&((*R)->l), n);
	}
}

struct tnode* pesquisa(struct tnode *R, int v){
	if(R != NULL){
		if(R->v == v)
		 return R;
		if(R->v < v)
			return pesquisa(R->l, v);
		return pesquisa(R->r, v); 
	}
	return NULL;
}

/*void avl(struct tnode *R, int w){
	v = w.p;
	while(v != NULL){
		v.h = max(h(v.l), h(v.r)) + 1		
	}
}

void rd(struct tnode * x){
	struct tnode *y = x->l;
	struct tnode *c = y->r;
	x->l = c;
	y->r = x;
	y->v = x->v;
	x->v = y->v;
	if(c != NULL)
		c->v = x->v;
	if(y->v != NULL){
		if(y->v->v > x->v)
			y->v->c = y;
		else
			y->v->d = y;
	}
}*/

int tamanhoArvore(struct tnode *r){
	if(r != NULL)
		return (tamanhoArvore(r->l) + 1 + tamanhoArvore(r->r));
	return 0; 
}

void exibir(struct tnode *r){
	if(r != NULL){
		exibir(r->r);
		printf("%d ", r->v);
		exibir(r->l);
	}
}

void preencherArvore(struct tnode **R){
	for(int i = 1; i <= tamanho; i++)
		iserir(R, new_tnode(i));
}

int max(int a, int b){
	if(a > b)
		return a;
	return b;
}

void exibirPesquisa(struct tnode *r){
	if ((pesquisa(r, buscando))!= NULL){
		printf("\n\nValor '%d' encontrado!", buscando);
	}else{
		printf("\n\nValor '%d' NAO encontrado!", buscando);
	}
}

void exibirTamArvore(struct tnode *r){
	printf("Numero de nos: %d\n\n", tamanhoArvore(r));
}
