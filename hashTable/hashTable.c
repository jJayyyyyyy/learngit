#include <stdio.h>
#define HASH_LEN 13
#define DATATABLE_SIZE 7

//用除法取余，用HASH_LEN作为n
void hashInsert(int hash[], int data) {
    int i = data % HASH_LEN;

    //如果冲突，则对应的hash[i]不为零，这里用线性探测法处理冲突
    //这里要求data不为零，要不然会被认为这里没用过
    while(hash[i] != 0){
        i++;
        i = i % HASH_LEN;
    }
    //然后把数据填到地址i
    hash[i] = data;
}

void hashCreate(int hash[], int data[], int lenData){
    for(int i=0; i<len; i++) {
        hashInsert(hash, data[i]);
    }
}

int hashSearch(int hash[], int key) {
    int i = key % HASH_LEN;
    
    //冲突时(不为空，但是也不等于key，那一定是冲突了)的处理方法
    while(hash[i]!=0 && hash[i]!=key){
        i++;
        i = i % HASH_LEN;
    }
    
    //退出循环有两种可能: 要么hash[i]=0, 要么hash[i]=key
    //hash[i]=0, 没找着
    if(hash[i] == 0){
        return -1;
    }else{
        //hash[i]=key 找着了，返回下标地址
        return i;
    }
}


int main(){
    //待存储的数据
    int data[DATATABLE_SIZE] = {69, 28, 54, 37, 92, 2, 28};
    //用来存放数据的hash表，初始化为0
    int hash[HASH_LEN] = {0};

    hashCreate(hash, data, DATATABLE_SIZE);
    printf("%d", hashSearch(hash, 2));
    
    return 0;
}