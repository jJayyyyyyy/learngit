//
//  stack.h
//  test
//
//  Created by Steve Lou on 15/10/3.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#ifndef __test__stack__
#define __test__stack__

#include <stdio.h>
#include <stdlib.h>
#define SIZE    15
#define EMPTY   0


typedef struct{
    char name[15];
    int age;
}DATA;


/*data里面存放数据，后进先出，出栈后不用删除，下次直接覆盖即可
 *top_index用来指明栈顶序号，每次操作后更新
 */
typedef struct stack{
    DATA data[SIZE+1];
    int top_index;
}SeqStack;


#endif /* defined(__test__stack__) */
