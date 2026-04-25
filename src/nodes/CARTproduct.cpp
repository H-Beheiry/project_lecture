#include "..\..\include\nodes\CARTproduct.h"

CARTproduct::CARTproduct(product* p, int q)
{
    data= p;
    quantity= q;
    next= nullptr;
}