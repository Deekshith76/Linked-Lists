#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next; // pointer to another node
};

struct node *head; //global variable

void insert(int data, int pos);
void print();

int main(void){
    head = NULL; // empty list
    insert(2,1); // List: 2
    insert(3,2); // List: 2,3
    insert(4,1); // List: 4,2,3
    insert(5,2); // List: 4,5,2,3
    print();
   
}

void insert(int data, int pos){
    struct node *temp1 = malloc(sizeof(struct node)); // C++ usage of malloc
    temp1->data = data;
    temp1->next = NULL;
    
    if(pos == 1){
        temp1->next = head; //assigns to NULL
        head = temp1; //stores address of temp1 in head pointer
        return;
    }
     struct node *temp2 = head;
     for(int i=0; i<pos-2; i++){
        temp2 = temp2->next; //traversing to node n-1
     }
     
     temp1->next = temp2->next;
     temp2->next = temp1;

}

void print(){
    struct node *temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
