#include "..\..\include\dataStructures\RestockingSystem.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
#include <iostream>
#include <string>
using namespace std;

RestockingSystem::RestockingSystem()
{
    front= nullptr;
    rear = nullptr;
    size = 0;
}

void RestockingSystem::enqueue(product* p)
{
    RESTOCKproduct* new_node= new RESTOCKproduct(p);
    if(isEmpty())
    {
    front=rear=new_node;
    }
    else
    {
        rear->next=new_node;
        rear=new_node;
    }
    size++;
    cout<<GREEN<<"Product added to the restocking system successfully"<<RESET<<endl;
}

void RestockingSystem::dequeue()
{
    if (isEmpty())
    {
        cout<<GREEN<<"No need to restock any products!"<<RESET<<endl;
        return;
    }
    else
    {
        RESTOCKproduct* curr= front;
        front= front->next;
        if (front == nullptr) {rear = nullptr;}
        delete curr;
        size--;
    }
}

void RestockingSystem::displayRestockQueue()
{
    if (isEmpty())
    {
        cout<<GREEN<<"No products to display...."<<RESET<<endl;
        return;
    }
    else
    {
        RESTOCKproduct *curr= front;
        while (curr!=NULL)
        {
            cout<<BLUE<<"Product ID: "<<curr->data->productID<<" Product Quantity: "<<curr->data->quantity<<" -->"<<RESET;
            curr= curr->next;
        }
        cout<<GREEN<<"NO MORE PRODUCTS NEED TO BE RESTOCKED"<<RESET<<endl;
    }
}

RestockingSystem::~RestockingSystem()
{
    RESTOCKproduct *curr= front;
    while (curr!= nullptr)
    {
        RESTOCKproduct *nextNode= curr->next;
        delete curr;
        curr= nextNode;
    }
    front= nullptr;
    rear = nullptr;
    size = 0;
}