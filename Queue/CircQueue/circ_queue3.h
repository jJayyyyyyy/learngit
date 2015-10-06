//
//  queue.h
//  test
//
//  Created by Steve Lou on 15/10/5.
//  Copyright (c) 2015年 Steve. All rights reserved.
//


#define MAXSIZE 5//MAXSIZE = max_size_of_queue + 1 = n+1

typedef int DATA;

typedef struct{
    DATA data[MAXSIZE-1];
    int front;
    int rear;
}CircQueue;

CircQueue *CircQueueInit();

void CircQueueFree(CircQueue *queue);

int CircQueueIn(CircQueue *queue, DATA data);
void CircQueueOut(CircQueue *queue, DATA *data_get);

int CircQueueIsEmpty(CircQueue *queue);
int CircQueueIsFull(CircQueue *queue);
void CircQueueTraverse(CircQueue *queue);
