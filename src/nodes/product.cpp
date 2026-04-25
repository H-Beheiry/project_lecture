#include "..\..\include\nodes\product.h"

product::product(int id, string productName, double productPrice, int productQuantity)
{
    productID= id;
    name= productName;
    price= productPrice;
    quantity= productQuantity;
}