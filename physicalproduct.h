#ifndef PHYSICALPRODUCT_H
#define PHYSICALPRODUCT_H
#include "Product.h"
#include <iostream>
using namespace std;

class PhysicalProduct : public Product
{
private:
    int stockQuantity;
    double weight;

public:
    PhysicalProduct(const string &t, const string &d, double p, const string &c, int stock, double w);

    bool reduceStock(int qty);
    void increaseStock(int qty);

    void display(ostream &os) const override;
    string getType() const override;
};
#endif