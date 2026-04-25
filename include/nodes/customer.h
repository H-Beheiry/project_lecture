#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "..\actors\customerUser.h"
struct customer
{
    customerUser* user;
    customer *next;
    customer(customerUser* user);
};

#endif