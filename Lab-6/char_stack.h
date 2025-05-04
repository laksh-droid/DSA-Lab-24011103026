//Implementation of stack ADT using singly linked list
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class Stack {
    private:
        char data;
        struct Stack *next;
        struct Stack *head;
    
    public:
        Stack() {
            head = NULL;
        }

        void push(char);
        char pop();
        char peek();

        void print();
        bool empty();
        bool empty2();


};

void Stack::push(char x) {
    struct Stack* newnode = new Stack;
    newnode -> data = x;
    newnode -> next = NULL;
    
    if (head == NULL) {
        head = newnode;
        return;
    }

    struct Stack* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }
    temp -> next = newnode;

}

char Stack::pop() {
    if (head == NULL) {
        printf("UnderFlow Error: Stack is Empty.\n");
        return 0;
    }

    char elem;
    if (head -> next == NULL) {
        elem = head -> data;
        head = NULL;
        return elem;
    }

    struct Stack* temp = head;
    for (;temp -> next -> next != NULL; temp = temp -> next) {

    }

    elem = temp -> next -> data;
    temp -> next = NULL;

    return elem; 
}

char Stack::peek() {
    struct Stack* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }

    return temp -> data;
}

void Stack::print() {
    struct Stack *temp = head;
    if (temp == NULL) {
        printf("head = NULL\n");
        return;
    }

    //printf("head -> ");
    for (; temp -> next != NULL; temp = temp -> next) {
        cout << temp -> data << " ";
    }
    cout << temp -> data << "\n";
}

#include <stdbool.h>
bool Stack::empty() {
    return head == NULL;
}

bool Stack::empty2() {
    return head->next == NULL;
}
