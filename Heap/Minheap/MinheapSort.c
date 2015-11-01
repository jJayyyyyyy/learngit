//
//  MinheapSort.c
//  参考: http://blog.csdn.net/morewindows/article/details/6709644
//
//  Created by Steve Lou on 10/31/15.
//  Copyright (c) 2015 Steve. All rights reserved.
//  代码风格:
//  函数: AxxxBxxx()
//  变量: cxxxDxxx
//

#include "MinheapSort.h"

//indexNode means index-of-Node, keyNode means key-value-of-Node
void MinheapAddNode(int a[], int indexNode, int keyNode){
    a[indexNode] = keyNode;
    MinheapFixUp(a, indexNode);
}

//indexNode means index-of-Node, keyNode means key-value-of-Node
void MinheapFixUp(int a[], int indexNode){
    int indexParent, keyNode;
    indexParent = (indexNode-1)/2;
    keyNode = a[indexNode];
    
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

//length是数组长度,用来找最后一个元素,把它移到根的位置
void MinheapDeleteNumber(int a[], int length){
    a[0] = a[length-1];
    //数组长度由变成了length-1,因为最后一个已经移到根了,所以不用去管他,
    //也就是说少了一个元素,所以数组长度减小1
    MinheapFixDown(a, 0, length-1);
}

//indexNode是移到根节点的元素的下标,要根据最小堆的规则找到它合适的位置(下标)
void MinheapFixDown(int a[], int indexNode, int length){
    int indexSon, keyNode;
    indexSon = 2*indexNode + 1;
    keyNode = a[indexNode];
    
    while(indexSon < length){
        if(indexSon+1<length && a[indexSon+1]<a[indexSon]){
            //找出 a[j]和 a[j+1]中更小的,得到其下标
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

//建立一个最小堆
void MakeMinheap(int a[], int length){
    //a[0]也要向下调整
    for(int i=length/2-1; i>=0; i--){
        //注意这里是length 而不是length-1
        //因为只是要在i开始的分支上重排,而不是删除,而且也没有把最后一个节点放到i
        //重排当然要考虑最后一个节点.
        MinheapFixDown(a, i, length);
    }
}

//建好堆之后再提取数据,每次 a[0]总是最小的那个
//每次把最小的放到最后,然后数组长度-1. 最小堆排序后是递减数组
void MinheapSort(int a[], int length){
    // a[1]找好后,i=0不用再比,肯定是最大
    for(int i=length-1; i>=1; i--){
        //把最小的放到最后
        int temp=a[0];
        a[0] = a[i];
        a[i] = temp;
        MinheapFixDown(a, 0, i);
    }
}




