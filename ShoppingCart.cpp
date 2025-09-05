#include "ShoppingCart.h"
#include "product.h"



ShoppingCart::ShoppingCart(const ShoppingCart &other)
{
    for (const auto &i : other.cartItems)
    {
        cartItems.push_back(i);
    }
}

void ShoppingCart::addItem(Product *item, int quantity)
{
    CartItem temp(item, quantity);
    cartItems.push_back(temp);
}

void ShoppingCart::removeItem(int id)
{
    for (int i = 0; i < cartItems.size(); i++)
    {
        if (cartItems[i].product && cartItems[i].product->id == id)
        {
            cartItems.erase(cartItems.begin() + i);
            break;
        }
    }
}

void ShoppingCart::updateQuantity(int id, int quantity)
{
    for (auto &item : cartItems)
    {
        if (item.product && item.product->id == id)
        {
            item.quantity = quantity;
        }
    }
}

double ShoppingCart::calculateTotal() const
{
    return accumulate(cartItems.begin(), cartItems.end(), 0.0,
                      [](double sum, const CartItem &item)
                      { return sum + item.subTotal(); });
}

void ShoppingCart::sortByPrice()
{
    sort(cartItems.begin(), cartItems.end(),
         [](const CartItem &a, const CartItem &b)
         { return a.subTotal() > b.subTotal(); });
}

ShoppingCart ShoppingCart::operator+(const ShoppingCart &other) const
{
    ShoppingCart temp(*this);
    for (const auto &i : other.cartItems)
    {
        temp.cartItems.push_back(i);
    }
    return temp;
}

ostream &operator<<(ostream &os, const ShoppingCart &cart)
{
    for (const auto &item : cart.cartItems)
    {
        if (item.product)
            os << item.product->name << " x" << item.quantity << " = " << item.subTotal() << endl;
    }
    os << "Total: " << cart.calculateTotal() << endl;
    return os;
}
