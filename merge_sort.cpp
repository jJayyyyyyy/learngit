#include <iostream>
using namespace std;

class Sort {
public:
    //two sorted arrays [array_a, array_b] --> a sorted array [array_temp]
    //from small to big
    void merge_array_AB(int a[], int len_a, int b[], int len_b, int temp[]){
        int i=0, j=0;
        int k=0;
        
        while(i<len_a && j<len_b){
            if (a[i]<b[j])
                temp[k++] = a[i++];
            else
                temp[k++] = b[j++];
        }
        while (i < len_a)
            temp[k++] = a[i++];
        while (j < len_b)
            temp[k++] = b[j++];
    }
    
    
    //同一个数组，分成两段来整理 (假设两段内均有序)
    //a[0]~a[n-1], len = (n-1)+1 - 0 =n
    //mid = (0 + n-1) / 2
    //array_a: a[0]~a[mid], that is a[left]~a[mid]
    //array_b: a[mid+1]~a[n-1], that is a[mid+1]~a[right]
    void merge_array(int a[], int left, int mid, int right, int temp[]){
        //a[0]~a[n-1], a[left]~a[right]
        //a[left]~a[mid]  ,  a[mid+1]~a[right]
        int i=left, j=mid+1;
        int k=0;
        
        //len_arrayA = (mid+1 - i)
        //len_arrayB = (right+1 - j)
        while(i<=mid && j<=right){
            if(a[i] < a[j])
                temp[k++] = a[i++];
            else
                temp[k++] = a[j++];
            
            //temp[k++] = (a[i]<a[j]) ? a[i++] : a[j++];
        }
        while(i <= mid)
            temp[k++] = a[i++];
        while(j <= right)
            temp[k++] = a[j++];
        
        //temp[] now has k elements,
        //that means the length of temp is k
        //k = right+1 - left
        for(i=0; i<k; i++){
            //attention:
            //instead of a[i]=temp[i], use left as the Base!!!
            //instead of a[i]=temp[i], use left as the Base!!!
            //instead of a[i]=temp[i], use left as the Base!!!
            //a[left+i] = temp[i];
            //very important!!!
            
            a[left+i] = temp[i];
            
        }
    }
    
    
    void merge_sort(int a[], int left, int right, int temp[]){
        if(left < right){
            //firstly, left=0, right=3 : a[0]~a[3]
            //then mid=1, arrayA:a[0]~a[1], arrayB:a[2]~a[3]
            //so mid is the right_border of arrayA
            //and mid+1 is the left_border of arrayB
            //arrayA: a[left]~a[mid], arrayB: a[mid+1]~a[right]
            int mid = (left + right) / 2;
            
            merge_sort(a, left, mid, temp);
            merge_sort(a, mid+1, right, temp);
            merge_array(a, left, mid, right, temp);
        }
    }
    
    
    //complete with left=0, right=len-1 and a pointer (*p)
    bool mergeSort(int a[], int len){
        int *p = new int[len];
        if(p == NULL)
            return false;
        //len=0 is not allowed
        
        merge_sort(a, 0, len-1, p);
        delete[] p;
        
        return true;
    }
};

int main(int argc, const char * argv[]) {
    
    int a[] = {6, 1, 2, 5, 3, 4, 2};
    Sort var = *new Sort;
    var.mergeSort(a, 7);
    
    for(int i=0; i<7;i++){
        cout<<a[i]<<'\t';
    }
}

