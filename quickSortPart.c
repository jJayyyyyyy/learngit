#include <stdio.h>

//(left to right) is (0 to n-1)  
int quickSortPart(int a[], int left, int right){
	int i=left, j=right;
	int key = a[i];

	while(i<j){
        while(i<j && a[j]>key){
            j--;
        }
		if(i<j){
			a[i] = a[j];//这个a[j]<key,所以要换到前面来
			i++;
		}
        while(i<j && a[i]< key){
			i++;
        }
		if(i<j){
			a[j] = a[i];//这个a[i]>key,所以要换到后面去
			j--;
		}
	}
	a[i] = key;//此时i=j了已经
	
	return i;
}

void quickSort(int a[], int left, int right){
	if(left < right){
		int mid = quickSortPart(a, left, right);
		quickSort(a, left, mid-1);
		quickSort(a, mid+1, right);
	}
}


int main(){
	int a[] = {2, 1, 4, 8, 10, 5, 4, 11, 3};
	int len = sizeof(a)/sizeof(a[0]);

	quickSort(a, 1-1, len-1);
	for(int i=0; i<len; i++){
        printf("%d\t", a[i]);
	}
	
	return 1;
}

