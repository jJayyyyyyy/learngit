// Given a sorted array, and a key_value
// use binary search to find the index of key_value
#include <stdio.h>
#define	Len_of_Array 6

int binary_search(const int a[], int left, int right, int key){
    if(left <= right){
        int mid = (left+right)/2;
        
        if(key < a[mid])
            return binary_search(a, left, mid, key);
        else if(key > a[mid])
            return binary_search(a, mid+1, right, key);
        else
            return mid;
    }
    
    return -1;
}

int main(){
    
    int array[Len_of_Array] = {1,2,3,4,5,6};
    int key = 6;
    
    printf("Please input the key value you want to search: ");
    scanf("%d", &key);
    printf("key : %d\n", key);
    printf("The array is: ");
    for(size_t i=0; i<Len_of_Array; ++i)
        printf("%d ", array[i]);
    
    int key_index = binary_search(array, 0, Len_of_Array-1, key);
    if(key_index >= 0)
        printf("\nThe index of key is: %d", key_index);
    else
        printf("\nError! Doesn't exist!");
}