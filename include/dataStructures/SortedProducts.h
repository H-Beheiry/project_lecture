#ifndef SORTEDPRODUCTS_H
#define SORTEDPRODUCTS_H
#include "..\nodes\product.h"
#include "..\nodes\BSTproduct.h"
#include <string>
using namespace std;

class SortedProducts
{
    private:
        void displayNode(BSTproduct* node);
    public:
        BSTproduct* root;
        void insert(product* new_node);
        void search(int id);
        void displayProducts(BSTproduct* tree_root);

        SortedProducts();
        ~ SortedProducts();
};

#endif