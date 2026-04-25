#ifndef ADMIN_H
#define ADMIN_H

#include <string>
#include "..\dataStructures\SortedProducts.h"
#include "..\dataStructures\ProductTable.h"
#include "..\dataStructures\opperationStack.h"
#include "..\dataStructures\RestockingSystem.h"
using namespace std;

class admin {
private:
    string username;
    string password;
    int ID;

    SortedProducts* product_tree;
    productTable* product_catalog;
    opperationStack* undo_stack;
    RestockingSystem* restock_line;

public:
    admin(int id, string uname, string pass, SortedProducts* tree, productTable* catalog, opperationStack* stack, RestockingSystem* restock);

    void addNewProduct(int id, string name, double price, int qty);
    void deleteProduct(int id);
    void updateProductPrice(int id, double newPrice);
    void undoLastAction();
    void viewSortedInventory();
    void viewRestockRequests();
    void seeLastOperation();
    void clearOperationHistory();
};

#endif