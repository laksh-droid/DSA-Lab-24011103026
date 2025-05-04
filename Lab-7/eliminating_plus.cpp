//prcessing the string such that '+' and the character to the left of '+' are eleminated
#include "char_stack.h"

//function declarations
string processing(string);

//45fgd+++ab+c
int main() {
    string input;
    string output;

    cout << "Enter the string: ";
    cin >> input;

    output = processing(input);
    cout << "String after proccessing: " << output << endl;
}

//the function that processes the string according ot the given conditions
string processing(string str) {
    node stk1;
    node stk2;
    char c;
    string out;
    int i;

    for (char ch : str) {
        stk1.push(ch);
    }

    while (!stk1.empty()) {
        i = 0;
        if (stk1.peek() == '+') {
            while (stk1.peek() == '+' && !stk1.empty()) {
                stk1.pop();
                i++;
            }
            int j = 0;
            while (j < i) {
                if (stk1.empty()) {
                    break;
                }
                stk1.pop();
                j++;
            }
        }
        
        else {
            c = stk1.pop();
            stk2.push(c);
        }
    }


    while (!stk2.empty()) {
        c = stk2.pop();
        out = out + c;
    }

    return out;
}