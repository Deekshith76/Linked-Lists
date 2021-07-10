#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head; //if it is not global the reverse should return the address of modified head
void reverse(struct node *p);
struct node *insert(struct node *head, int);
void print(struct node *p);

int main(void){
    head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 8);
    print(head);
    printf("\n");
    reverse(head);
    print(head);
    printf("\n");
    
}

void reverse(struct node *p){
    if (p->next == NULL){
        head = p; // head points to last element
        return;
    }
    reverse(p->next);
    struct node *q = p->next; // if p is pointing (n-1)th element then q will points to nth element in list
    q->next = p; //storing p address in q pointing node
    p->next = NULL;  // instead of writig 2 lines we can write p->next->next = p which is exactly the same 
}

struct node *insert(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    if (head == NULL){
        head = temp;
    }else{
        struct node *ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
    return head;
}

void print(struct node *p){

    if(p == NULL){
        return; // exit condition
    }
    printf("%d ", p->data); // first print the value in node
    print(p->next); //recursive call
}
