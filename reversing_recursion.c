#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head; //if it is not global the reverse should return the address of modified head
void reverse(struct node *p);

int main(void){

}

void reverse(struct node *p){
    if (p == NULL){
        head = p; // head points to last element
        return;
    }
    reverse(p->next);
    struct node *q = p->next; // if p is pointing (n-1)th element then q will points to nth element in list
    q->next = p; //storing p address in q pointing node
    p->next = NULL;  // instead of writig 2 lines we can write p->next->next = p which is exactly the same 
}
