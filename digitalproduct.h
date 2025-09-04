#ifndef DIGITALPRODUCT_H
#define DIGITALPRODUCT_H
#include "Product.h"

#include <iostream>
using namespace std;

class DigitalProduct : public Product
{
private:
    double fileSizeMB;
    string format;

public:
    DigitalProduct(const string &t, const string &d, double p, const string &c, double size, const string &f);

    void display(ostream &os) const override;
    string getType() const override;
};
#endif