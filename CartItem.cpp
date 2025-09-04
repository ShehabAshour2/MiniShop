//
// Created by Amr moussa on 8/29/2025.
//
#include <iostream>
#include "Product.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"
#include "CartItem.h"
#include <vector>

CartItem::CartItem(Product *product, int quantity)
{
    this->product = product;
    this->quantity = quantity;
}

double CartItem::subTotal() const
{
    return product->priceafterdiscount() * quantity;
}

CartItem::~CartItem()
{
    product = NULL;
}
