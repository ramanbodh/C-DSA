// Singly Linked List: node Deletion at Any Position
// Write a C program to delete a node at any given position from a singly linked list.
// (a) Handle all three deletion cases:
// • Delete from the beginning (first node).
// • Delete from a middle position.
// • Delete from the end (last node).
// (b) Free the memory of the deleted node using free().
// (c) Handle edge cases properly: deleting from an empty list or entering an invalid position.
// (d) Display the linked list before and after each deletion.
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * insertAtN(struct node * head,int n,int value){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if (n<0){
        printf("invalid position\n");
    }
    else if(head==NULL || n==1){
        newnode->next=head;
        return newnode;
    }
    struct node * temp=head;
    for(int i=1;i<n-1||temp->next!=NULL;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node * deletenode(struct node* head,int n){
    struct node * temp=head;
    if(n<0){
        printf("negative  position not valid\n");
    }
    else if(n==1){
        head=temp->next;
        free(temp);
        return head;
    }
    for(int i=1;i<n-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("position out of bound\n");
        return head;
    }
    struct node * temp2=temp->next;
    temp->next=temp->next->next;
    free(temp2);
    return head;
}


void display(struct node* head){
    while(head!=NULL){
        printf(" %d ->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node * head=NULL;
    head=insertAtN(head,2,33);
    head=insertAtN(head,1,43);
    head=insertAtN(head,1,34);
    display(head);
    head=insertAtN(head,1,44);
    display(head);
    head=deletenode(head,4);
    display(head);
    head=deletenode(head,2);
    display(head);
    head=deletenode(head,4);
    display(head);
    return 0;
}

