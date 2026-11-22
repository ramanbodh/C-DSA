// Write a C program to implement and compare Selection Sort and Insertion Sort on an array of
// integers.
// (a) Write functions for:
// • Selection Sort: In each pass, find the smallest element from the unsorted part and
// swap it into place.
// • Insertion Sort: In each pass, pick the next element and insert it into its correct
// position among the sorted elements.
// (b) Test both algorithms on the array:
// [ 25, 12, 64, 22, 11 ]
// (c) Display the array before sorting, after each pass, and after sorting is completed.
// (d) State the best-case and worst-case time complexity for each method

#include<stdio.h>

void selection_sort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++){
            if(a[min_index]>a[j]){
                min_index=j;
            }
        }
        if(i!=min_index){
            int temp=a[i];
            a[i]=a[min_index];
            a[min_index]=temp;
        }
    }
}

void insertion_sort(int a[],int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int key=a[i];
        while(j>=0 && a[j]>key){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}

void display(int a[],int n){
    for(int i=0;i<n;i++){
        printf( " %d ",a[i]);
    }
    printf("\n");
}
int main(){
    int a[]={ 25, 12, 64, 22, 11};
    int n=sizeof(a)/sizeof(a[1]);
    printf("array before sorting :");
    display(a,n);
    // insertion_sort(a,n);
    // printf("after insertion sorting :");
    // display(a,n);
    selection_sort(a,n);
    printf("after selection sort:");
    selection_sort(a,n);
    display(a,n);
    
    return 0;
}