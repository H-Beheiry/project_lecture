#ifndef OPPERATION_STACK_H
#define OPPERATION_STACK_H
#include "..\nodes\opperation.h"

class opperationStack
{
    private:
        opperation* top;

    public:
        opperationStack();
        ~opperationStack();

        void push(string action, product* p, double price= 0.0);
        opperation* pop();
        bool isEmpty() {return top==nullptr;}
        void clear();
};

#endif