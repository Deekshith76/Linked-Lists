#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

void print(struct node *head);
void reversePrint(struct node *head);
struct node *insert(struct node *head, int);

int main(void){
    struct node *head = NULL; //local
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 8);
    print(head);
    printf("\n");
    reversePrint(head);
    printf("\n");
}

void print(struct node *p){

    if(p == NULL){
        return; // exit condition
    }
    printf("%d ", p->data); // first print the value in node
    print(p->next); //recursive call
}

void reversePrint(struct node *p){
    if(p == NULL){
    return;
    }
    reversePrint(p->next);
    printf("%d ", p->data);
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

/*
For normal traversal of linked list: iterative approach will be efficient
For reversal : both methods are fine
*/

