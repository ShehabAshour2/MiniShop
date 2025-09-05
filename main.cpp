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
int main() {

    char choice='1';
    vector<Admin>admins;
    vector<Customer>customers;
    while(choice!='0') {
        system("cls");
        cout<<"if you're a user press 1.\n";
        cout<<"if you're an admin press 2.\n";
        cout<<"To exit press 0.\n";
        choice=getch();
        switch (choice) {
            case '1':
            {system("cls");
                break;
            case '2':
                system("cls");
                break;
            default:
                break;
        }

    }
    system("cls");
    cout<<"Thank you for using MiniShop.\n";
    return 0;
}