#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <string>
using namespace std;

class Admin : public User
{
public:
    Admin(string n, string e, string p);

    void addProduct(string product);
    void removeProduct(string product);
    void viewReports();
    void updateStock(string product, int newQuantity);

    void display(ostream &os) override;
    string gettype() override;
};

#endif