#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next; // pointer to another node
};

struct node *head;
void insert(int data); // insert data at end of list
void print();
void delete(int n); //deletes node at pos n

int main(void){
    head = NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5); 
    print(); // List: 2,4,6,5
    int n;
    printf("Enter a positive number: ");
    scanf("%d",&n);
    delete(n);
    print();

}

void delete(int n){
    struct node *temp1 = head;
    
    if(n==1){
        head = temp1->next; //head now points to second node
        free(temp1);
        return;
    }
    int i;
    for(i=0; i<n-2; i++){
        temp1 = temp1->next; //points to (n-1)th node
    }
    
    struct node *temp2 = temp1->next; //nth node
    temp1->next = temp2->next; //(n+1)th node
    free(temp2); //delete temp2
}

void print(){
    struct node *ptr = head;
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void insert(int data){
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    
    if(head==NULL){
        head = temp;
        return;
    }
    struct node *ptr2;
    ptr2 = head;
    while(ptr2->next != NULL){ // Time complexity: O(n)
    // Traversing the list
        ptr2 = ptr2->next;
    }
    
    ptr2->next = temp;
}
