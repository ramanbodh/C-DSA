// Write a C program to reverse an integer array in-place without using a second array.
// (a) Write a function void reverseArray(int arr[], int n) using two pointers: swap elements from both ends moving towards the center until the pointers meet.
// (b) Test the program on two separate arrays:
// • An array with an odd number of elements (e.g., {10, 20, 30, 40, 50}).
// • An array with an even number of elements (e.g., {1, 2, 3, 4, 5, 6}).
// (c) Print the array before and after reversal for both cases.

#include<stdio.h>
int main(){
    int a[]={1,2,3,4,5,6,7};
    printf("array in  order\n");
    for(int i=0;i<7;i++){
        printf("%d ",*(a+i));
    }
    int i=0,j=6;
    for(int i=0;i<j;i++){
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        j--;
    }
    printf("after reversal \n");
    for(i=0;i<7;i++){
        printf("%d ",*(a+i));
    }

    
    return 0;

}