/*Given a sorted(ascengding) array and a key to search its index
 */
#include <stdio.h>
#define	LENGTH 6


int binarySearch(const int a[], int left, int right, int key){
    if(left <= right){
        int mid = (left+right)/2;
        if(key < a[mid]){
            return binarySearch(a, left, mid-1, key);
        }else if(key > a[mid]){
            return binarySearch(a, mid+1, right, key);
        }else{
            return mid;
        }
    }
    
    return -1;
}

int main(){
    int array[LENGTH] = {1,2,3,4,5,6};
    int key=0, key_index=0;
    
    printf("Please input the key value you want to search: ");
    scanf("%d", &key);
    printf("key : %d\nThe array is: ", key);
    for(size_t i=0; i<LENGTH; ++i)
        printf("%d ", array[i]);
    
    key_index = binarySearch(array, 0, LENGTH-1, key);
    if(key_index >= 0)
        printf("\nThe index of key is: %d", key_index);
    else
        printf("\nError! Doesn't exist!");
}