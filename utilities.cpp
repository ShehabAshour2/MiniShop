//
// Created by Amr moussa on 9/5/2025.
//

#include "utilities.h"

bool utilities::intin(int& n) {
    n = 0;
    string s;
    getline(cin, s);
    for (char c : s) {
        if (!(c >= '0' && c <= '9')) {
            return 1; // Returns true if a non-digit character is found
        } else {
            // Check for potential integer overflow
            if (n * 10 >= 1e9) {
                cout << "The number is too big.\n";
                system("pause");
                return 1;
            }

            n *= 10;
            n += c - '0'; // Convert character to integer and add to the number
        }
    }
    return 0; // Returns false if input is a valid integer
}

void utilities::admin(vector<Admin> &) {
    int id;
    string s="Please enter your ID: ";

}
