#include "..\..\include\nodes\opperation.h"

opperation::opperation(string opp_done,product *p, double price)
{
    opp=opp_done;
    productPtr= p;
    oldPrice= price;
    next= nullptr;
}