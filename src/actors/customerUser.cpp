#include "..\..\include\actors\customerUser.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
#include "..\..\include\dataStructures\CustomerLine.h"

customerUser::customerUser(string uname, string pass, int id, productTable* catalog, SortedProducts* tree, CustomerLine* line)
{
    username= uname;
    password= pass;
    ID= id;
    product_catalog= catalog;
    product_tree= tree;
    checkoutLine= line;
    customer_cart= new ShoppingCart();
    status= "BROWSING";
}

void customerUser::browseItems()
{
    product_tree->displayProducts(product_tree->root);
}

void customerUser::addTocart(int productID, int quantity)
{
    product* product_added= product_catalog->search(productID);
    if (product_added!= NULL && product_added->quantity>=quantity)
    {
        customer_cart->addItem(product_added,quantity);
        cout<<GREEN<<"Product added to cart successfully"<<RESET<<endl;
    }
    else
    {
        cout<<RED<<"Cannot add product..."<<RESET<<endl;
    }
}

void customerUser::removeFromCart(int productID)
{
    customer_cart->removeItem(productID);
}

void customerUser::displayCart()
{
    customer_cart->displayCart();
}

void customerUser::queueToCheckout()
{
    checkoutLine->enqueue(this);
    status= "QUEUED";
}