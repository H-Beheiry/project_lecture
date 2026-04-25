#include "../../include/actors/admin.h"
#include "../../include/systemUtils/ConsoleUtils.h"

admin::admin(int id, string uname, string pass, SortedProducts* tree, productTable* catalog, opperationStack* stack, RestockingSystem* restock)
{
    ID= id;
    username= uname;
    password= pass;
    product_tree= tree;
    product_catalog= catalog;
    undo_stack= stack;
    restock_line= restock;
}

void admin::addNewProduct(int id, string name, double price, int qty)
{
    product* p= new product(id, name, price, qty);
    product_tree   ->insert(p);
    product_catalog->insert(p);
    undo_stack->push("ADD_PROD", p);
    cout<<GREEN<<"Product added to system !"<<RESET<<endl;
}

void admin::deleteProduct(int id)
{
    product* p= product_catalog->search(id);
    if (p!=NULL)
    {
        undo_stack     ->push("DEL_PROD", p);
        product_tree   ->remove(id);
        product_catalog->remove(id);
        cout<<YELLOW<< "Product removed from active catalog."<<RESET<<endl;
    }
    else
    {
        cout<<RED<<"Product Not Found cannot delete..."<<RESET<<endl;
    }
}

void admin::updateProductPrice(int id, double newPrice)
{
    product* p= product_catalog->search(id);
    if (p!=NULL)
    {
        undo_stack->push("UPD_PRICE", p, p->price);
        p->price= newPrice;
        cout<<GREEN<<"Price updated successfully."<<RESET<<endl;
    }
    else 
    {
        cout<<RED<<"Product not found cannot update price..."<<RESET<<endl;
    }
}

void admin::undoLastAction()
{
    opperation* op= undo_stack->pop();
    if (op==NULL)
    {
        cout<<RED<<"Nothing to undo!"<<RESET<<endl;
        return;
    }
    if (op->opp=="ADD_PROD")
    {
        product_tree->remove(op->productPtr->productID);
        product_catalog->remove(op->productPtr->productID);
    } 
    else if (op->opp=="DEL_PROD")
    {
        product_tree->insert(op->productPtr);
        product_catalog->insert(op->productPtr);
    } 
    else if (op->opp=="UPD_PRICE")
    {
        op->productPtr->price= op->oldPrice;
    }

    cout<<GREEN<<"Undo successful: "<<op->opp<<RESET<<endl;
    delete op; 
}

void admin::viewSortedInventory()
{
    product_tree->displayProducts(product_tree->root);
}

void admin::viewRestockRequests()
{
    restock_line->displayRestockQueue();
}

void admin::seeLastOperation()
{
    cout<<GREEN<<"Last Opperation: "<<RESET<<endl;
    undo_stack->peek();
}

void admin::clearOperationHistory()
{
    undo_stack->clear();
    cout<<GREEN<<"History cleared successfully"<<RESET<<endl;
}