#ifndef PRODUCT_TABLE_H
#define PRODUCT_TABLE_H
#include "..\nodes\HASHproduct.h"

class productTable
{
    public:
        productTable();
        ~productTable();

        void insert(product* p);
        void remove(int id);
        product* search(int id);
        void updateProduct(int id, double newPrice, int newQuantity);
        
    private:
        static const int TABLE_SIZE= 1000;
        HASHproduct* table[TABLE_SIZE];
        int h(int ID) {return ID%TABLE_SIZE;}
};

#endif