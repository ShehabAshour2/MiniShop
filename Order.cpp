#include "Order.h"
#include <iostream>

#include "ShoppingCart.h"

using namespace std;
int Order::nextOrderId = 1;

Order::Order(int custId, const ShoppingCart &items, const string &orderDate)
    : customerId(custId), purchasedItems(items), date(orderDate), status("Pending")
{
    orderId = nextOrderId++;
    totalAmount = 0.0;
    for (auto &item : purchasedItems)
    {
        totalAmount += item.subTotal();
    }
}

void Order::updateStatus(const string &newStatus)
{
    status = newStatus;
}

ostream & ShoppingCart::operator<<(ostream &os, const ShoppingCart &sc) {
    for (auto &item : sc.cartItems)os<<item<<" - ";
    return os;
}

ostream &operator<<(ostream &os, const Order &o)
{
    os << "Order ID: " << o.orderId
       << "\nCustomer ID: " << o.customerId
       << "\nDate: " << o.date
       << "\nStatus: " << o.status
       << "\nTotal: " << o.totalAmount
       << "\nItems:\n";

    os << o.purchasedItems << endl;
    return os;
}

void printInvoice(const Order &o)
{
    cout << "===== INVOICE =====\n";
    cout << o;
    cout << "===================\n";
}
