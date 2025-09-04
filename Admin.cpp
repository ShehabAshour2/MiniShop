#include "Admin.h"
#include <iostream>
using namespace std;

Admin::Admin(string n, string e, string p)
    : User(n, e, p) {}

void Admin::addProduct(string product)
{
    cout << "Admin " << name << " added product: " << product << endl;
}

void Admin::removeProduct(string product)
{
    cout << "Admin " << name << " removed product: " << product << endl;
}

void Admin::viewReports()
{
    cout << "Admin " << name << " is viewing system reports..." << endl;
}

void Admin::updateStock(string product, int newQuantity)
{
    cout << "Admin " << name
         << " updated stock of " << product
         << " to " << newQuantity << " items." << endl;
}

void Admin::display(ostream &os)
{
    os << "Admin ID: " << userid << endl;
    os << "Admin Name: " << name << endl;
    os << "Admin Email: " << email << endl;
}

string Admin::gettype()
{
    return "Admin";
}