#include "..\..\include\dataStructures\opperationStack.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
using namespace std;


opperationStack::opperationStack() {top = nullptr;}

void opperationStack::push(string action, product* p, double price)
{
    opperation* new_node= new opperation(action, p, price);
    new_node->next= top;
    top = new_node;
}

opperation* opperationStack::pop()
{
    if (isEmpty()){return nullptr;}
    opperation* temp= top;
    top= top->next;
    return temp; 
}

void opperationStack::clear()
{
    while (!isEmpty())
    {
        opperation* temp= pop();
        delete temp;
    }
}

void opperationStack::peek()
{
    if (top!=NULL)
    {
        cout<<top->opp<<endl;
    }
    else
    {
        cout<<RED<<"no opperations availble"<<RESET<<endl;
    }
}

opperationStack::~opperationStack(){clear();}