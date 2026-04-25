#include "..\..\include\dataStructures\CustomerLine.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
#include <iostream>
#include <string>
using namespace std;

CustomerLine::CustomerLine()
{
    front= nullptr;
    rear = nullptr;
    size = 0;
}

void CustomerLine::enqueue(customerUser* user)
{
    customer *new_node= new customer(user);
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
}

void CustomerLine::dequeue()
{
    if (isEmpty())
    {
        cout<<RED<<"Customer queue is empty...."<<RESET<<endl;
        return;
    }
    else
    {
        customer* curr= front;
        front= front->next;
        if (front == nullptr) {rear = nullptr;}
        delete curr;
        size--;
    }
}

customer* CustomerLine::getFront(){return front;}
customer* CustomerLine::getBack() {return rear;}

CustomerLine::~CustomerLine()
{
    customer *curr= front;
    while (curr!= nullptr)
    {
        customer *nextNode= curr->next;
        delete curr;
        curr= nextNode;
    }
    front= nullptr;
    rear = nullptr;
    size = 0;
}