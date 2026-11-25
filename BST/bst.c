// Binary Search Tree: Insertion, Traversals, and Deletion
// Write a C program to implement a Binary Search Tree (BST) supporting insertion, traversals,
// and node deletion:
// (a) Insertion: Insert the following numbers one by one into an empty BST:
// [ 50, 30, 70, 20, 40, 60, 80 ]
// (b) Traversals: Write recursive functions to display:
// • In-order traversal (displays the elements in sorted order).
// • Pre-order traversal.
// • Post-order traversal.
// Page 4 of 5
// (c) Deletion: Implement deletion handling all three cases:
// • Case 1: Delete a leaf node (e.g., delete 20).
// • Case 2: Delete a node with one child (e.g., delete 30).
// • Case 3: Delete a node with two children using its in-order successor (e.g., delete 50).
// (d) Print the in-order traversal after each deletion to verify that the tree remains a valid BST

#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* getNode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}

struct node* insertAtN(struct node* root,int data){
    if(root==NULL){
        root=getNode(data);
    }
    else if(root->data>data){
        root->left=insertAtN(root->left,data);
    }
    else{
        root->right=insertAtN(root->right,data);
    }
    return root;
}

void display(struct node* root){
    if(root==NULL){
        return;
    }
    //inorder
    display(root->left);
    printf("%d ",root->data);
    display(root->right);
}

struct node* MinValueN(struct node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct node* deletionNode(struct node* root,int value){
    if(root==NULL){
        printf("nothing to delete ,value not found !\n");
    }
    else if(root->data>value){
        root->left=deletionNode(root->left,value);
    }
    else if(root->data<value){
        root->right=deletionNode(root->right,value);
    }
    //now the if the value if equal to the current node data
    else{
        if(root->left==NULL && root->right==NULL){
            free(root);
            root=NULL;
        }
        else if(root->left==NULL){
            struct node* temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL){
            struct node* temp=root;
            root=root->left;
            free(temp);
        }
        else{
            struct node* temp=MinValueN(root->right);
            root->data=temp->data;
            root->right=deletionNode(root->right,temp->data);
        }
    return root;
    }
    
}

int main(){
    struct node* root=NULL;
    root=insertAtN(root,10);
    root=insertAtN(root,23);
    root=insertAtN(root,3);
    root=insertAtN(root,26);
    root=insertAtN(root,44);
    root=insertAtN(root,1);
    display(root);
    root=deletionNode(root,1);
    printf("\nafter deleting node \n");
    display(root);
    return 0;
}

