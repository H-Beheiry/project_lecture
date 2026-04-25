#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H
#include "..\nodes\product.h"
#include "..\nodes\CARTproduct.h"
class ShoppingCart
{
    private:
        CARTproduct* head;
        int size;
        void displayNode(CARTproduct* node);
        bool isEmpty() {return size==0;}
        int  getSize() {return size;}

    public:
        ShoppingCart();
        ~ShoppingCart();
        void addItem(product* p, int q);
        void removeItem(int ID);
        void displayCart();
};

#endif