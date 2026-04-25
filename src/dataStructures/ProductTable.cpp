#include "..\..\include\dataStructures\ProductTable.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
#include <iostream>
using namespace std;

productTable::productTable()
{
    for (int i = 0; i < TABLE_SIZE; i++){table[i] = nullptr;}
}

void productTable::insert(product* p)
{
    int idx= h(p->productID);
    HASHproduct* new_node= new HASHproduct(p);
    new_node->next= table[idx];
    table[idx]= new_node;
    cout<<GREEN<<"Product added successfully !"<<RESET<<endl;
}

void productTable::remove(int ID)
{
    int idx= h(ID);
    HASHproduct* curr = table[idx];
    HASHproduct* trail= NULL;
    while (curr!= NULL && curr->data->productID!= ID)
    {
        trail= curr;
        curr = curr->next;
    }
    if (curr==NULL)
    {
        cout<<RED<<"Product not found..."<<RESET<<endl;
    }
    else if (trail==NULL)
    {
        table[idx]= curr->next;
        cout<<GREEN<<"Product removed successfully !"<<RESET<<endl;
    }
    else
    {
        trail->next= curr->next;
        cout<<GREEN<<"Product removed successfully !"<<RESET<<endl;
    }
    delete curr;
}

product* productTable::search(int id)
{
    int idx= h(id);
    HASHproduct* curr= table[idx];
    while (curr!= NULL)
    {
        if (curr->data->productID==id){return curr->data;}
        curr= curr->next;
    }
    cout<<RED<<"Product not found..."<<RESET<<endl;
    return NULL;
}

void productTable::updateProduct(int id, double newPrice, int newQuantity)
{
    int idx= h(id);
    HASHproduct* curr= table[idx];

    while (curr!=NULL)
    {
        if  (curr->data->productID == id)
        {
            curr->data->price   = newPrice;
            curr->data->quantity= newQuantity;
            cout<<GREEN<<"Product "<<id<<" updated successfully !"<<RESET<<endl;
            return;
        }
        curr= curr->next;
    }
    cout<<RED<<"Update failed: Product ID: "<<id<<" not found."<<RESET<<endl;
}

productTable::~productTable(){}