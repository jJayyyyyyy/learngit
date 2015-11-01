//
//  MinheapSort.c
//  test
//
//  Created by Steve Lou on 10/31/15.
//  Copyright (c) 2015 Steve. All rights reserved.
//  代码风格:
//  函数: AxxxBxxx()
//  变量: cxxxDxxx
//

#include "MinheapSort.h"

void MinheapFixUp(int a[], int indexNode){
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
    MinheapFixUp(a, indexNode);
}

void MinheapFixDown(int a[], int indexNode, int length){
    int indexSon, keyNode;
    
    keyNode = a[indexNode];
    indexSon = 2*indexNode + 1;
    while(indexSon < length){
        if(indexSon+1<length && a[indexSon+1]<a[indexSon]){
            //找出 a[j]和 a[j+1]中更小的
            indexSon++;
        }
        
        if(keyNode <= a[indexSon]){
            //父结点比左右子结点都小,说明排好了
            break;
        }
        
        a[indexNode] = a[indexSon];
        indexNode = indexSon;
        indexSon = indexSon*2 + 1;
    }
    a[indexNode] = keyNode;
}

void MinheapDeleteNumber(int a[], int length){
    //不用删除 a[length-1],可以留着以后用
    a[0] = a[length-1];
    //数组长度len 由length 变成了 length-1
    MinheapFixDown(a, 0, length-1);
}
















