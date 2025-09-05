//
// Created by Amr moussa on 9/5/2025.
//
#include <iostream>
#include <conio.h>
#include <vector>
#include "User.h"
#include "Admin.h"
#include "Customer.h"
#include "Order.h"
#include "product.h"
#include "physicalproduct.h"
#include "digitalproduct.h"
#include "Inventory.h"
#include "CartItem.h"
#include "ShoppingCart.h"

using namespace std;
#ifndef OOP_WORKSHOP_UTILITIES_H
#define OOP_WORKSHOP_UTILITIES_H


class utilities {
public:
    bool utilities::intin(int& n);
    void admin(vector<Admin> &);
    void user(vector<User> &);
};


#endif //OOP_WORKSHOP_UTILITIES_H