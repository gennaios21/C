#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "orismoi.h"
#define N 80
#define FALSE 0
#define TRUE 1

void init(PTR *head){
	*head=NULL;
}

int empty(PTR head){
	return head==NULL;
}

int insert_start(PTR *head,int k){
	PTR newnode;
	newnode=malloc(sizeof(NODE));
	if(newnode==NULL)
		return FALSE;
	newnode->data=k;
	newnode->next=*head;
	*head=newnode;
	return TRUE;
}

int insert_after(PTR p,int k){
	PTR newnode;
	newnode=malloc(sizeof(NODE));
	if(newnode==NULL)
		return FALSE;
	newnode->data=k;
	newnode->next=p->next;
	p->next=newnode;
	return TRUE;
}

int delete_start(PTR *head,int *k){
	PTR current;
	if(empty(*head))
		return FALSE;
	current=*head;
	*k=current->data;
	*head=(*head)->next;
	free(current);
	return TRUE;
}

int delete_after(PTR prev,int *k){
	PTR current;
	if(prev->next==NULL)
		return FALSE;
	current=prev->next;
	*k=current->data;
	prev->next=current->next;
	free(current);
	return TRUE;
}

void destroy(PTR *head){
	PTR ptr;
	while(*head!=NULL){
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

void print(PTR head,FILE *fp){
	PTR current;
	current=head;
	while(current!=NULL){
		printf("%d,",current->data);
		fprintf(fp,"%d,",current->data);
		current=current->next;
	}
	printf("\n");
}
