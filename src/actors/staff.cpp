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
        cout<<GREEN<<"Item added successfully !"<<RESET<<endl;
    }
}

void staff::removeItemFromRestock(int new_quantity)
{
    RESTOCKproduct* item_restocked= restcok_system->getFront();
    if (item_restocked!=NULL)
    {
    item_restocked->data->quantity= new_quantity;
    restcok_system->dequeue();
    }
    else
    {
        cout<<RED<<"No items for restock....."<<RESET<<endl;
    }
}

void staff::displayItemsToRestock()
{
    restcok_system->displayRestockQueue();
}

void staff::dequeCustomer()
{
    customer* first_customer= checkout_line->getFront();
    if (first_customer!=NULL)
    {
    ShoppingCart* first_Customer_cart= first_customer->user->customer_cart;
    CARTproduct* curr= first_Customer_cart->getHead();
    while (curr!=NULL)
    {
        curr->data->quantity-= curr->quantity;
        if (curr->data->quantity<=0)
        {
            curr->data->quantity= 0;
            cout<<YELLOW<<"Warning: "<<curr->data->name<<" is OUT OF STOCK!"<<RESET<<endl;
            restcok_system->enqueue(curr->data);
        }
        else if (curr->data->quantity < 5)
        {
            cout<<YELLOW<<"Warning: "<<curr->data->name<<" is running low."<<RESET<<endl;
            restcok_system->enqueue(curr->data);
        }
        else if (!product_catalog->search(curr->data->productID))
        {
            cout<<RED<<"Item "<<curr->data->name<<" is no longer sold here. Removing from total."<<RESET<<endl;
        }
        curr= curr->next;
    }
    first_customer->user->setStatus("BROWSING");
    checkout_line->dequeue();
    cout<<GREEN<<"Checkout completed for "<<first_customer->user->getUsername()<<RESET<<endl;
    }

}