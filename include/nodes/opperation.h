#ifndef OPERATION_H
#define OPERATION_H
#include "product.h"
#include <string>
using namespace std;

struct opperation
{
    string opp;
    product* productPtr;
    double oldPrice;
    opperation* next;
    opperation(string opp_done,product *p, double price=0.0);
};

#endif
