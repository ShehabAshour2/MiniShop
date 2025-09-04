#ifndef USER_H
#define USER_H
#include <string>
#include <iostream>
using namespace std;
class User
{
protected:
    int userid;
    string name;
    string email;
    string password;

public:
    static int useridcounter;

    User(string n, string e, string p);

    virtual void display(ostream &os) = 0;
    virtual string gettype() = 0;

    bool authenticate(string &enteredPass);

    friend ostream &operator<<(ostream &os, User &u);
};

#endif 