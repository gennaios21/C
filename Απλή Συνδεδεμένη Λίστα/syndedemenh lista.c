#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "orismoi.c"
#define N 80
#define FALSE 0
#define TRUE 1

int main(){
	PTR head;
	int n,M,i=0;
	FILE *fp;
	fp=fopen("lista.txt","w");
	init(&head);
	insert_start(&head,0);                               //initialize list
	printf("Posa stoixeia thes na eisageis: ");
	scanf("%d",&M);
	while(i<M){
		printf("Dwse arithmo: ");
		scanf("%d",&n);
		insert_after(head,n);
		i++;
	}
	print(head,fp);
	system("pause");
	destroy(&head);
return 0;
}
