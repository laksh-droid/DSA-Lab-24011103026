//Implementation of stack ADT using singly linked list
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class List {
    private:
        string data;
        struct List *next;
        struct List *head;
    
    public:
        List() {
            head = NULL;
        }
        void push(string);
        string pop();
        string peek();

        bool empty();

        void print();

};

void List::push(string x) {
    List* newnode = new List;
    newnode -> data = x;
    newnode -> next = NULL;
    
    if (head == NULL) {
        head = newnode;
        return;
    }

    struct List* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }

    temp -> next = newnode;

    

}

string List::pop() {
    if (head == NULL) {
        printf("UnderFlow Error: Stack is Empty.\n");
        return "0";
    }

    string elem;
    if (head -> next == NULL) {
        elem = head -> data;
        head = NULL;
        return elem;
    }

    struct List* temp = head;
    for (;temp -> next -> next != NULL; temp = temp -> next) {

    }

    elem = temp -> next -> data;
    temp -> next = NULL;

    return elem; 
}

string List::peek() {
    struct List* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }

    return temp -> data;
}

#include <stdbool.h>
bool List::empty() {
    return head == NULL;
}


void List::print() {
    struct List *temp = head;
    if (temp == NULL) {
        printf("head = NULL\n");
        return;
    }

    //printf("head -> ");
    for (; temp -> next != NULL; temp = temp -> next) {
        //cout << "FOR\n";
        cout << temp -> data << " ";
        //printf("%c ", temp -> data);
    }
    cout << temp -> data << "\n";
    //printf("%c -> NULL\n", temp -> data);
    
}
