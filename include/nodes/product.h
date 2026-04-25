#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;

struct product
{
    int productID;
    string name;
    double price;
    int quantity;

    product(int id, string productName, double productPrice, int productQuantity);
};

#endif