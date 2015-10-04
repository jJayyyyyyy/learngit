//
//  stack.c
//  test
//
//  Created by Steve Lou on 15/10/3.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Create and Initialize a new sequential stack
SeqStack *SeqStackInit(){
    SeqStack *new_stack;
    new_stack = (SeqStack *)malloc(sizeof(SeqStack));
    
    if(new_stack == NULL){
        printf("No more memory!\n");
        return NULL;
    }else{
        new_stack->top_index = 0;
        return new_stack;
    }
}



//先把栈顶上移，再压入数据，若栈已满，则返回0
int SeqStackPush(SeqStack *stack, DATA data){
    if(stack->top_index == SIZE){
        printf("Stack is full!\n");
        return 0;
    }else{
        ++stack->top_index;//先把栈顶上移
        stack->data[stack->top_index] = data;//再压入数据
        printf("Data[%d] in: %s, %d\n",stack->top_index, stack->data[stack->top_index].name,stack->data[stack->top_index].age);
        return 1;
    }
}

//先把栈顶下移，再弹出数据，若栈为空，则结束程序
DATA SeqStackPop(SeqStack *stack){
    DATA temp_data;
    if(stack->top_index == EMPTY){
        printf("Stack is empty!\n");
        exit(0);//直接退出程序
    }else{
        temp_data = stack->data[stack->top_index];
        printf("Data[%d] out: %s, %d\n",stack->top_index, temp_data.name, temp_data.age);
        //--stack->top_index;
        return (stack->data[stack->top_index--]);
    }
}

//返回栈顶数据，若栈为空，则结束程序
DATA SeqStackGetTop(SeqStack *stack){
    if(stack->top_index == EMPTY){
        printf("Stack is empty!\n");
        exit(0);//直接退出程序
    }else{
        printf("Data[%d] got: %s, %d\n", stack->top_index, stack->data[stack->top_index].name, stack->data[stack->top_index].age);
        return stack->data[stack->top_index];
    }
}


//return 1 when empty, else return 0.
int SeqStackIsEmpty(SeqStack *stack){
    return (stack->top_index == 0);
}

//return 1 when full, else return 0.
int SeqStackIsFull(SeqStack *stack){
    return (stack->top_index == SIZE);
}



//Clear a stack, while the memory still can be used
void SeqStackClear(SeqStack *stack){
    stack->top_index = 0;
}

//To release occupied memory
void SeqStackFree(SeqStack *stack){
    if(stack != NULL){
        SeqStackClear(stack);
        free(stack);
    }
}




/*

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
*/










