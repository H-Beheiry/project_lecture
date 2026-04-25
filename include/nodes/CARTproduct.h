#ifndef CART_NODE_H
#define CART_NODE_H
#include "product.h"

struct CARTproduct
{
    product* data;
    CARTproduct* next;
    int quantity;
    CARTproduct(product* p, int q);
};

#endif