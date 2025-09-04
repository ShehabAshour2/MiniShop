#include "DigitalProduct.h"
#include <vector>

DigitalProduct::DigitalProduct(const string &t, const string &d, double p, const string &c, double size, const string &f)
    : Product(t, d, p, c), fileSizeMB(size), format(f) {}

void DigitalProduct::display(ostream &os) const
{
    os << "[ID: " << id << "] " << title
       << " | " << category
       << " | Price: " << price
       << " | After Discount: " << priceafterdiscount()
       << " | File Size: " << fileSizeMB << "MB"
       << " | Format: " << format;
}

string DigitalProduct::getType() const
{
    return "Digital";
}
