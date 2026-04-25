// Our BST is sorted by ProductID

#include "..\..\include\dataStructures\SortedProducts.h"
#include "..\..\include\systemUtils\ConsoleUtils.h"
#include <iostream>
#include <string>
using namespace std;

SortedProducts::SortedProducts()
{
    root= NULL;
}

void SortedProducts::insert(product* p)
{
    BSTproduct* trail   = NULL;
    BSTproduct* curr    = root;
    BSTproduct* new_node= new BSTproduct(p);
    if (root==NULL)
    {
        root= new_node;
    }
    else
    {
        while (curr!=NULL)
        {
            if (new_node->data->productID == curr->data->productID)
            {
                cout<<RED<<"Product cannot have an already taken ID"<<RESET<<endl;
                return;
            }
            else if (new_node->data->productID < curr->data->productID)
            {
                trail= curr;
                curr = curr->lchild;
            }
            else if (new_node->data->productID > curr->data->productID)
            {
                trail= curr;
                curr = curr->rchild;
            }
        }
        if (trail->data->productID > new_node->data->productID)
        {
            curr= new_node;
            trail->lchild= curr;
        }
        else 
        {
            curr= new_node;
            trail->rchild= curr;
        }
        cout<<GREEN<<"Product inserted successfully !"<<RESET<<endl;
    }
}


void SortedProducts::search(int id)
{
    if (root==NULL)
    {
        cout<<RED<<"Cannot search an empty product backlog"<<RESET<<endl;
        return;
    }

    BSTproduct* curr= root;

    while (curr!=NULL)
    {
        if (curr->data->productID==id)
        {
            displayNode(curr);
            return;
        }
        else if (curr->data->productID>id)
        {
            curr= curr->lchild;
        }
        else
        {
            curr= curr->rchild;
        }
    }
    cout<<RED<<"Product Not found try again....."<<RESET<<endl;
}

void SortedProducts::displayNode(BSTproduct* node)
{
    cout
    <<GREEN<<"Product with ID: "<<node->data->productID<<RESET<<endl
    <<BLUE<<"============================================="<<RESET<<endl
    <<WHITE
    <<"Name:      "<<node->data->name<<endl
    <<"Price:     "<<node->data->price<<endl
    <<"Quantity:  "<<node->data->quantity<<endl
    <<RESET
    <<RED<<"============================================="<<RESET<<endl;
}

void SortedProducts::displayProducts(BSTproduct* tree_root)
{
    if (root==NULL)
    {
        return;
    }
    else
    {
        displayProducts(tree_root->lchild);
        displayNode(tree_root);
        displayProducts(tree_root->rchild);
    }
}