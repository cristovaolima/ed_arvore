#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include <locale.h>

struct tnode * new_tnode(int v);
void tprint(struct tnode *r);
void tinsert(struct tnode **R, struct tnode *n);
struct tnode* search(struct tnode *R, int v);

struct tnode{
	int v;
	struct tnode *l;
	struct tnode *r;
};

int main(int argc, char **argv){
	struct tnode *R = NULL;
	/* //Inserir manual
	R = new_tnode(4);
	R->l = new_tnode(2);
	R->r = new_tnode(6);
	(R->l)->l = new_tnode(1);*/
	tinsert(&R, new_tnode(19));
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

void tprint(struct tnode *r){
	if(r != NULL){
		tprint(r->l);
		printf("%d\n", r->v);
		tprint(r->r);
	}
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


