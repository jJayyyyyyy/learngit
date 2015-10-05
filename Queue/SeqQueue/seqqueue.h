//
//  seqqueue.h
//  test
//
//  Created by Steve Lou on 15/10/5.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#ifndef __test__seqqueue__
#define __test__seqqueue__

#include <stdio.h>
#include <stdlib.h>

#define QUEUEMAX 5//QUEUEMAX = max_size_of_queue = n
typedef int DATA;

typedef struct {
    DATA data[QUEUEMAX];
    int front;
    int rear;
}SeqQueue;


SeqQueue *SeqQueueInit();

int SeqQueueIn(SeqQueue *queue, DATA data);
DATA *SeqQueueOut(SeqQueue *queue);
DATA *SeqQueueGetFront(SeqQueue *queue);

int SeqQueueIsEmpty(SeqQueue *queue);
int SeqQueueIsFull(SeqQueue *queue);

int SeqQueueGetLen(SeqQueue *queue);
void SeqQueueFree(SeqQueue *queue);

#endif /* defined(__test__seqqueue__) */













