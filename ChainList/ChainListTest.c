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

int ChainListFree(ChainListType *head){
    ChainListType *p, *q;

    p = head;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }
    
    return 1;
}


void ChainListTraverse(ChainListType *head){
    ChainListType *pTraverse;
    DATA data;
    
    pTraverse = head;
    if (pTraverse == NULL) {
        printf("List is empty!\n");
    }else{
        printf("All the data is as follows.\n");
        while (pTraverse != NULL) {
            data = pTraverse->data;
            printf("(%s, %s, %d)\n", data.key, data.name, data.age);
            pTraverse = pTraverse->next;
        }
    }
}

