#include <iostream>
#include "Product.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"
#include <vector>

#ifndef OOP_WORKSHOP_CARTITEM_H
#define OOP_WORKSHOP_CARTITEM_H

class CartItem
{
public:
    Product *product;
    int quantity;

public:
    CartItem(Product *p = nullptr, int q = 0);
    double subTotal() const;

    int getQuantity() const { return quantity; }
    Product *getProduct() const { return product; }
    ~CartItem();
    friend std::ostream &operator<<(std::ostream &os, const CartItem &item);
};

#endif