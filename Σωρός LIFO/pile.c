#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 20
#define TRUE 1
#define FALSE 0

typedef int elem;

struct stoiva{
	elem pin[N];
	int top;
};

typedef struct stoiva PILE;

void innit(PILE *p);
int empty(PILE p);
int full(PILE p);
int push(PILE *p,elem k);
int pop(PILE *p,elem *k);

int main(){
	PILE p;
	FILE *fp,*fp2;
	int a,epilogh,i=0,n;
	fp=fopen("pile.txt","w");
	fp2=fopen("num.txt","r");
	innit(&p);
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
				if(push(&p,a))
					printf("Egine eisagwgh tou %d\n",a);
				else
					printf("Prosoxh: !!Gemath stoiva!!\n");
				break;				
			case(2):	
				if(pop(&p,&a))
					printf("Egine diagrafh tou %d\n",a);
				else
					printf("Prosoxh: !!Adeia stoiva!!\n");
				break;
			case(3):
				printf("\n");
				for(i=0;i<=p.top;i++)
					printf("%do Stoixeio: %d\n",i+1,p.pin[i]);
				printf("\n");
				continue;
			case(4):
				for(i=0;i<=p.top;i++)
					fprintf(fp,"%do Stoixeio: %d\n",i+1,p.pin[i]);
				continue;
			case(5):
				while(fscanf(fp2,"%d",&n)!=EOF){
					push(&p,n);
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

void innit(PILE *p){
	p->top=-1;
}

int empty(PILE p){
	return p.top==-1;
}

int full(PILE p){
	return p.top==N-1;
}

int push(PILE *p,elem k){
	if(full(*p))
		return FALSE;
	p->top++;
	p->pin[p->top]=k;
	return TRUE;
}

int pop(PILE *p,elem *k){
	if (empty(*p))
		return FALSE;
	*k=p->pin[p->top];
	p->top--;
	return TRUE;
}

