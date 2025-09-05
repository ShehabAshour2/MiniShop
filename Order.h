#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CartItem.h"
#include "ShoppingCart.h"
using namespace std;

class Order
{
private:
    int orderId;
    int customerId;
    double totalAmount;
    string status;
    string date;

    static int nextOrderId;

    ShoppingCart purchasedItems;

public:
    // Constructor
    Order(int custId, ShoppingCart &items, const string &orderDate);

    // Methods
    void updateStatus(const string &newStatus);

    // Operator overloading
    friend ostream &operator<<(ostream &os, const Order &o);
    friend void printInvoice(const Order &o);
};
