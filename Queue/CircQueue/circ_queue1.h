//
//  circ_queue.h
//  test
//
//  Created by Steve Lou on 15/10/6.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#ifndef __test__circ_queue__
#define __test__circ_queue__

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 5

typedef int DATA;

typedef struct{
    DATA data[MAXSIZE];
    int front;
    int rear;
}CircQueue;


CircQueue *CircQueueInit();
void CircQueueFree(CircQueue *queue);

int CircQueueIn(CircQueue *queue, DATA data);
void CircQueueOut(CircQueue *queue, DATA *data);
void CircQueueGetFront(CircQueue *queue, DATA *data_get);

int CircQueueIsFull(CircQueue *queue);
int CircQueueIsEmpty(CircQueue *queue);
int CircQueueGetLen(CircQueue *queue);

void CircQueueTraverse(CircQueue queue);

#endif /* defined(__test__circ_queue__) */
