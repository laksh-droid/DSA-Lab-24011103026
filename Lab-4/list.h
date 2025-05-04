#ifndef LIST_H
#define LIST_H

#include <iostream>
using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    Node* head1;
    Node* head2;

public:
    List();  
    void insert_beginning(Node*& head, int val);

    
    void display(Node* head);
    Node* mergesortedlists(Node* head1, Node* head2);
    void displaym();
    
    Node*& gethead1();
    Node*& gethead2();
};


List::List() {
    head1 = head2 = NULL;
}

void List::insert_beginning(Node*& head, int val) {
    Node* newnode = new Node(val);
    if (head == nullptr) {
        head = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}

void List::display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

List::Node* List::mergesortedlists(Node* head1, Node* head2) {
    if (head1 == nullptr || head2 == nullptr) {
        return head1 == nullptr ? head2 : head1;
    }

    if (head1->data <= head2->data) {
        head1->next = mergesortedlists(head1->next, head2);
        return head1;
    } else {
        head2->next = mergesortedlists(head1, head2->next);
        return head2;
    }
}

void List::displaym() {
    Node* newnode = mergesortedlists(head1, head2);
    while (newnode != nullptr) {
        cout << newnode->data << "->";
        newnode = newnode->next;
    }
    cout << "NULL" << endl;
}

List::Node*& List::gethead1() {
    return head1;
}

List::Node*& List::gethead2() {
    return head2;
}



#endif // LIST_H
