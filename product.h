#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <iostream>
using namespace std;

class Product
{
protected:
    int id;
    string title, description, category;
    double price;
    static int nextId;
    static double globalDiscount;

public:
    Product(const string &t, const string &d, double p, const string &c);

    virtual void display(ostream &os) const = 0;
    virtual string getType() const = 0;
    double priceafterdiscount() const;

    bool operator==(const Product &other) const { return id == other.id; }
    friend ostream &operator<<(ostream &os, const Product &p);
    string getTitle() const { return title; }
    double getPrice() const { return price; }
};
#endif