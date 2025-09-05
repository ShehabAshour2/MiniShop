#include "PhysicalProduct.h"

PhysicalProduct::PhysicalProduct() : Product("", "", -1 , "") {
    stockQuantity=-1;
    weight=-1;

}
PhysicalProduct::PhysicalProduct(const string &t, const string &d, double p, const string &c, int stock, double w)
    : Product(t, d, p, c), stockQuantity(stock), weight(w) {}

bool PhysicalProduct::reduceStock(int qty)
{
    if (qty <= stockQuantity)
    {
        stockQuantity -= qty;
        return true;
    }
    return false;
}

void PhysicalProduct::increaseStock(int qty)
{
    stockQuantity += qty;
}

void PhysicalProduct::display() const
{
    cout << "[ID: " << id << "] " << title
       << " | category: " << category
       << " | Price: " << price
       << " | After Discount: " << priceafterdiscount()
       << " | Stock: " << stockQuantity
       << " | Weight: " << weight << "kg";
}

string PhysicalProduct::getType() const
{
    return "Physical";
}