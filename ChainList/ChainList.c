#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ChainList.h"

/*Add node to the end of the ChainList
 *Use *node to hold the data, *p to find the end of the ChainList
 */
ChainListType *ChainListAddEnd(ChainListType *head, DATA data){
    ChainListType *node, *p;
    
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
    
    p=head;
    while (p->next != NULL)
        p = p->next;
    //Now *p comes to the end of the ChainList
    p->next = node;
    //
    //p->next->next is p->next, which is NULL
    
    return head;
}


/*Add node to the first of the ChainList, after *head
 *Use *node to hold the data
 */
ChainListType *ChainListAddFirst(ChainListType *head, DATA data){
    ChainListType *node;
    
    node = (ChainListType *)alloca(sizeof(ChainListType));
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
    ChainListType *p;
    
    p = head;
    while (p != NULL){
        if (strcmp(p->data.key, key) == 0){//it returns 0 when equals
            printf("Node found: ");
            printf("%s, %s, %d\n", key, p->data.name, p->data.age);
            return p;//return addr where key is located
        }
        p = p->next;
    }
    
    printf("Node not found!\n");
    return NULL;
}


/*Insert node after where key is located
 ****** and what is the use of this type?  return to what? return to who?*****
 ****** is this return_type necessary?     ********
 */
ChainListType *ChainListInsert(ChainListType *head, DATA data, char key[]){
    ChainListType *node, *p;
    
    node = (ChainListType *)malloc(sizeof(ChainListType));
    if (node == NULL) {
        printf("Fail to allocate memory for a new Node!");
        return head;
    }
    
    node->data = data;
    p = ChainListFind(head, key);
    if(p != NULL){
        node->next = p->next;
        p->next = node;
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
int ChainListDelete(ChainListType *head, char key[]){
    ChainListType *node, *p;

    //can't use ChainListFind(), because it only returns *p of Node_key
    //we've got to know the node that is ahead of Node_key
    node = head;
    p = head;
    while(p != NULL){
        if (strcmp(p->data.key, key) ==0) {
            node->next = p->next;
            free(p);
            return 1;
        }else{
            //p is node->next
            //use p to find key, then use node & p to delete Node_key
            node = p;
            p = p->next;
        }
    }
    
    return 0;
}

/*
 */
int ChainListLength(ChainListType *head){
    ChainListType *p;
    int count = 0;
    
    p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    
    return count;
}