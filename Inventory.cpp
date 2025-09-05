
#include "Inventory.h"
#include "PhysicalProduct.h"
#include "DigitalProduct.h"
#include <vector>
using namespace std;

template<class T>
Inventory<T>::Inventory() {

}


template <class T>
void Inventory<T>::additem(int id, T &product)
{
    inventory[id] = product;
}

template <class T>
void Inventory<T>::removeitem(int id)
{
    inventory.erase(id);
}

template <class T>
T *Inventory<T>::findbyid(int id)
{
    T* temp= &inventory[id];
    if (temp == nullptr)
        inventory.erase(id);
    return temp;
}

template <class T>
vector<T> Inventory<T>::findbytitle(string name)
{
    vector<T> v;
    for (auto &it : inventory)
    {
        if (it.title == name)
        {
            v.push_back(it);
        }
    }
    return v;
}


template<class T>
void Inventory<T>::display() {
    for (auto &it : inventory) {
        it.second.display();
        cout<<'\n';
    }
}
