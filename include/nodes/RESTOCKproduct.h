#ifndef RESTOCK_NODE_H
#define RESTOCK_NODE_H
#include "product.h"

struct RESTOCKproduct
{
    product* data;
    RESTOCKproduct* next;
    RESTOCKproduct(product* p);
};

#endif