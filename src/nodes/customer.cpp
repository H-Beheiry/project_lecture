#include "..\..\include\nodes\customer.h"

customer::customer(customerUser* user)
{
    this->user= user;
    next= nullptr;
}