#include <iostream>
#include <string>
#include "../include/systemUtils/SupermarketSystem.h"
#include "../include/systemUtils/ConsoleUtils.h"

using namespace std;

int main()
{
    SupermarketSystem ufeMarket;
    ufeMarket.bootUp(); 
    int portalChoice;
    string inputUname, inputPass;

    while (true) {
        clearScreen();
        printHeader();
        
        cout 
        <<endl
        <<BOLD<<YELLOW<<"[ WELCOME TO UFE MARKET PLEASE SELECT YOUR PORTAL ]"<<RESET<<endl
        <<GREEN<< "[1]"<<RESET <<" Admin Login"     <<endl
        <<GREEN<< "[2]"<<RESET <<" Staff Login"     <<endl
        <<GREEN<< "[3]"<<RESET <<" Customer Login"  <<endl
        <<GREEN<< "[4]"<<RESET <<" Shut Down System"<<endl
        << "Select Portal: ";
        cin >> portalChoice;

        // admin portal
        if (portalChoice == 1)
        {
            clearScreen();
            cout<<BOLD<<RED<<"[ ADMIN AUTHENTICATION ]"<<RESET<<endl;
            cout<<"Username: "; cin>> inputUname;
            cout<<"Password: "; cin>> inputPass;

            if (inputUname == "admin" && inputPass == "admin123")
            {
                int adminChoice;
                while (true)
                {
                    clearScreen();
                    printHeader();
                    cout 
                    <<endl
                    <<BOLD<<YELLOW<<"[ WELCOME ADMIN PLEASE SELECT YOUR ACTION ]"<<RESET<<endl
                    <<GREEN<< "[1]"<<RESET <<" Add New Product"                    <<endl
                    <<GREEN<< "[2]"<<RESET <<" Delete Existing Product"            <<endl
                    <<GREEN<< "[3]"<<RESET <<" Update Product Price"               <<endl
                    <<GREEN<< "[4]"<<RESET <<" Undo Last Action"                   <<endl
                    <<GREEN<< "[5]"<<RESET <<" View Sorted Inventory"              <<endl
                    <<GREEN<< "[6]"<<RESET <<" View Restock Requests"              <<endl
                    <<GREEN<< "[7]"<<RESET <<" View Last Operation"                <<endl
                    <<GREEN<< "[8]"<<RESET <<" Clear Operation History"            <<endl
                    <<GREEN<< "[9]"<<RESET <<" Logout"                             <<endl
                    << "Select Action: ";
                    cin>> adminChoice;
                    if (adminChoice == 1)
                    {
                        clearScreen();
                        printHeader();
                        int id, qty; 
                        double price; 
                        string name;
                        cout<<"Enter ID: "; 
                        cin>> id;
                        cout<<endl<<"Enter Price: ";
                        cin>> price;
                        cout<<endl<<"Enter Quantity: ";
                        cin>> qty;
                        cout<<endl<< "Enter Name: ";
                        cin>> name;
                        ufeMarket.systemAdmin->addNewProduct(id, name, price, qty);
                        pauseConsole();
                    }
                    else if (adminChoice == 2)
                    {
                        clearScreen();
                        printHeader();
                        int id; 
                        cout<<"Enter Product ID to delete: "; 
                        cin>> id;
                        ufeMarket.systemAdmin->deleteProduct(id);
                        pauseConsole();
                    }
                    else if (adminChoice == 3)
                    {
                        clearScreen();
                        printHeader();
                        int id; 
                        double price;
                        cout<<"Enter Product ID: "; 
                        cin>> id;
                        cout<<endl<<"Enter New Price: ";
                        cin>> price;
                        ufeMarket.systemAdmin->updateProductPrice(id, price);
                        pauseConsole();
                    }
                    else if (adminChoice == 4)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemAdmin->undoLastAction();
                        pauseConsole();
                    }
                    else if (adminChoice == 5)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemAdmin->viewSortedInventory();
                        pauseConsole();
                    }
                    else if (adminChoice == 6)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemAdmin->viewRestockRequests();
                        pauseConsole();
                    }
                    else if (adminChoice == 7)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemAdmin->seeLastOperation();
                        pauseConsole();
                    }
                    else if (adminChoice == 8)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemAdmin->clearOperationHistory();
                        pauseConsole();
                    }
                    else if (adminChoice == 9)
                    {
                        break;
                    }
                    else
                    {
                        clearScreen();
                        printHeader();
                        cout<<RED<<"Invalid choice, please try again."<<RESET<<endl;
                        pauseConsole();
                    }
                }
            }
            else
            {
                clearScreen();
                printHeader();
                cout << RED << "Authentication Failed! Invalid credentials." << RESET << endl;
                pauseConsole();
            }
        }

        // staff portal
        else if (portalChoice == 2)
        {
            clearScreen();
            cout<<BOLD<<RED<<"[ STAFF AUTHENTICATION ]"<<RESET<<endl;
            cout<<"Username: "; cin>> inputUname;
            cout<<"Password: "; cin>> inputPass;

            if (inputUname == "staff" && inputPass == "staff123")
            {
                int staffChoice;
                while (true)
                {
                    clearScreen();
                    printHeader();
                    cout
                    <<BOLD<<YELLOW<<"[ WELCOME STAFF PLEASE SELECT YOUR ACTION ]"<<RESET<<endl
                    <<GREEN<< "[1]"<<RESET <<" Update Existing Item"               <<endl
                    <<GREEN<< "[2]"<<RESET <<" Add Item To Restock List"           <<endl
                    <<GREEN<< "[3]"<<RESET <<" Restock Item"                       <<endl
                    <<GREEN<< "[4]"<<RESET <<" Display Items To Be Restock"        <<endl
                    <<GREEN<< "[5]"<<RESET <<" Checkout Customer"                  <<endl
                    <<GREEN<< "[6]"<<RESET <<" Logout"                             <<endl
                    <<"Select Action: ";
                    cin>> staffChoice;

                    if (staffChoice == 1)
                    {
                        clearScreen();
                        printHeader();
                        int newQTY, id;
                        double newPrice;
                        cout<<"Enter Product ID to update: "; cin>> id;
                        cout<<endl<<"Enter New Price: "; cin>> newPrice;
                        cout<<endl<<"Enter New Quantity: "; cin>> newQTY;
                        ufeMarket.systemStaff->updateItem(id, newPrice, newQTY);
                        pauseConsole();
                    }
                    else if (staffChoice == 2)
                    {
                        clearScreen();
                        printHeader();
                        int ID;
                        cout<<"Enter Product ID to add to restock list: "; cin>> ID;
                        ufeMarket.systemStaff->addItemToRestock(ID);
                        pauseConsole();
                    }
                    else if (staffChoice == 3)
                    {
                        clearScreen();
                        printHeader();
                        int newQTY;
                        cout<<"Enter product new quantity: "; cin>> newQTY;
                        ufeMarket.systemStaff->removeItemFromRestock(newQTY);
                        pauseConsole();
                    }
                    else if (staffChoice == 4)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemStaff->displayItemsToRestock();
                        pauseConsole();
                    }
                    else if (staffChoice == 5)
                    {
                        clearScreen();
                        printHeader();
                        ufeMarket.systemStaff->dequeCustomer();
                        pauseConsole();
                    }
                    else if (staffChoice == 6)
                    {
                        break;
                    }
                    else
                    {
                        clearScreen();
                        printHeader();
                        cout<<RED<<"Invalid choice, please try again."<<RESET<<endl;
                        pauseConsole();
                    }
                }
            } 
            else
            {
                cout << RED << "Authentication Failed! Invalid credentials." << RESET << endl;
                pauseConsole();
            }
        }

        // customer portal
        else if (portalChoice == 3)
        {
            clearScreen();
            cout<<BOLD<<RED<<"[ CUSTOMER AUTHENTICATION ]"<<RESET<<endl;
            cout<<"Username: "; cin>> inputUname;
            cout<<"Password: "; cin>> inputPass;
            customerUser* currentCustomer = ufeMarket.customerLogin(inputUname, inputPass, rand() % 1000 + 1);
            
            int custChoice;
            while (true) 
            {
                    clearScreen();
                    printHeader();
                    cout
                    <<BOLD<<YELLOW<<"[ WELCOME STAFF PLEASE SELECT YOUR ACTION ]"<<RESET<<endl
                    <<GREEN<< "[1]"<<RESET <<" Browse Items"               <<endl
                    <<GREEN<< "[2]"<<RESET <<" Add Item To cart"           <<endl
                    <<GREEN<< "[3]"<<RESET <<" Remove Item From Cart"      <<endl
                    <<GREEN<< "[4]"<<RESET <<" Display My Cart"            <<endl
                    <<GREEN<< "[5]"<<RESET <<" Queue To Checkout"          <<endl
                    <<GREEN<< "[6]"<<RESET <<" Logout"                     <<endl
                    <<"Select Action: ";
                    cin>> custChoice;

                if (custChoice == 1)
                {
                    clearScreen();
                    printHeader();
                    currentCustomer->browseItems();
                    pauseConsole();
                }
                else if (custChoice == 2) 
                {
                    clearScreen();
                    printHeader();
                    int id, qty;
                    cout<< "Enter Product ID: ";            cin>> id;
                    cout<<endl<<"Enter Quantity Needed: ";  cin>> qty;
                    currentCustomer->addTocart(id, qty);
                    pauseConsole();
                }
                else if (custChoice == 3) {
                    clearScreen();
                    printHeader();
                    int id; 
                    cout<< "Enter Product ID to remove: "; 
                    cin >>id;
                    currentCustomer->removeFromCart(id);
                    pauseConsole();
                }
                else if (custChoice == 4) 
                {
                    clearScreen();
                    printHeader();
                    currentCustomer->displayCart();
                    pauseConsole();
                }
                else if (custChoice == 5)
                {
                    clearScreen();
                    printHeader();
                    currentCustomer->queueToCheckout();
                    cout << GREEN << "You are now in line. A staff member will process your checkout shortly!" << RESET << endl;
                    pauseConsole();
                    break;
                }
                else if (custChoice == 6)
                {
                    break;
                }
                else
                {
                    clearScreen();
                    printHeader();
                    cout<<RED<<"Invalid choice, please try again."<<RESET<<endl;
                    pauseConsole();
                }
        }
    }
        else if (portalChoice == 4) 
        {
            cout<<GREEN<<"Initiating system shutdown. Goodbye."<<RESET<<endl;
            break;
        }
        else
        {
            clearScreen();
            printHeader();
            cout<<RED<<"Invalid choice, please try again."<<RESET<<endl;
            pauseConsole();
        }
    }

    return 0;
}