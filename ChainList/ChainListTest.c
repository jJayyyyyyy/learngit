#include <stdio.h>
#include <string.h>
#include "ChainList.h"

ChainListType *ChainListInit(ChainListType *head){
    DATA data;
    head=NULL;
    
    printf("Please input data of List, including key, name and age. ");
    printf("Quit when key=0.\n");
    while (1) {
        fflush(stdin);
        scanf("%s", data.key);
        if(strcmp(data.key, "0") == 0)
            break;
        
        scanf("%s%d",data.name, &data.age);
        head = ChainListAddEnd(head, data);
    }
    
    return head;
}

void ChainListTraverse(ChainListType *head){
    ChainListType *p;
    DATA data;
    
    p = head;
    if (p == NULL) {
        printf("List is empty!\n");
    }else{
        printf("All the data is as follows.\n");
        while (p != NULL) {
            data = p->data;
            printf("(%s, %s, %d)\n", data.key, data.name, data.age);
            p = p->next;
        }
    }
}

