#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 10
#define TRUE 1
#define FALSE 0

typedef int elem;

struct oura{
	elem pin[N];
	int start;
	int finish;
};

typedef struct oura OURA;

void innit(OURA *q);
int empty(OURA q);
int full(OURA q);
int push(OURA *q,elem k);
int pop(OURA *q,elem *k);

int main(){
	OURA q;
	FILE *fp,*fp2;
	int a,epilogh,i=0,n;
	fp=fopen("oura.txt","w");
	fp2=fopen("num.txt","r");
	innit(&q);
	while(1){
		if(i==1)
			system("pause");
		i=1;
		printf("----MENU----\n");
		printf("1) Eisagwgh stoxeiou\n");
		printf("2) Diagrafh stoixeiou\n");
		printf("3) Ektypwsh\n");
		printf("4) Ektypwsh se arxeio\n");
		printf("5) Eisagwgh apo arxeio\n");
		printf("6) Eksodos\n");
		printf("EPILOGH: ");
		scanf("%d",&epilogh);
		switch(epilogh){
			case(1):
				printf("Dwse stoixeio: ");
				scanf("%d",&a);
				if(push(&q,a))
					printf("Egine eisagwgh tou %d\n",a);
				else
					printf("Prosoxh: !!Gemath stoiva!!\n");
				break;				
			case(2):	
				if(pop(&q,&a))
					printf("Egine diagrafh tou %d\n",a);
				else
					printf("Prosoxh: !!Adeia stoiva!!\n");
				break;
			case(3):
				printf("\n");
				for(i=0;i<=q.finish;i++)
					printf("%do Stoixeio: %d\n",i+1,q.pin[i]);
				printf("\n");
				continue;
			case(4):
				for(i=0;i<=q.finish;i++)
					fprintf(fp,"%do Stoixeio: %d\n",i+1,q.pin[i]);
				continue;
			case(5):
				while(fscanf(fp2,"%d",&n)!=EOF){
					push(&q,n);
					printf("Egine eisagwgh tou arithmou %d apo to arxeio\n",n);
				}
				continue;
			case(6):
				exit(0);
			default:
				printf("Lathos eisodos\n");
		}
	}
return 0;
}


void innit(OURA *q){
	q->finish=-1;
	q->start=-1;
}

int empty(OURA q){
	return q.finish==-1;
}

int full(OURA q){
	return q.start==(q.finish+1)%N;
}

int push(OURA *q,elem k){
	if (full(*q))
		return FALSE;
	if(empty(*q)){
		q->finish=0;
		q->start=0;
	}
	else
		q->finish=(q->finish+1)%N;	
	q->pin[q->finish]=k;
	return TRUE;
}

int pop(OURA *q,elem *k){
	if(empty(*q))
		return FALSE;
	*k=q->pin[q->start];
	if(q->start==q->finish){
		q->start=-1;
		q->finish=-1;	
	}
	else
		q->start=(q->start+1)%N;
	return TRUE;
}
