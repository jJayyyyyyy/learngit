#include <iostream>
using namespace std;

//每次把未排序部分的第一个插入到有序部分的合适位置
//把小的放前面来，最后升序排列
void insert_sort(int a[], int len){
	int i,j;
	int key;
	for(j=1; j<len; j++){
		i = j-1;
		key = a[j];
		while(i>=0 && a[i]>key){
			a[i+1] = a[i];
			i -= 1;
		}
		a[i+1] = key;
	}
}

int main(int argc, const char * argv[]){
	int a[] = {4, 1, 5, 9, 2, 1, 3, 7};
	int len = sizeof(a)/sizeof(a[0]); 

	insert_sort(a, len);
	for(int index=0; index<len; index++){
		cout<<a[index]<<'\t';
	}	

	return 0;
}


