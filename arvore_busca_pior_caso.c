#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <conio.h>
#include <string.h>

FILE *grafico;

struct tnode * new_tnode(int v);
void iserir(struct tnode **R, struct tnode *n);
struct tnode* pesquisa(struct tnode *R, int v);
void preencherArvore(struct tnode **R, int n);

struct tnode{
	int v;
	struct tnode *l;
	struct tnode *r;
};

int main(int argc, char **argv){
	struct timeval a, b;
	int t;
	
	//gerar o arquivo de texto com dados 
	grafico = fopen ("graficoarvore_pior_caso.txt", "w");
	for(int n = 1000; n <= 11000; n += 1000){
		struct tnode *R = NULL;
		preencherArvore(&R, n);
		t = 0;
		for (int i = 0; i < 10000; i++){
			gettimeofday(&a, NULL);
			pesquisa(R, n);
			gettimeofday(&b, NULL);
			t+= (b.tv_sec * 1000000 + b.tv_usec) - (a.tv_sec * 1000000 + a.tv_usec);			
		}
		printf("%d %1.2f\n", n,  t/1000000.0);
		fprintf(grafico, "%d %1.2f\n", n, t/1000000.0);
		free(R);
	}
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

void preencherArvore(struct tnode **R, int n){
	for(int i = 1; i <= n; i++)
		iserir(R, new_tnode(i));
}
