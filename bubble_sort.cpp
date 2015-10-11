#include <iostream>
#include <stdio.h>
using namespace std;

//从后往前，每次把最小的放到未排序部分的前面
void bubble_sort(int a[], int len){
	for(int i=0; i<len; i++){
		for(int j=len-1; j>i; j--){
			if(a[j] < a[j-1]){
				int temp = a[j];
				a[j] = a[j-1];
				a[j-1] = temp;
			}
		}
	} 
}

int main(int argc, const char * argv[]){
	int a[] = {6,12,6,14,15,7,2};
	char len = sizeof(a)/sizeof(a[0]);

	bubble_sort(a,len);
	for(int index=0; index<len; index++){
		cout<<a[index]<<'\t';
	}

	return 0;
}

