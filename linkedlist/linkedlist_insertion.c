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
    if(n==1||head==NULL){
        struct Node * newnode=(struct Node*)malloc(sizeof(struct No
        
    }
}