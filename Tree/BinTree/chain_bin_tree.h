//
//  chain_bin_tree.h
//  test
//
//  Created by Steve Lou on 15/10/6.
//  Copyright (c) 2015年 Steve. All rights reserved.
//

#ifndef __test__chain_bin_tree__
#define __test__chain_bin_tree__

#include <stdio.h>
#define MAXSIZE 10

typedef char DATA;

typedef struct ChainTree{
    DATA data;
    struct ChainTree *left, *right;
}BinTree;

BinTree *BinTreeRootInit();

void BinTreeAddNode(BinTree *root);

void BinTree_DLR(BinTree *root);

#endif /* defined(__test__chain_bin_tree__) */
