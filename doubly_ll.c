#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
    };
    
// Usage of doubly lists: Reverse Look Up
// 12 bits 

void insertAtHead(int );
struct node *getNewNode(int x);
void print();
void reversePrint();
void insertAtTail(int x);

struct node *head; // global variable : pointer to head node

int main(void){
    head = NULL;
    insertAtHead(2); print(); reversePrint();
    insertAtTail(3); print(); reversePrint();
    insertAtHead(4); print(); reversePrint();
    insertAtTail(5); print(); reversePrint();
    insertAtHead(6); print(); reversePrint();
    insertAtTail(7); print(); reversePrint();  
}

struct node *getNewNode(int x){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int x){
    struct node *newNode = getNewNode(x);
    if (head == NULL){
        head = newNode;
        return;
    }
    head->prev = newNode; 
    newNode->next = head;
    head = newNode; // head ->  newNode -> prev newNode
}

void insertAtTail(int x){
    struct node *newNode = getNewNode(x);
    if(head == NULL){
        head = newNode;
        return;
    }
    struct node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    
}

void print(){
    struct node *temp = head;
    printf("Forward: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reversePrint(){
    struct node *temp = head;
    if (temp == NULL) return; // empty list, exit
    
    // Going to last node
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    // Traversing back using prev pointer
    printf("Reverse: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}
