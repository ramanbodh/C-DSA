// Singly Linked List: Node Insertion at Any Position
// Write a C program to insert a node at any given position (1-indexed) in a singly linked list.
// (a) Handle all three insertion cases:
// • Insert at the beginning (position 1).
// • Insert at a middle position.
// • Insert at the end (after the last node).
// (b) If the user enters an invalid position (less than 1 or greater than list length + 1), display an
// error message.
// (c) Display the linked list before and after each insertion

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};


struct Node * insertion_n(struct Node * head,int n,int data){
    struct Node * newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=NULL;
    if(n==1||head==NULL){
        newnode->next=head;
        return newnode;
    }
    struct Node * temp=head;
    for(int i=1;i<n-1;i++){
        if(temp->next==NULL){//or we can directly add the in the above for loop with && temp->next!=NULL
            break;
        }
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}
void display(struct Node* head){
    while(head!=NULL){
        printf(" %d ->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node * head=NULL;
    head=insertion_n(head,2,33);
    head=insertion_n(head,1,43);
    head=insertion_n(head,1,34);
    display(head);
    head=insertion_n(head,1,44);
    display(head);
    return 0;
}

