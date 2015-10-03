//
//  stack.c
//  test
//
//  Created by Steve Lou on 15/10/3.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#include "stack.h"
SeqStack *SeqStackInit(){
    SeqStack *p;
    p = (SeqStack *)malloc(sizeof(SeqStack));
    
    if(p == NULL){
        printf("No more memory\n");
        return NULL;
    }else{
        p->top_index = 0;
        return p;
    }
}

void SeqStackFree(SeqStack *stack){
    if(stack != NULL)
        free(stack);
}

int SeqStackIsEmpty(SeqStack *stack){
    return (stack->top_index == 0);
}

void SeqStackClear(SeqStack *stack){
    stack->top_index = 0;
}

int SeqStackIsFull(SeqStack *stack){
    return (stack->top_index == SIZE);
}


/*use int type to return a value, to show if successfully done
 */
int SeqStackPush(SeqStack *stack, DATA data){
    if((stack->top_index+1)>SIZE){
        printf("Stack overflow!\n");
        return 0;
    }else{
        stack->data[stack->top_index] = data;
        ++stack->top_index;
        return 1;
    }
    
}

DATA SeqStackPop(SeqStack *stack){
    DATA temp_data;
    
    if(stack->top_index == EMPTY){
        printf("Stack empty!\n");
        exit(0);
        
    }else{
        temp_data = stack->data[stack->top_index];
        stack->top_index -= 1;
        return temp_data;
    }
}

/*
 */
DATA SeqStackGetTop(SeqStack *stack){
    if(stack->top_index == EMPTY){
        printf("Stack empty!\n");
        exit(0);
    }else{
        return (stack->data[stack->top_index]);
    }
}
