#include <stdio.h>
#include "ChainList.h"

int main(){
    ChainListType *head;
    
    head = ChainListInit(head);
    ChainListTraverse(head);
    
    return 0;
}