#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <vector>
#include <string>
using namespace std;

class Customer : public User
{
private:
    string address;
    vector<string> orderhistory;

public:
    Customer(string n, string e, string p, string add);

    void addtocart(string item);
    void checkout(string order);
    void vieworders();

    void display(ostream &os) override;
    string gettype() override;
};

#endif