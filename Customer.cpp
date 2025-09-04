#include "Customer.h"
#include <iostream>
using namespace std;

Customer::Customer(string n, string e, string p, string add)
    : User(n, e, p)
{
    address = add;
}

void Customer::addtocart(string item)
{
    cout << name << " added this " << item << endl;
}

void Customer::checkout(string order)
{
    orderhistory.push_back(order);
    cout << name << " checked out order: " << order << endl;
}

void Customer::vieworders()
{
    cout << "The order history of " << name << " is:" << endl;
    for (auto order : orderhistory)
    {
        cout << "- " << order << endl;
    }
}

void Customer::display(ostream &os)
{
    os << "Customer id is " << userid << endl;
    os << "Customer name is " << name << endl;
    os << "Customer email is " << email << endl;
    os << "Customer address is " << address << endl;
}

string Customer::gettype()
{
    return "Customer";
}