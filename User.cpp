#include "User.h"

int User::useridcounter = 0;

User::User(string n, string e, string p)
{
    userid = ++useridcounter;
    name = n;
    email = e;
    password = p;
}

bool User::authenticate(string &enteredPass)
{
    return password == enteredPass;
}

string User::getname() {
    return name;
}

int User::getId() {
    return userid;
}
ostream &operator<<(ostream &os, User &u)
{
    u.display(os);
    return os;
}