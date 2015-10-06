//  先队尾加1，再入队。先队首加1，再出队
//  MAX = n，按n个空格来算最多只能用到n-1格子
//  如果不出队，第一个格子无法使用
//  circ_queue2.c
//  test
//
//  Created by Steve Lou on 15/10/6.
//  Copyright (c) 2015年 Steve. All rights reserved.
//
#include "circ_queue1.h"
#include <stdio.h>
#include <stdlib.h>


CircQueue *CircQueueInit(){
    CircQueue *new_queue;
    new_queue = (CircQueue *)malloc(sizeof(CircQueue));
    
    if(new_queue != NULL){
        new_queue->front = 0;
        new_queue->rear = 0;
        //初始化时先把不能用到的这个归零，防止意外读到乱码
        //只有这个没有被自动初始化为0
        new_queue->data[MAXSIZE-1]=0;
        return new_queue;
    }else{
        printf("No more memory!\n");
        return NULL;
    }
}

void CircQueueFree(CircQueue *queue){
    if(queue != NULL)
        free(queue);
}


int CircQueueIn(CircQueue *queue, DATA data){
    if((queue->rear+1)%MAXSIZE == queue->front){
        //判断是否已满
        printf("Queue is full!\n");
        return 0;
    }else{
        queue->rear = (queue->rear+1) % MAXSIZE;
        queue->data[queue->rear] = data;
        return 1;
    }
}

void CircQueueOut(CircQueue *queue, DATA *data_get){
    if(queue->rear == queue->front){
        //判断是否为空
        printf("Queue is empty!\n");
    }else{
        queue->front = (queue->front+1) % MAXSIZE;
        *data_get = queue->data[queue->front];
    }
}

void CircQueueGetFront(CircQueue *queue, DATA *data_get){
    if(queue->rear == queue->front){
        printf("ueue is empty!\n");
    }else{
        *data_get = queue->data[queue->front];
    }
}


int CircQueueIsFull(CircQueue *queue){
    return ((queue->rear+1)%MAXSIZE == queue->front);
}

int CircQueueIsEmpty(CircQueue *queue){
    return (queue->rear == queue->front);
}

int CircQueueGetLen(CircQueue *queue){
    return (queue->rear - queue->front + MAXSIZE) % MAXSIZE;
}

void CircQueueTraverse(CircQueue *queue){
    int temp_front = queue->front;
    
    printf("\n");
    //判断是队列否为空(为空表示遍历完成)
    while((temp_front)%MAXSIZE != queue->rear){
        //按照 先队首加1，再读数据的规则
        temp_front = (temp_front + 1) % MAXSIZE;
        printf("%d\t", queue->data[temp_front]);
    }
    printf("\n");
}








