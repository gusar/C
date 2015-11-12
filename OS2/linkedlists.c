#include <stdio.h>

struct node{
	int data;
	struct node *next;
} LLIST;

main(){

}

void list_remove(LLIST **p){
	if(p != NULL && *p != NULL){
		LLIST *n = *p;
		*p = (*p) -> next;
		free(n);
	}
}
