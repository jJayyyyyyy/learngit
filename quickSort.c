#include <stdio.h>

//(left to right) is (0 to n-1)  
void quick_sort(int a[], int left, int right){
    if(left < right){
        int i = left, j = right;
        int key = a[i];
        
        while(i < j){
            while(i<j && key<a[j]){
                j -= 1;
            }
            if(i<j){
                a[i] = a[j];//这个a[j]<key,所以要换到前面来
                i += 1;
            }
            while(i<j && key>a[i]){
                i += 1;
            }
            if(i<j){
                a[j] = a[i];//这个a[i]>key,所以要换到后面去
                j -= 1;
            }
        }
        
        a[i] = key;//此时i=j
        quick_sort(a, left, i-1);
        quick_sort(a, i+1, right);
    }
}

int main(){
	int a[] = {2, 1, 4, 8, 10, 5, 4, 11, 3};
	int len = sizeof(a)/sizeof(a[0]);

	quick_sort(a, 1-1, len-1);
	for(int i=0; i<len; i++){
		cout<<a[i]<<'\t';
	}
	
	return 1;
}
