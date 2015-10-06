//
//  queue.c
//  test
//
//  Created by Steve Lou on 15/10/5.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#include "circ_queue3.h"
#include <stdio.h>
#include <stdlib.h>

CircQueue *CircQueueInit(){
    CircQueue *queue;
    queue = (CircQueue *)malloc(sizeof(CircQueue));
    
    if(queue == NULL){
        printf("No more memory!\n");
        return NULL;
    }else{
        queue->front = 0;
        queue->rear = 0;
        return queue;
    }
}

int CircQueueIn(CircQueue *queue, DATA data){
    if(CircQueueIsFull(queue)){
        //判断是否已满
        printf("Queue is full!\n");
        return 0;
    }else{
        if(queue->rear == MAXSIZE-1)
            queue->rear = 0;
        queue->data[queue->rear] = data;
        queue->rear = (queue->rear+1)%(MAXSIZE);
        return 1;
    }
}

void CircQueueOut(CircQueue *queue, DATA *data_get){
    if(CircQueueIsEmpty(queue)){
        printf("Queue is empty!\n");
    }else{
        *data_get = queue->data[queue->front];
        queue->front = (queue->front+1) % (MAXSIZE);
    }
}

void CircQueueFree(CircQueue *queue){
    if(queue != NULL)
        free(queue);
}

int CircQueueIsEmpty(CircQueue *queue){
    return (queue->front == queue->rear);
}

int CircQueueIsFull(CircQueue *queue){
    return ((queue->rear+1)%MAXSIZE == queue->front);
}


void CircQueueTraverse(CircQueue *queue){
    int temp_front = queue->front;
    printf("%d\n", queue->rear);
    
    printf("\n");
    while ((temp_front)%MAXSIZE != queue->rear) {
        printf("%d\t", queue->data[temp_front]);
        temp_front = (temp_front + 1) % MAXSIZE;
    }
    printf("\n");
}













