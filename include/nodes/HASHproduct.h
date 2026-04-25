#ifndef HASH_PRODUCT_H
#define HASH_PRODUCT_H
#include "product.h"

struct HASHproduct
{
    product* data;
    HASHproduct* next;
    HASHproduct(product* p);
};

#endif