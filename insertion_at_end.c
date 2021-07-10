#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link; // pointer to another node
};

void add_at_end(struct node *head, int data);
struct node *free_links(struct node *head);

struct node *temp, *ptr2; // global variable

int main(void){
    struct node *head = malloc(sizeof(struct node)); //Local variable
    head->data = 77;
    head->link = NULL;
    
    add_at_end(head, 36);
    add_at_end(head, 65);
    
    while(head!=NULL){
        printf("%d\n", head->data);
        head = head->link;
    } 
    
    head = free_links(head);
    if (head==NULL){
        printf("List is empty\n");
    }
    free_links(ptr2);
    temp = free_links(temp);
    free(temp);
}

void add_at_end(struct node *head, int data){
    struct node *ptr2;
    ptr2 = head;
    temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    
    while(ptr2->link != NULL){ // Time complexity: O(n)
    // Traversing the list
        ptr2 = ptr2->link;
    }
    
    ptr2->link = temp;
}

struct node *free_links(struct node *head){
    struct node *ptr = head;
    while(ptr != NULL){
        ptr = ptr->link;
        free(head); // del previous node
        head = ptr; // updating head pointer to the next one
    }
    return head;
}

