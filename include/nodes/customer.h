#ifndef CUSTOMER_H
#define CUSTOMER_H

class customerUser;

struct customer {
    customerUser* user;
    customer* next;
    
    customer(customerUser* u); 
};

#endif