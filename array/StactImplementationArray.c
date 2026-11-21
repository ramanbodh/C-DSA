// Stack Implementation Using an Array
// Write a C program to implement a Stack using a fixed-size array of size 5.
// (a) Implement the following stack operations:
// • push(value): Add an element to the top of the stack (check for stack overflow).
// • pop(): Remove and return the top element (check for stack underflow).
// • peek(): Display the top element without removing it.
// • display(): Print all elements currently in the stack.
// (b) In main(), test your stack by:
// • Pushing elements until the stack is full, then attempting one more push to show overflow.
// • Peeking at the top element.
// • Popping elements until the stack is empty, then attempting one more pop to show
// underflow

#include<stdio.h>

int push(int a[],int value,int stackPtr){
    if(stackPtr>=4 ){
        printf("stact overflow \n");
        return stackPtr;
    }
    stackPtr++;
    a[stackPtr]=value;
    return stackPtr;
}
int pop(int a[],int stackPtr){
    if(stackPtr<0){
        printf("underflow \n");
        return stackPtr;
    }
    return stackPtr-1;
}

 void peek(int a[],int stackPtr){
    if(stackPtr==-1){
        printf("empty stack\n");
        return;
    }
    printf("peek %d\n",a[stackPtr]);
    return;
 }

void display(int a[],int stackPtr){
    for(int i=0;i<=stackPtr;i++){
        printf(" %d ",a[i]);
    }
    printf("\n");
}

int main(){
    int a[5];
    int stackPtr=-1;
    stackPtr=push(a,10,stackPtr);
    display(a,stackPtr);
    stackPtr=push(a,20,stackPtr);
    display(a,stackPtr);
    stackPtr=push(a,33,stackPtr);
    display(a,stackPtr);
    peek(a,stackPtr);
    stackPtr=pop(a,stackPtr);
    display(a,stackPtr);
    return 0;
}