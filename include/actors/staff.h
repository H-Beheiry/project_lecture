#ifndef STAFF_H
#define STAFF_H
#include "..\dataStructures\customerLine.h"
#include "..\dataStructures\productTable.h"
#include "..\dataStructures\RestockingSystem.h"

class staff
{
    public:
        void updateItem(int id, double newPrice, int newQuantity);
        void addItemToRestock(int productID);
        void removeItemFromRestock();
        void displayItemsToRestock();
        void dequeCustomer();
        staff(int id, string pass, string uname, productTable* product_hashmap, CustomerLine* checkout_queue, RestockingSystem* restock_queue);

        string getUsername(){return username;}
        string getPassword(){return password;}
    private:
        string username;
        string password;
        int ID;
        productTable* product_catalog;
        CustomerLine* checkout_line;
        RestockingSystem* restcok_system;
};



#endif