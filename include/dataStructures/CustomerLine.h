#ifndef CUSTOMER_LINE_H
#define CUSTOMER_LINE_H
#include "..\nodes\customer.h"

class CustomerLine
{
    public:
        CustomerLine();
        ~ CustomerLine();

        void enqueue(customerUser* user);
        void dequeue();
        int  getSize() {return size;}
        bool isEmpty() {return size==0;}

        customer* getFront();
        customer* getBack();
    
    private:
        customer* front;
        customer* rear;
        int size;
};

#endif