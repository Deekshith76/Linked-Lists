#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next; // pointer to another node
};


struct node *reverse(struct node *head);
struct node *insert(struct node *head, int data);
void print(struct node *head);

int main(void){

    struct node *head = NULL;
    head = insert(head, 2);
    head = insert(head, 4);
    head = insert(head, 6);
    head = insert(head, 8);
    print(head);
    head = reverse(head);
    print(head);
}

struct node *reverse(struct node *head){
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL){
        next = current->next; // stores addresss for next node
        current->next = prev; // breaks the link for the next node and points to NULL
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

struct node *insert(struct node *head, int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if (head==NULL){
        head = temp;
    }else{
        struct node *temp1 = head;
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        
        temp1->next = temp;
    }
    return head;
}

void print(struct node *head){
    while(head!=NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
