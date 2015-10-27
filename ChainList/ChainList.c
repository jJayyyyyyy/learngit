#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChainList.h"

/*Add node to the end of the ChainList
 *Use *node to hold the data, *p to find the end of the ChainList
 */
ChainListType *ChainListAddEnd(ChainListType *head, DATA data){
    //TODO:
    //*newNode, pFind;
    ChainListType *node, *pFind;
    
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if (node == NULL) {
        printf("Fail to allocate memory for a new Node!");
        return head;
    }
    
    node->data = data;
    node->next = NULL;
    if (head == NULL) {
        head = node;
        return head;
    }
    
    pFind=head;
    while (pFind->next != NULL){
        pFind = pFind->next;
    }
    //Now *pFind comes to the end of the ChainList
    pFind->next = node;
    //
    //pFind->next->next is pFind->next, which is NULL
    
    return head;
}


/*Add node to the first of the ChainList, after *head
 *Use *node to hold the data
 */
ChainListType *ChainListAddFirst(ChainListType *head, DATA data){
    ChainListType *node;
    
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if (node == NULL) {
        printf("Fail to allocate memory for a new Node!");
        return head;
    }
    
    node->data = data;
    node->next = head;
    head = node;
    
    return head;
}


/*return addr where the <Node> that contains <key_string> is located
 ************ should we merge Find and Insert??? *******
 ************ what is the use of a SINGLE FIND?  *******
 ************ or it's a gateway sometimes? to verify the identity? ******
 */
ChainListType *ChainListFind(ChainListType *head, char key[]){
    ChainListType *pFind;
    
    pFind = head;
    while (pFind != NULL){
        if (strcmp(pFind->data.key, key) == 0){//it returns 0 when equals
            printf("Node found: ");
            printf("%s, %s, %d\n", key, pFind->data.name, pFind->data.age);
            return pFind;//return addr where key is located
        }
        pFind = pFind->next;
    }
    
    printf("Node not found!\n");
    return NULL;
}


/*Insert node after where key is located
 ****** and what is the use of this type?  return to what? return to who?*****
 ****** is this return_type necessary?     ********
 */
ChainListType *ChainListInsert(ChainListType *head, DATA data, char key[]){
    ChainListType *node, *pFind;
    
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if (node == NULL) {
        printf("Fail to allocate memory for a new Node!");
        return head;
    }
    
    node->data = data;
    pFind = ChainListFind(head, key);
    if(pFind != NULL){
        node->next = pFind->next;
        pFind->next = node;
        printf("Node inserted!\n");
    }else{
        printf("Not found!");
        free(node);
    }
    
    //Oh! SHIT!!!!!!!Init_return is NULL, but don't forget to modify
    //to the exact DESIRED_VALUE to return!
    //Not 'return NULL'!!! Dont forget!!!
    return head;
}


/*
 */
int ChainListDeleteNode(ChainListType *head, char key[]){
    ChainListType *pBefore, *pFind;

    //can't use ChainListFind(), because it only returns *p of Node_key
    //we've got to know the node that is ahead of Node_key
    pBefore = head;
    pFind = head;
    while(pFind != NULL){
        if (strcmp(pFind->data.key, key) ==0) {
            pBefore->next = pFind->next;
            free(pFind);
            return 1;
        }else{
            //pFind is pBefore->next
            //use pFind to find key, then use pBefore and pFind to delete Node_key
            pBefore = pFind;
            pFind = pFind->next;
        }
    }
    
    return 0;
}

/*
 */
int ChainListLength(ChainListType *head){
    ChainListType *pFind;
    int count = 0;
    
    pFind = head;
    while(pFind != NULL){
        count++;
        pFind = pFind->next;
    }
    
    return count;
}