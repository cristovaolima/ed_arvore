#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#define tamanho 100

struct tnode * new_tnode(int v);
void tprint(struct tnode *r);
void tinsert(struct tnode **R, struct tnode *n);
struct tnode* search(struct tnode *R, int v);
void rd(struct tnode * x);
int tamanhoArvore(struct tnode *r);
void preencherArvore(struct tnode **R);

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
	//tinsert(&R, new_tnode(19));
	preencherArvore(&R);
	printf("Numero de nos: %d\n\n", tamanhoArvore(R));
	tprint(R);	
	return 0;
}

struct tnode * new_tnode(int v){
		struct tnode *w = (struct tnode*) malloc(sizeof (struct tnode));
		w->v = v;
		w->l = NULL;
		w->r = NULL;
		return w;
}

void tinsert(struct tnode **R, struct tnode *n){
	if(*R == NULL)
		*R = n;
	else{
		if(n->v < (*R)->v)
			tinsert(&((*R)->l), n);
		else
			tinsert(&((*R)->l), n);
	}
}

struct tnode* search(struct tnode *R, int v){
	if(R != NULL){
		if(R->v == v)
		 return R;
		if(R->v > v)
			return search(R->l, v);
		return search(R->r, v); 
	}
	return NULL;
}

/*void avl(struct tnode *R, int w){
	v = w.p;
	while(v != ){
		
	}
}

void rd(struct tnode * x){
	struct tnode *y = x->e;
	struct tnode *c = y->d;
	x->e = c;
	y->d = x;
	y->p = x->p;
	x-> = y;
	if(c != NULL)
		c->p = x;
	if(y-> != NULL){
		if(y->pv > x->v)
			y->p->c = y;
		else
			y->p->d = y;
	}
}*/

int tamanhoArvore(struct tnode *r){
	if(r != NULL)
		return (tamanhoArvore(r->l) + 1 + tamanhoArvore(r->r));
	return 0; 
}

void tprint(struct tnode *r){
	if(r != NULL){
		tprint(r->l);
		printf("%d ", r->v);
		tprint(r->r);
	}
}

void preencherArvore(struct tnode **R){
	for(int i = 1; i <= tamanho; i++)
		tinsert(R, new_tnode(i));
}
