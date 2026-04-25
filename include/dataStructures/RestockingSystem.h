#ifndef  RESTOCKING_SYSTEM_H
#define RESTOCKING_SYSTEM_H
#include "..\nodes\product.h"
#include "..\nodes\RESTOCKproduct.h"

class RestockingSystem
{
    private:

        RESTOCKproduct* front; 
        RESTOCKproduct* rear;
        int size;

    public:
        RestockingSystem();
        ~RestockingSystem();
        
        void enqueue(product* p);
        void dequeue();
        void displayRestockQueue();
        bool isEmpty() {return size==0;}
        int  getSize() {return size;}
};

#endif