#include <stdio.h>
#include "ChainList.h"

int main(){
    ChainListType *head;
    char key[15]={0};
    DATA data;
    
    //Initialize the ChainList
    head = ChainListInit();
    ChainListTraverse(head);
    
    ///Find out if the is a Node that matches the key
    printf("\n");
    printf("Please input the key of Node you want to find: ");
    scanf("%s", key);
    ChainListFind(head, key);
    
    
    //Insert a Node
    //Use key to find where to insert the Node
    //Then input the Data of that Node
    printf("\n");
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