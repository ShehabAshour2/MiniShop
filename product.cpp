#include "Product.h"
#include <iostream>



int Product::nextId = 1;
double Product::globalDiscount = 0.0;

Product::Product(const string &t, const string &d, double p, const string &c)
    : title(t), description(d), price(p), category(c)
{
    id = nextId++;
}

double Product::priceafterdiscount() const
{
    return price * (1 - globalDiscount);
}

ostream &operator<<(ostream &os, const Product &p)
{
    p.display();
    return os;
}
