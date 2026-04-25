#include "..\..\include\actors\staff.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"

staff::staff(int id, string pass, string uname, productTable* product_hashmap, CustomerLine* checkout_queue, RestockingSystem* restock_queue)
{
    ID= id;
    password= pass;
    username= uname;
    product_catalog= product_hashmap;
    checkout_line  = checkout_queue;
    restcok_system = restock_queue;
}

void staff::updateItem(int id, double newPrice, int newQuantity)
{
    product_catalog->updateProduct(id,newPrice,newQuantity);
}

void staff::addItemToRestock(int productID)
{
    product* item= product_catalog->search(productID);
    if (item!=NULL)
    {
        restcok_system->enqueue(item);
    }
}

void staff::removeItemFromRestock()
{
    restcok_system->dequeue();
}

void staff::displayItemsToRestock()
{
    restcok_system->displayRestockQueue();
}

void staff::dequeCustomer()
{
    checkout_line->dequeue();
}