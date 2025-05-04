//Implementation of stack ADT using singly linked list
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class node {
    private:
        int data;
        struct node *next;
    public:
        void push(int);
        int pop();
        int peek();

        void print();

} *head = NULL;

//appends element to the stack
void node::push(int x) {
    struct node* newnode = (struct node*) malloc (sizeof(struct node));
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

//deletes the top and returns it
int node::pop() {
    if (head == NULL) {
        printf("UnderFlow Error: Stack is Empty.\n");
        return 0;
    }

    int elem;
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

//returns the top
int node::peek() {
    struct node* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
    }

    return temp -> data;
}

//prints without modifying the stack in the terminal
void node::print() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("head = NULL\n");
        return;
    }

    //printf("head -> ");
    for (; temp -> next != NULL; temp = temp -> next) {
        printf("%d -> ", temp -> data);
    }
    printf("%d -> NULL\n", temp -> data);
}



int main() {
    node stk;
    int x, pos, choice = 0;
    printf("MENU\n1 - PUSH\n2 - POP\n3 - PEEK\n4 - Exit\n");

    while (choice != 4) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Element to be pushed: ");
                scanf("%d", &x);
                stk.push(x);
                break;

            case 2:
                cout << stk.pop() << endl;
                break;

            case 3:
                cout << "TOP = " << stk.peek() << endl;
                break;
            
            case 4:
                printf("Exiting...\n");   
                break;
                
            default:
                printf("Invalid choice. Enter again.\n");
                break;
        }
        printf("\n\tThe stack : ");
        stk.print();
    }
    
}