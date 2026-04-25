#ifndef CUSTOMER_USER_H
#define CUSTOMER_USER_H
#include "..\dataStructures\ShoppingCart.h"
#include "..\dataStructures\ProductTable.h"
#include "..\dataStructures\SortedProducts.h"

class CustomerLine;
class customerUser
{
    public:
        customerUser(string uname, string pass, int id, productTable* catalog, SortedProducts* tree, CustomerLine* line);
        string getUsername(){return username;}
        string getPassword(){return password;}
        void setStatus(string s) {status=s;};
        ShoppingCart* customer_cart;
        void browseItems();
        void addTocart(int productID, int quantity);
        void removeFromCart(int productID);
        void displayCart();
        void queueToCheckout();
    private:
        productTable* product_catalog;
        SortedProducts* product_tree;
        CustomerLine* checkoutLine;
        
        string username;
        string password;
        string status;
        int ID;
        
};

#endif