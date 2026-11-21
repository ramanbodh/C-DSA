// Circular Queue Implementation Using an Array
// Write a C program to implement a Circular Queue using an array of size 5.
// (a) Implement the queue operations using modulo arithmetic:
// • enqueue(value): Add an element at the rear (check for queue overflow).
// • dequeue(): Remove and return the front element (check for queue underflow).
// • display(): Print all active elements in the queue from front to rear.
// (b) In main(), demonstrate:
// • Adding elements until the queue is full
// • Deleting two elements.
// • Adding new elements to demonstrate circular wrap-around and slot reuse.
// • Deleting all remaining elements.
#include<stdio.h>

void enqueue(int a[],int *f,int *r,int value){
    if((*r+1)%5==*f){
        printf("queue overflow \n");
        return;
    }
    else if (*r==*f && *r==-1){
        *f=0;
    }
    *r=(*r+1)%5;
    a[*r]=value;
    return;
}

void dequeue(int a[],int *f,int *r){
    if(*f==*r  ){
        *r=-1;
        *f=-1;
        return;
    }
    else if(*f==-1){
        printf("queue underflow \n");
        return;
    }
    *f=((*f+1)%5);
    return;
}

void display(int a[],int f,int r){
    if(f==-1){
        printf("empty queue\n");
        return;
    }
    int i=f;
    while(i!=r){
        printf("%d ",a[i]);
        i=(i+1)%5;
    }
    printf("%d ",a[r]);
    return;
}

int main(){
    int a[5];
    int face=-1,rear=-1;
    // enqueue(a,&face,&rear,10);
    // display(a,face,rear);
    // printf("face %d , rear %d\n",face,rear);
    // enqueue(a,&face,&rear,30);
    // display(a,face,rear);
    // printf("face %d , rear %d\n",face,rear);
    // enqueue(a,&face,&rear,56);
    // display(a,face,rear);
    // printf("face %d , rear %d\n",face,rear);
    // dequeue(a,&face,&rear);
    // display(a,face,rear);
    // printf("face %d , rear %d\n",face,rear);
    // dequeue(a,&face,&rear);
    // display(a,face,rear);
    // dequeue(a,&face,&rear);
    // display(a,face,rear);
    // dequeue(a,&face,&rear);
    // display(a,face,rear);
    // printf("face %d , rear %d\n",face,rear);
    enqueue(a,&face,&rear,10);
    enqueue(a,&face,&rear,20);
    enqueue(a,&face,&rear,30);
    enqueue(a,&face,&rear,40);
    enqueue(a,&face,&rear,50);
    display(a,face,rear);
    printf("face %d , rear %d\n",face,rear);
    enqueue(a,&face,&rear,55);

    dequeue(a,&face,&rear);
    dequeue(a,&face,&rear);
    printf("face %d , rear %d\n",face,rear);
    enqueue(a,&face,&rear,55);
    display(a,face,rear);
    printf("face %d , rear %d\n",face,rear);

    return 0;
}