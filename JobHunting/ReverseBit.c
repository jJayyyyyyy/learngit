/* Write a program to reverse a given number(32bit, 0-31),
 * bit0 <=>bit31, bit1<=>bit30 ...
 * int ReverseNumber(unsigned int number)
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE    40
#define EMPTY   0

typedef int DATA;
typedef struct stack{
    DATA data[SIZE];
    int top;
}SeqStack;

SeqStack *StackInit(){
    SeqStack *stack;
    stack = (SeqStack *)malloc(sizeof(SeqStack));
    
    if(stack == NULL){
        return NULL;
    }else{
        stack->data[0]=0;
        stack->top=0;
        return stack;
    }
}

int StackIsEmpty(SeqStack *stack){
    return stack->top==EMPTY;
}

int StackIsFull(SeqStack *stack){
    return stack->top==SIZE;
}

int StackPush(SeqStack *stack, DATA data){
    if(StackIsFull(stack)){
        
        return 0;
    }else{
        stack->data[++stack->top]=data;
        return 1;
    }
}

DATA StackPop(SeqStack *stack){
    if(StackIsEmpty(stack)){
        exit(0);
    }else{
        return stack->data[stack->top--];
    }
}

void StackFree(SeqStack *stack){
    if(stack != NULL){
        free(stack);
    }
}

int ReverseNumber4(unsigned int number){
    unsigned int nBit;
    SeqStack *stack;
    stack = StackInit();
    
    for(int i=0; i<4; i++){
        nBit = number & 0x01;
        StackPush(stack, nBit);
        number = number >> 1;
    }
    
    number = 0;
    
    for(int i=0; i<4; i++){
        nBit = StackPop(stack);
        nBit <<= i;
        number = number + nBit;
        number = number;
    }
    
    return number;
}



int main(){
    unsigned int num=10;
    printf("%x\n", num);
    printf("\n%x\n", ReverseNumber4(num));

    return 0;
    
}