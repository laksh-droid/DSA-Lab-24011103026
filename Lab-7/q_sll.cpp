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
        struct node *head;
    
    public:
        node() {
            head = NULL;
        }

        void enqueue(int);
        int dequeue();
        int peek();
        bool isempty();

        void print();

};

//adds element to end
void node::enqueue(int x) {
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

//deletes the front
int node::dequeue() {
    if (head == NULL) {
        printf("UnderFlow Error: Stack is Empty.\n");
        return 0;
    }

    int elem;
    elem = head -> data;
    head = head -> next;
    return elem; 
}

//returns the front
int node::peek() {
    return head -> data;
}

//displays the queue
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

//checks if queue is empty
bool node::isempty() {
    return (head == NULL);
}


int main() {
    node Q;
    int x, choice = 0;

    printf("MENU\n1 - Enqueue\n2 - Dequeue\n3 - Peek\n4 - Exit\n");
    printf("Zero is not allowed in the queue. If the UnderFlowError occurs zero will be returned.\n");
    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Element to be enqueued: ");
                scanf("%d", &x);
                Q.enqueue(x);
                break;

            case 2:
                cout << Q.dequeue() << endl;
                break;

            case 3:
                cout << "front: " << Q.peek() << endl;
                break;
            
            case 4:
                printf("Exiting...\n");
                return 0;
                break;

            default:
                printf("\nInvalid choice. Enter again.\n");
                break;
        }
        if (!Q.isempty()) {
            printf("\tQueue = ");
            Q.print();
        }
    }
}
