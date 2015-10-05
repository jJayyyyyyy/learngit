//
//  seqqueue.c
//  test
//
//  Created by Steve Lou on 15/10/5.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#include "seqqueue.h"

SeqQueue *SeqQueueInit(){
    SeqQueue *queue;
    queue = (SeqQueue *)malloc(sizeof(SeqQueue));
    
    if(queue != NULL){
        queue->front = 0;
        queue->rear = 0;
        return queue;
    }else{
        printf("No more memory!\n");
        return NULL;
    }
}

//0..n-1
int SeqQueueIn(SeqQueue *queue, DATA data){
    if(SeqQueueIsFull(queue)){
        printf("Failed!\n");
        return 0;
    }else{
        queue->data[queue->rear++] = data;
        return 1;
    }
}

DATA *SeqQueueOut(SeqQueue *queue){
    if(SeqQueueIsEmpty(queue)){
        printf("Failed!\n");
        exit(0);//防止读到NULL
    }else{
        return &(queue->data[queue->front++]);
    }
}

DATA *SeqQueueGetFront(SeqQueue *queue){
    if(SeqQueueIsEmpty(queue)){
        printf("Failed!\n");
        exit(0);//防止读到NULL
    }else{
        return &(queue->data[queue->front]);
    }
}

int SeqQueueIsEmpty(SeqQueue *queue){
    return (queue->front == queue->rear);
}

//n is not used
int SeqQueueIsFull(SeqQueue *queue){
    return (queue->rear == QUEUEMAX);
}

int SeqQueueGetLen(SeqQueue *queue){
    return (queue->rear - queue->front);
}

void SeqQueueFree(SeqQueue *queue){
    if(queue != NULL)
        free(queue);
}
