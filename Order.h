#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "CartItem.h"
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

    vector<CartItem> purchasedItems;

public:
    // Constructor
    Order(int custId, const vector<CartItem> &items, const string &orderDate);

    // Methods
    void updateStatus(const string &newStatus);

    // Operator overloading
    friend ostream &operator<<(ostream &os, const Order &o);
    friend void printInvoice(const Order &o);
};
