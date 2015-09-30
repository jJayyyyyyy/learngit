#include <stdio.h>
#include "ChainList.h"

int main(){
    ChainListType *head;
    char key[15]={0};
    DATA data;
    
    //Initialize the ChainList
    head = ChainListInit();
    ChainListTraverse(head);
    
    //Insert a Node
    //Use key to find where to insert the Node
    //Then input the Data of that Node
    printf("\nInput key to insert a Node:");
    scanf("%s",key);
    if(ChainListFind(head, key)) {
        printf("OK! Input the Data of Node (key name age): ");
        scanf("%s%s%d", data.key, data.name, &data.age);
        printf("%s\t%s\t%s\t%d\n", key, data.key, data.name, data.age);
        head = ChainListInsert(head, data, key);
        ChainListTraverse(head);
    }else{
        printf("Node not found!");
    }
    
    
    
    return 0;
}