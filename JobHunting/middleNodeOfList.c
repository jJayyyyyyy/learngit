/* Create a List and return the middle node
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNode{
    int number;
    struct tagNode *next;
}Node;

static Node *FindMiddleNode(Node *head){
    Node *pFind;
    int count=0, mid=0;
    
    pFind = head->next;
    while(pFind != NULL){
        count++;
        pFind = pFind->next;
    }
    
    pFind = head->next;
    mid = count/2;
    count=0;
    while(count<mid){
        pFind = pFind->next;
        count++;
    }
    return pFind;
    
}

static Node *CreatNode(int number, Node *p){
    Node *newNode, *pFind;
    
    newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL){
        return NULL;
    }else{
        newNode->number = number;
        newNode->next = NULL;
        
        pFind = p;
        while(pFind->next != NULL){
            pFind = pFind->next;
        }
        pFind->next = newNode;
        
        return p;
        
    }
}

int TraverseNode(Node *p){
    Node *pFind;
    int count=0;
    pFind = p->next;
    
    while(pFind != NULL){
        count++;
        printf("%d\t", pFind->number);
        pFind = pFind->next;
    }
    
    return count;
}

int main(){
    Node singleList;
    Node *p = &singleList;
    Node *middle = NULL, *q = NULL;
    p->next = NULL;
    int number;
    
    printf("%d\n", p->number);
    
    while(1){
        printf("Input number (999 for exit): ");
        scanf("%d", &number);
        if(number == 999){
            break;
        }
        p = CreatNode(number, p);
    }
    
    printf("\n%d\n", TraverseNode(p));
    
    
    middle = FindMiddleNode(&singleList);
    if(middle){
        printf("middle: %d\n", middle->number);
    }
    

    p = singleList.next;
    while(p != NULL){
        q = p->next;
        free(p);
        p=q;
    }
    

    return 0;
    
}