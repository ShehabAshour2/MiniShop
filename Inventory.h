
#ifndef OOP_WORKSHOP_INVENTORY_H
#define OOP_WORKSHOP_INVENTORY_H

#include "PhysicalProduct.h"
#include "DigitalProduct.h"
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

template <class T>
class Inventory
{
private:
    unordered_map<int, T> inventory;

public:
    Inventory();

    void additem(int id, T &product);

    void removeitem(int id);

    T *findbyid(int id);

    vector<T> findbytitle(string name);

    void display();
};

#endif