#ifndef BST_NODE_H
#define BST_NODE_H
#include "product.h"

struct BSTproduct
{
    product* data;
    BSTproduct* lchild;
    BSTproduct* rchild;
    BSTproduct(product* p);
};

#endif