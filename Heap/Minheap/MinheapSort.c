//
//  MinheapSort.c
//  test
//
//  Created by Steve Lou on 10/31/15.
//  Copyright (c) 2015 Steve. All rights reserved.
//

#include "MinheapSort.h"

void MinheapFixup(int a[], int indexNode){
    int indexParent, keyNode;
    keyNode = a[indexNode];
    indexParent = (indexNode-1)/2;
    
    while(indexParent>=0 && indexNode!=0){
        if(keyNode >= a[indexParent]){
            break;
        }else{
            //类似插入排序
            a[indexNode] = a[indexParent];
            indexNode = indexParent;
            indexParent = (indexParent-1)/2;
        }
    }
    a[indexNode] = keyNode;
}

void MinheapAddNumber(int a[], int indexNode, int data){
    a[indexNode] = data;
    MinheapFixup(a, indexNode);
}
