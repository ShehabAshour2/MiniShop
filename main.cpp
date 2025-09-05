//
// Created by Amr moussa on 9/5/2025.
//

#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

#include "User.cpp"
#include "Admin.cpp"
#include "Customer.cpp"
#include "Product.cpp"
#include "PhysicalProduct.cpp"
#include "DigitalProduct.cpp"
#include "ShoppingCart.cpp"
#include "CartItem.cpp"
#include "Order.cpp"
#include "Inventory.h"
#include "Inventory.cpp"
#include <numeric>

using namespace std;

// Forward declarations of functions to handle menu actions
void customerMenu(Customer *currentCustomer);
//void adminMenu(Admin *currentAdmin);
void displayAllProducts();
// In-memory databases
vector<Admin> admins;
vector<Customer> customers;
Inventory<PhysicalProduct> physicalInventory;
Inventory<DigitalProduct> digitalInventory;
vector<Order> orders;



int main()
{
    // Populate with some initial data for demonstration
    admins.push_back(Admin("admin_user", "admin@shop.com", "adminpass"));
    customers.push_back(Customer("test_customer", "customer@shop.com", "customerpass", "123 Main Street"));

    // Add some initial products to the inventory
    PhysicalProduct p1("Laptop", "A powerful laptop for work and gaming.", 1200.0, "Electronics", 50, 2.5);
    PhysicalProduct p2("Book", "A classic novel.", 15.0, "Books", 200, 0.5);
    DigitalProduct p3("Ebook", "The digital version of a classic.", 10.0, "E-books", 10.5, "PDF");
    DigitalProduct p4("Software", "A utility application.", 50.0, "Software", 250.0, "Executable");

    // Add items to the inventory using their IDs
    physicalInventory.additem(p1.getId(), p1);
    physicalInventory.additem(p2.getId(), p2);
    digitalInventory.additem(p3.getId(), p3);
    digitalInventory.additem(p4.getId(), p4);

    char choice;
    string email, password, name, address;

    while (true)
    {
        system("cls"); // Clear the console screen
        cout << "===========================" << endl;
        cout << "    MiniShop Main Menu" << endl;
        cout << "===========================" << endl;
        cout << "1. Login as Customer" << endl;
        cout << "2. Login as Admin" << endl;
        cout << "3. Sign Up as Customer" << endl;
        cout << "4. Exit" << endl;
        cout << "---------------------------" << endl;
        cout << "Enter your choice: ";

        // Use getch() for direct character input
        while ((choice = getch()) && (choice < '1' || choice > '4'))
            ;

        cout << choice << endl; // Echo the selected character


        switch (choice)
        {
        case '1':
        { // Login as Customer
            system("cls");
            cout << "--- Customer Login ---" << endl;
            cout << "Enter email: ";
            getline(cin, email);
            cout << "Enter password: ";
            getline(cin, password);

            Customer *foundCustomer = nullptr;
            for (auto &customer : customers)
            {
                // Use the getemail() method to check the email
                if (customer.authenticate(password) && customer.getemail() == email)
                {
                    foundCustomer = &customer;
                    break;
                }
            }

            if (foundCustomer)
            {
                // Use the getname() method to access the customer's name
                cout << "\nLogin successful! Welcome, " << foundCustomer->getname() << "." << endl;
                customerMenu(foundCustomer); // Go to the customer-specific menu
            }
            else
            {
                cout << "\nInvalid email or password. Please try again." << endl;
                cout << "\nPress Enter to continue...";
                cin.get();
            }
            break;
        }
        case '2':
        { // Login as Admin
            system("cls");
            cout << "--- Admin Login ---" << endl;
            cout << "Enter ID: ";
            int id;
            cin >> id;
            cout << "Enter password: ";
            getline(cin, password);

            Admin *foundAdmin = nullptr;
            for (auto &admin : admins)
            {
                // Use the getemail() method to check the email
                if (admin.authenticate(password) && admin.getId() == id)
                {
                    foundAdmin = &admin;
                    break;
                }
            }

            if (foundAdmin)
            {
                // Use the getname() method to access the admin's name
                cout << "\nLogin successful! Welcome, " << foundAdmin->getname() << "." << endl;
                //adminMenu(foundAdmin); // Go to the admin-specific menu
            }
            else
            {
                cout << "\nInvalid email or password. Please try again." << endl;
                cout << "\nPress Enter to continue...";
                cin.get();
            }
            break;
        }
        case '3':
        { // Sign Up as Customer
            system("cls");
            cout << "--- Customer Sign Up ---" << endl;

            cout << "Enter your full name: ";
            getline(cin, name);
            cout << "Enter your email: ";
            getline(cin, email);
            cout << "Create a password: ";
            getline(cin, password);
            cout << "Enter your address: ";
            getline(cin, address);

            customers.push_back(Customer(name, email, password, address));
            cout << "\nAccount created successfully! You can now log in." << endl;
            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        case '4':
        { // Exit
            system("cls");
            cout << "Thank you for using MiniShop. Goodbye!" << endl;
            return 0; // Exit the program
        }
        }
    }
    return 0;
}


void displayAllProducts() {
    system("cls");
    cout<<"Physical items:"<<endl;
    physicalInventory.display();
    cout<<endl;
    cout<<"digital items:"<<endl;
    digitalInventory.display();
    cout<<endl;
}


void customerMenu(Customer *currentCustomer)
{
    char choice;
    ShoppingCart customerCart;

    while (true)
    {
        system("cls"); // Clears the console
        cout << "Welcome, " << currentCustomer->getname() << "!" << endl;
        cout << "--- Customer Menu ---" << endl;
        cout << "1. View all products" << endl;
        cout << "2. Add product to cart" << endl;
        cout << "3. View shopping cart" << endl;
        cout << "4. Checkout" << endl;
        cout << "5. View order history" << endl;
        cout << "6. Log out" << endl;
        cout << "Enter your choice: ";

        while ((choice=getch()) && (choice<'1' || choice>'6') );
        cout << choice << endl; // Echo the character pressed

        switch (choice)
        {
        case '1':
        {
            system("cls");
            displayAllProducts();
            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        case '2':
        {
            system("cls");
            int productId, quantity;
            cout << "Enter product ID to add to cart: ";
            cin >> productId;

            cout << "Enter quantity: ";
            cin >> quantity;


            // Try to find the product in both inventories
            PhysicalProduct *physicalProd = physicalInventory.findbyid(productId);
            DigitalProduct *digitalProd = digitalInventory.findbyid(productId);

            if (physicalProd != nullptr)
            {
                customerCart.addItem(physicalProd, quantity);
                cout << "\nAdded " << quantity << " of " << physicalProd->getTitle() << " to cart." << endl;
            }
            else if (digitalProd != nullptr)
            {
                customerCart.addItem(digitalProd, quantity);
                cout << "\nAdded " << quantity << " of " << digitalProd->getTitle() << " to cart." << endl;
            }
            else
            {
                cout << "\nProduct not found." << endl;
            }

            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        case '3':
        {
            system("cls");
            cout << "--- Your Shopping Cart ---" << endl;
            display(customerCart);
            cout<< endl;
            cout << "Total: $" << customerCart.calculateTotal() << endl;
            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        case '4':
        {
            system("cls");
            if (customerCart.calculateTotal() > 0)
            {
                // Create a new order
                Order newOrder(currentCustomer->getId(), customerCart, "2025-09-05");
                orders.push_back(newOrder);
                cout << "Order placed successfully! " << endl;
                cout << "You can view your invoice here: " << endl;
                printInvoice(newOrder);

                // Clear the shopping cart
                ShoppingCart emptyCart;
                customerCart = emptyCart;
            }
            else
            {
                cout << "Your cart is empty. Nothing to checkout." << endl;
            }

            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        case '5':
        {
            system("cls");
            currentCustomer->vieworders();
            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        case '6':
        {
            // Log out
            cout << "\nLogging out. Goodbye!" << endl;
            cout << "\nPress Enter to continue...";
            cin.get();
            return;
        }
        default:
        {
            cout << "\nInvalid choice. Please try again." << endl;
            cout << "\nPress Enter to continue...";
            cin.get();
            break;
        }
        }
    }
}