//
//  stack.h
//  test
//
//  Created by Steve Lou on 15/10/3.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#ifndef __test__stack__
#define __test__stack__


#define SIZE    3
#define EMPTY   0

/*自定义数据类型
 */
typedef struct{
    char name[15];
    int age;
}DATA;

/*data数组里面存放数据，后进先出，出栈后不用删除，下次直接覆盖即可
 *top用来指明栈顶序号，每次操作后更新
 */
typedef struct stack{
    DATA data[SIZE+1];//DATA类型的data数组[1..SIZE]用于存放数据
    int top;
}SeqStack;

//-Create and Initialize a new sequential stack
//tested
SeqStack *SeqStackInit();


//--return 1 when successfully pushed, return 0 when failed
//tested
int SeqStackPush(SeqStack *stack, DATA data);

//--先把栈顶下移，再弹出数据，若栈为空，则结束程序
//tested
DATA SeqStackPop(SeqStack *stack);

//--返回栈顶数据，若栈为空，则结束程序
//tested
DATA SeqStackGetTop(SeqStack *stack);


//---return 1 when empty, else return 0
//tested
int SeqStackIsEmpty(SeqStack *stack);

//---return 1 when full, else return 0
//tested
int SeqStackIsFull(SeqStack *stack);



//----Clear a stack, while the memory still can be used
//没有释放内存使用权限，只是把栈顶序号赋为0，下次写入时直接覆盖即可
//程序内部对这部分内存可读可写，其他程序对这部分内存只能读不能写
//tested
void SeqStackClear(SeqStack *stack);

//----To release occupied memory
//释放了内存使用权限，其他程序也可以用这部分内存了
//tested
void SeqStackFree(SeqStack *stack);






#endif /* defined(__test__stack__) */



















