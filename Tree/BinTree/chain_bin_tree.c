//
//  chain_bin_tree.c
//  test
//
//  Created by Steve Lou on 15/10/6.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#include "chain_bin_tree.h"
#include <stdio.h>
#include <stdlib.h>

BinTree *BinTreeRootInit(){
    BinTree *node;
    node = (BinTree *)malloc(sizeof(BinTree));
    
    if(node != NULL){
        printf("Input data of root: ");
        scanf("%c", &node->data);
        node->left = NULL;
        node->right = NULL;
        printf("\n");
        return node;
    }else
        return NULL;
}


BinTree *BinTreeGetLeft(BinTree *parent){
    if(parent != NULL)
        return parent->left;
    else{
        printf("Parent node is empty!\n");
        return NULL;
    }
}

BinTree *BinTreeGetRight(BinTree *parent){
    if(parent != NULL)
        return parent->right;
    else{
        printf("Parent node is empty!\n");
        return NULL;
    }
}

int BinTreeIsEmpty(BinTree *root){
    if(root != NULL)
        return 0;
    else
        return 1;
}

int BinTreeDepth(BinTree *root){
    int depth1, depth2;
    
    if(root == NULL)
        return 0;
    else{
        depth1 = BinTreeDepth(root->left);
        depth2 = BinTreeDepth(root->right);
        
        if(depth1 > depth2)
            return depth1+1;//加上根
        else
            return depth2+1;
    }
}

BinTree *BinTreeFindNode(BinTree *root, DATA data_for_search){
    BinTree *node;

    if(root == NULL)
        return NULL;
    else{
        if(root->data == data_for_search)
            return root;
        else{
            //可以算是DLR
            if((node = BinTreeFindNode(root->left, data_for_search)))
                return node;
            else if((node = BinTreeFindNode(root->right, data_for_search)))
                return node;
            else
                return NULL;
        }
    }
}

//可以算是LRD
void BinTreeClear(BinTree *root){
    if(root != NULL){
        BinTreeClear(root->left);
        BinTreeClear(root->right);
        root = NULL;
        free(root);
    }
}

void BinTree_DLR(BinTree *root){
    if(root != NULL){
        printf("%c, ", root->data);
        BinTree_DLR(root->left);
        BinTree_DLR(root->right);
    }
    return;
}

void BinTree_LDR(BinTree *root){
    if(root != NULL){
        BinTree_LDR(root->left);
        printf("%c, ", root->data);
        BinTree_LDR(root->right);
    }
    return;
}

void BinTree_LRD(BinTree *root){
    if(root != NULL){
        BinTree_LRD(root->left);
        BinTree_LRD(root->right);
        printf("%c, ", root->data);
    }
    return;
}

void BinTree_Level(BinTree *root){
    BinTree *node;
    BinTree *queue[MAXSIZE];
    int front=0, rear=0;
    
    if(root != NULL){
        rear = (rear+1) % MAXSIZE;
        queue[rear] = root;
    }
    
    while(front != rear){
        front = (front+1) % MAXSIZE;
        node = queue[front];
        printf("%c, ", node->data);
        
        if(node->left != NULL){
            rear = (rear+1) % MAXSIZE;
            queue[rear] = node->left;
        }
        if(node->right != NULL){
            rear = (rear+1) % MAXSIZE;
            queue[rear] = node->right;
        }
    }
    
    return;
}

//添加node 到 parent，node是parent的左子树还是右子树取决于select
//select=1 means add node to left, while 2 means right
int BinTreeAddNodePartial(BinTree *parent, BinTree *node, int select){
    if(parent == NULL){
        printf("Parent node is empty!\n");
        return 0;
    }
    
    switch (select) {
        case 1:
            if(parent->left != NULL){
                printf("Left son is not empty!\n");
                return 0;
            }else{
                parent->left = node;
            }
            break;
            
        case 2:
            if(parent->right != NULL){
                printf("Right son is not empty!\n");
                return 0;
            }else
                parent->right = node;
            break;
            
        default:
            printf("Parament error!\n");
            break;
    }
    return 1;
}

//从根开始找，找到数据对应的节点，然后添成为其左节点或者右节点
//这是一个综合函数，上面的一些函数是它的子函数
void BinTreeAddNode(BinTree *root){
    BinTree *node, *parent;
    DATA parent_data;
    char select;
    
    node = (BinTree *)malloc(sizeof(BinTree));
    if(node != NULL){
        printf("输入要添加的节点数据: ");
        fflush(stdin);
        scanf("%s", &node->data);//why %s?
        node->left = NULL;
        node->right = NULL;
        printf("\n");
        printf("输入父节点数据: ");
        fflush(stdin);
        scanf("%s", &parent_data);//why %s?
        printf("\n");
        
        parent = BinTreeFindNode(root, parent_data);
        if(parent == NULL){
            printf("未找到父节点\n");
            free(node);
            return;
        }
        //如果该父节点已经有左右节点无法再插入了怎么办？
        //在添加节点的BinTreeAddNode()函数中解决
        printf("1.添加到左子树\n2.添加到右子树\n");
        do{
            scanf("%s", &select);
            select -= '0';
            //if(select==1 || select==2)
                BinTreeAddNodePartial(parent, node, select);
        }while(select!=1 && select!=2);
    }
    return;
}

















