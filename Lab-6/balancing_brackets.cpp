#include "char_stack.h"

#include <iostream>
#include <string>
using namespace std;


// Function to check for balanced round brackets
int bracket_check(string str) {
    Stack stk;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            stk.push('(');
        } else if (str[i] == ')') {
            if (stk.empty()) return 0;
            stk.pop();
        }
    }
    return stk.empty(); // if empty after traversal, balanced
}

int main() {
    string str;
    int choice = 20;

    cout << "MENU\n1 - Check Balance\n2 - Exit\n";
    while (choice != 2) {
        cout << "\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter a string with round brackets: ";
                cin >> str;

                if (bracket_check(str)) {
                    cout << "The brackets are balanced\n";
                } else {
                    cout << "The brackets are NOT balanced\n";
                }
                break;

            case 2:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid option. Enter again.\n";
                break;
        }
    }

    return 0;
}