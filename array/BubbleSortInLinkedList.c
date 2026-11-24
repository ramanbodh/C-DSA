// Singly Linked List: Bubble Sorting
// Write a C program to sort a singly linked list using the Bubble Sort algorithm.
// (a) Create a singly linked list with at least 5 unsorted numbers (e.g., 40 -> 10 -> 50 -> 20
// -> 30).
// (b) In each pass, compare adjacent nodes and swap their data values if they are out of order.
// (c) Sort the list in ascending order and display the result.
// (d) Sort the list in descending order and display the result

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node* insertion_n(struct node* head,int n,int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    if(n<=0){
        printf("invalide position of the node \n");
        return head;
    }
    else if(n==1 || head==NULL){
        newnode->next=head;
        head=newnode;
        return newnode;
    }
    struct node * temp=head;
    for(int i=1;i<n-1 && temp->next!=NULL;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    return head;
}

struct node * BubbleSortLLS(struct node* head){
    struct node * ptr1;
    struct node *lptr=NULL;
    int swapped;
    do{
        swapped=0;
        ptr1=head;
        while(ptr1->next != lptr){
            if(ptr1->data > ptr1->next->data){
                int temp=ptr1->data;
                ptr1->data=ptr1->next->data;
                ptr1->next->data=temp;
                swapped=1;
            }
            ptr1=ptr1->next;
        }
    lptr=ptr1;
    }while(swapped);
    return head;
}  
void display(struct node* head){
    if(head==NULL){
        printf("NULL\n");
        return;
    }
    printf("%d->",head->data);
    display(head->next);
}

int main(){
    struct node* head=NULL;
    // 40 -> 10 -> 50 -> 20-> 30).
    head=insertion_n(head,1,30);
    head=insertion_n(head,1,20);
    head=insertion_n(head,1,50);
    head=insertion_n(head,1,10);
    head=insertion_n(head,1,40);
    display(head);
    head=BubbleSortLLS(head);
    display(head);
    return 0;
    
    
}