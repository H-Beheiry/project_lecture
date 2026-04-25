#ifndef SUPERMARKET_SYSTEM_H
#define SUPERMARKET_SYSTEM_H

#include "..\dataStructures\SortedProducts.h"
#include "..\dataStructures\productTable.h"
#include "..\dataStructures\CustomerLine.h"
#include "..\dataStructures\RestockingSystem.h"
#include "..\dataStructures\opperationStack.h"

#include "..\actors\admin.h"
#include "..\actors\staff.h"
#include "..\actors\customerUser.h"

class SupermarketSystem
{
    private:
        SortedProducts inventoryBST;
        productTable lookupTable;
        CustomerLine checkoutQueue;
        RestockingSystem restockQueue;
        opperationStack globalUndoStack;
    public:
        admin* systemAdmin;
        staff* systemStaff;
        customerUser* activeCustomer;

        SupermarketSystem();
        ~SupermarketSystem();

        void bootUp();
        
        bool adminLogin(string uname, string pass);
        bool staffLogin(string uname, string pass);
        customerUser* customerLogin(string uname, string pass, int id);
};

#endif