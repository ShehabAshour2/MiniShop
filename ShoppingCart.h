#ifndef OOP_WORKSHOP_SHOPPINGCART_H
#define OOP_WORKSHOP_SHOPPINGCART_H
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include "CartItem.h"
#include "product.h"
#include "digitalproduct.h"
#include "physicalproduct.h"
using namespace std;



class ShoppingCart
{
private:
    vector<CartItem> cartItems;

public:
    ShoppingCart() {}
    ShoppingCart(const ShoppingCart &other);

    void addItem(Product *item, int quantity);
    void removeItem(int id);
    void updateQuantity(int id, int quantity);
    double calculateTotal() const;
    void sortByPrice();

    friend ostream &operator<<(ostream &os, const ShoppingCart &cart);
    ShoppingCart operator+(const ShoppingCart &other) const;
};

#endif
