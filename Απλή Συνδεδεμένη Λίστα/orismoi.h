#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define N 80
#define FALSE 0
#define TRUE 1

struct node{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node *PTR;


void init(PTR *head);
int empty(PTR head);

int insert_start(PTR *head,int k);
int insert_after(PTR p,int k);

int delete_start(PTR *head, int *k);
int delete_after(PTR prev,int *k);

void destroy(PTR *head);
void print(PTR head,FILE *fp);
