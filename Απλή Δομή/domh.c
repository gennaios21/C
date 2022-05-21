#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 80

struct atomo{
	char *onoma;
	char *dief;
	char *arit;
	char *nomos;
};

typedef struct atomo record;

void read(record *r);
void print(record r,FILE *fp);
void mnhmh(record *r);
void fr(record *r);

int main(){
	int M,i;
	FILE *fp;
	record *a;
	fp=fopen("domh.txt","w");
	printf("Posa atoma thes na eisageis: ");
	scanf("%d",&M);
	a=malloc(sizeof(record)*M);
	if(a==NULL)
		return -2;
	for(i=0;i<M;i++){
		mnhmh(&a[i]);
		printf("---%do atomo---\n",i+1);
		read(&a[i]);
		print(a[i],fp);
		fr(&a[i]);
	}
	fclose(fp);
	
return 0;
}

void read(record *r){
	printf("Dwse onoma: ");
	scanf("%s",r->onoma);
	
	printf("Dwse diefthinsh: ");
	scanf("%s",r->dief);
	
	printf("Dwse arithmo: ");
	scanf("%s",r->arit);
	
	printf("Dwse nomo: ");
	scanf("%s",r->nomos);
}

void print(record r,FILE *fp){
	printf("Onoma: %s \t Diefthinsi: %s %s \t Nomos: %s\n",r.onoma,r.dief,r.arit,r.nomos);
	fprintf(fp,"Onoma: %s \t Diefthinsi: %s %s \t Nomos: %s\n",r.onoma,r.dief,r.arit,r.nomos);
}

void mnhmh(record *r){
	r->onoma=malloc(sizeof(char)*N);
	r->arit=malloc(sizeof(char)*N);
	r->dief=malloc(sizeof(char)*N);
	r->nomos=malloc(sizeof(char)*N);
	if(r->onoma==NULL || r->arit==NULL || r->dief==NULL || r->nomos==NULL)
		exit(0);
}

void fr(record *r){
	free(r->onoma);
	free(r->arit);
	free(r->dief);
	free(r->nomos);
}



