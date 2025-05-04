//program accepts an infix expression converts it into postfix and evaluates the postfix expression
#include "stack.h"
#include "float_stack.h"
#include <string>
#include <cctype>
using namespace std;

//function definitions
List get_infix();
List in_to_post(List);
float postfix_eval(List);

//helper functions
int len(string);
bool is_operator(string);
int precedence(string);
bool is_digit(string);

//1/2+3-4*9
int main() {
    List input, output, post;
    int choice = 0;
    int ans;
    string c;

    printf("MENU\n1 - Get Infix\n2 - Convert Infix to Postfix\n3 - Evaluate Postfix\n4 - Exit \n");
    while (choice != 4) {
        cout << "\n\nEnter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter your expression element by element. When the expression is done enter 'q' to continue:\n";
                input = get_infix();
                break;
            case 2:
                cout << "The Equivalent POSTFIX Expression: ";
                output = in_to_post(input);
                output.print();
                cout << endl;
                break;
            case 3:
                while (!output.empty()) {
                    c = output.pop();
                    post.push(c);
                }
                cout << "Evaluation of the postfix expression gives " << postfix_eval(post);
                break;
            case 4:
                cout << "exiting...\n";
                break;
            default:
                cout << "Invalid choice. Enter again\n";
        }
    }
    return 0;
}

//Takes input from the user for infix expression and stores it efficiently in a stack and returns the stack
List get_infix() {
    List input, infix;
    string c, prev;

    cin >> c;
    while (c != "q") {
        // if (!(is_digit(c)) || !(is_operator(c)) || (is_digit(prev) == is_digit(c)) || (is_operator(prev) == is_operator(c))) {
        //     cout << "Invalid Expression\n";
        //     break;
        // }

        input.push(c);
        cin >> c;
        prev = c;
    }
    cout << "\nThe infix expression obtained: ";
        input.print();
    while (!input.empty()) {
        c = input.pop();
        infix.push(c);
    }
    return infix;
}

//Accepts an infix expression in the form of a stack and converts it into a postfix expression and returns the postfix stack
List in_to_post(List input) {
    List operators;
    List output;

    int p = -1;
    string a, top;
    while(input.empty() != true) {
        top = input.pop();
        if (is_operator(top)) {
            if (precedence(top) < p) {
                p = precedence(top);
                while(true) {
                    a = operators.pop();
                    output.push(a);
                    if (precedence(a) <= p) {
                        break;
                    }
                    if (operators.empty()) {
                        break;
                    }
                }
                operators.push(top);
            }
            else if (p == precedence(top)) {
                a = operators.pop();
                output.push(a);
                operators.push(top);
            }
            else if (precedence(top) > p) {
                operators.push(top);
                p = precedence(top);
            }
            else {
                continue;
            }
        }
        else {
            output.push(top);
        }
    }
    while (!operators.empty()) {
        a = operators.pop();
        output.push(a);
    }
    return output;

}

//Accepts a postfix expression in the form of a stackand evaluates and returns the answer as float
float postfix_eval(List input) {
    string top;
    node evaluate;
    float ans;
    float val1, val2;
    while (!input.empty()) {
        top = input.pop();
        if (is_digit(top)) {
            evaluate.push(stoi(top));
        }
        else if (is_operator(top)) {
            val2 = evaluate.pop();
            val1 = evaluate.pop();
            switch (top[0]) {
                case '+': evaluate.push(val1 + val2); break;
                case '-': evaluate.push(val1 - val2); break;
                case '*': evaluate.push(val1 * val2); break;
                case '/': evaluate.push(val1 / val2); break;
                case '%': evaluate.push((int)val1 % (int)val2); break;
            }
        }
        else {
            continue;
        }
    }

    return evaluate.pop();
}

//Checks if the string contains only digits
bool is_digit(string str) {
    for (char c: str) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

//returns the length of the string
int len(string str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    
    return i;
}

//returns the precedence of the operator
int precedence(string opr) {
    if (opr == "*" || opr == "/" || opr == "%") {
        return 2;
    } 
    if (opr == "+" || opr == "-") {
        return 1;
    }
    if (opr == "(") {
        return 0;
    }
    return -1;
}

//checks if the operator is valid
bool is_operator(string c) {
    std::string operators[] = {"+", "-", "*", "/", "%"};
    for (const std::string& op : operators) {
        if (c == op) {
            return true;
        }
    }
    return false;
}
