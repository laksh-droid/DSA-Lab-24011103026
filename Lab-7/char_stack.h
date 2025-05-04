//Implementation of stack ADT using singly linked list
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class node {
    private:
        char data;
        struct node *next;
        struct node *head;
    
    public:
        node() {
            head = NULL;
        }

        void push(char);
        char pop();
        char peek();

        void print();
        bool empty();
        bool empty2();


};

void node::push(char x) {
    struct node* newnode = new node;
    newnode -> data = x;
    newnode -> next = NULL;
    
    if (head == NULL) {
        head = newnode;
        return;
    }

    struct node* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }
    temp -> next = newnode;

}

char node::pop() {
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

    struct node* temp = head;
    for (;temp -> next -> next != NULL; temp = temp -> next) {

    }

    elem = temp -> next -> data;
    temp -> next = NULL;

    return elem; 
}

char node::peek() {
    struct node* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }

    return temp -> data;
}

void node::print() {
    struct node *temp = head;
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
bool node::empty() {
    return head == NULL;
}

bool node::empty2() {
    return head->next == NULL;
}
