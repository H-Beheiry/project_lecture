#include "../../include/systemUtils/SupermarketSystem.h"

SupermarketSystem::SupermarketSystem()
{
    systemAdmin= new admin(1, "admin", "admin123", &inventoryBST, &lookupTable, &globalUndoStack, &restockQueue);
    systemStaff= new staff(2, "staff123", "staff", &lookupTable, &checkoutQueue, &restockQueue);
    activeCustomer= NULL;
}

void SupermarketSystem::bootUp()
{
    // Produce
    systemAdmin->addNewProduct(1001, "Organic Apples", 1.50, 50);
    systemAdmin->addNewProduct(1002, "Bananas", 0.75, 100);
    systemAdmin->addNewProduct(1003, "Avocados", 2.00, 30);
    
    // Dairy & Eggs
    systemAdmin->addNewProduct(2001, "Whole Milk 1L", 3.20, 20);
    systemAdmin->addNewProduct(2002, "Cheddar Cheese", 4.50, 15);
    systemAdmin->addNewProduct(2003, "Free-Range Eggs", 5.00, 40);

    // Bakery
    systemAdmin->addNewProduct(3001, "Sourdough Bread", 3.50, 10);
    systemAdmin->addNewProduct(3002, "Croissants", 1.20, 25);

    // Pantry
    systemAdmin->addNewProduct(4001, "Olive Oil", 8.00, 12);
    systemAdmin->addNewProduct(4002, "Pasta 500g", 1.10, 60);
    systemAdmin->addNewProduct(4003, "Tomato Sauce", 2.30, 45);
}

customerUser* SupermarketSystem::customerLogin(string uname, string pass, int id) 
{
    activeCustomer= new customerUser(uname, pass, id, &lookupTable, &inventoryBST, &checkoutQueue);
    return activeCustomer;
}

SupermarketSystem::~SupermarketSystem() {
    delete systemAdmin;
    delete systemStaff;
    if (activeCustomer != nullptr) delete activeCustomer;
}