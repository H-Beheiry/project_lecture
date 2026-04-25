#include "..\..\include\dataStructures\ShoppingCart.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
#include <iostream>
using namespace std;

ShoppingCart::ShoppingCart()
{
    head= NULL;
    size= 0;
}

void ShoppingCart::addItem(product* p, int q)
{
    CARTproduct* new_node= new CARTproduct(p,q);
    if (head==NULL)
    {
        head= new_node;
    }
    else
    {
        new_node->next= head;
        head= new_node;
    }
    size++;
}

void ShoppingCart::removeItem(int ID)
{
    if (isEmpty())
    {
        cout<<RED<<"Cannot remove items from an empty shopping cart"<<RESET<<endl;
    }
    else
    {
        if (head->data->productID==ID)
        {
            CARTproduct* curr= head;
            head= head->next;
            delete curr;
        }
        else
        {
            CARTproduct* curr= head;
            CARTproduct* trail= NULL;
            bool found= false;
            while (curr!=NULL && !found)
            {
                if (curr->data->productID==ID)
                {
                    found= true;
                }
                else
                {
                    trail= curr;
                    curr = curr->next;
                }
            }
            if (found)
            {
                trail->next= curr->next;
                delete curr;
            }
            else
            {
                cout<<RED<<"Item not found try again...."<<RESET<<endl;
            }
        }
    }
}

void ShoppingCart::displayNode(CARTproduct* node)
{
    cout
    <<BLUE<<"Product with ID: "<<node->data->productID<<RESET<<endl
    <<BLUE<<"============================================="<<RESET<<endl
    <<WHITE
    <<"Name:      "<<node->data->name<<endl
    <<"Price:     "<<node->data->price<<endl
    <<"Quantity:  "<<node->data->quantity<<endl
    <<RESET
    <<RED<<"============================================="<<RESET<<endl;
}

void ShoppingCart::displayCart()
{
    if (isEmpty())
    {
        cout<<RED<<"cannot display an empty cart"<<RESET<<endl;
    }
    else
    {
        CARTproduct* curr= head;
        while (curr!=NULL)
        {
            displayNode(curr);
            curr= curr->next;
        }
    }
}