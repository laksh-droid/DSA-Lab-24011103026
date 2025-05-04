//Implemention of list ADT using doubly linked lists

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

class node {
    private:
        int data;
        struct node* next;
        struct node* prev;

        struct node* head;
        struct node* tail;
    
    public:
        void insert_beginning(int);
        void insert_end(int);
        void insert_pos(int, int);

        int delete_beginning();
        int delete_end();
        int delete_pos(int);

        bool search(int);
        void print();
        void print_rev();

        
    
    node() {
        head = NULL;
        tail = NULL;
    }

};

//insertion of a of node containing value of x at the beginning of the DLL
void node::insert_beginning(int x) {
    struct node* newnode = new struct node;
    newnode -> data = x;

    newnode -> next = head;
    newnode -> prev = NULL;

    if (head != NULL) {
        head -> prev = newnode;       
    }
    head = newnode;

    if (tail == NULL) {
        tail = newnode;
    }
}

//insertion of a of node containing value of x at the end of the DLL
void node::insert_end(int x) {
    if (head == NULL) {
        insert_beginning(x);
        return;
    }

    struct node* newnode = new struct node;
    newnode -> data = x;

    newnode -> next = NULL;
    newnode -> prev = tail;
    tail -> next = newnode;
    tail = newnode;

    //cout << tail -> data << endl;
}

//insertion of a of node containing value of x at position pos of the DLL
void node::insert_pos(int x, int pos) {
    if (head == NULL) {
        cout << "List is empty.\n";
        return;
    }

    if (pos == 1) {
        insert_beginning(x);
        return;
    }

    node* temp = head;
    for (int i = 1; i < pos; i++, temp = temp -> next) {
        if (temp -> next == NULL) {
            cout << "position out of range.\n";
            return;
        }
    }

    struct node* newnode = new struct node;
    newnode -> data = x;

    newnode -> prev = temp -> prev;
    newnode -> next = temp;
    temp -> prev -> next = newnode;
    temp -> prev = newnode;
}

//Deletes the first element of the DLL
int node::delete_beginning() {
    if (head == NULL) {
        cout << "UnderFlowError: List is Empty\n";
        return 0;
    }
    
    int popped = head -> data;
    if (head -> next == NULL) {
        head = NULL;
        tail = NULL;
        return popped;
    }

    head = head -> next;
    head -> prev = NULL;

    return popped;
}

//Deletes the last element of the DLL
int node::delete_end() {
    if (head == NULL) {
        cout << "UnderFlowError: List is Empty\n";
        return 0;
    }
    
    int popped = tail -> data;
    if (tail -> prev == NULL) {
        head = NULL;
        tail = NULL;
        return popped;
    }

    tail = tail -> prev;
    tail -> next = NULL;

    return popped;
}

//deletes the element from the specified position from the DLL
int node::delete_pos(int pos) {
    if (head == NULL) {
        cout << "UnderFlowError: List is Empty\n";
        return 0;
    }

    if (pos == 1) {
        delete_beginning();
        return 0;
    }

    node* temp = head;
    for (int i = 1; i < pos; i++, temp = temp -> next) {
        if (temp -> next == NULL) {
            cout << "position out of range.\n";
            return 0;
        }
    }

    if (temp -> next == NULL) {
        delete_end();
        return 0;
    }

    temp -> prev -> next = temp -> next;
    temp -> next -> prev = temp -> prev;

    return 0;
}

//checks if element x is present in the DLL or not
bool node::search(int x) {
    node* temp = head;
    if (head == NULL) {
        return false;
    }
    
    for (; temp -> next != NULL; temp = temp -> next) {
        if (temp -> data == x) {
            return true;
        }
    }
    if (temp -> data == x) {
        return true;
    }

    return false;

}

//displaying the reverse of the doubly linked list
void node::print_rev() {
    node* temp = tail;
    if (head == NULL) {
        cout << "List is Empty.\n";
        return;
    }

    //cout << "NULL <- ";
    for (; temp -> prev != NULL; temp = temp -> prev) {
        cout << temp -> data << " <-> ";
    }
    cout << temp -> data << "\n";
}

//displaying the doubly linked list
void node::print() {
    node* temp = head;
    if (head == NULL) {
        cout << "List is Empty.\n";
        return;
    }
    //cout << "NULL <- ";
    for (; temp -> next != NULL; temp = temp -> next) {
        cout << temp -> data << " <-> ";
    }
    cout << temp -> data << "\n";
}

int main() {
    node L;
    int x, pos, choice;
    printf("MENU\n1 - Insert Beginning\n2 - Insert At End\n3 - Insert At Position\n");
    printf("4 - delete Beginning\n5 - delete At End\n6 - delete At Position\n");
    printf("7 - Search\n8 - Display\n9 - Display Reverse\n10 - Exit\n");

    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Element to be inserted: ");
                scanf("%d", &x);
                L.insert_beginning(x);
                break;

            case 2:
                printf("Enter Element to be inserted: ");
                scanf("%d", &x);
                L.insert_end(x);
                break;

            case 3:
                printf("Enter Element to be inserted and its postion: ");
                scanf("%d", &x);
                scanf("%d", &pos);
                L.insert_pos(x, pos);
                break;
            
            case 4:
                printf("%d\n", L.delete_beginning());
                break;

            case 5:
                printf("%d\n", L.delete_end());
                break;

            case 6:
                printf("Enter the postion for deletion: ");
                scanf("%d", &pos);
                printf("%d \n", L.delete_pos(pos));
                break;
            
            case 7:    
                printf("Enter Element to be searched: ");
                scanf("%d", &x);

                if (L.search(x) == 1) {
                    printf("Element Found.\n");
                }
                else {
                    printf("Element Not Found.\n");
                }
                break;
            
            case 8:    
                cout << "DISPLAYING LIST: ";
                L.print();
                break;
            
            case 9:   
                cout << "REVERSE OF LIST: "; 
                L.print_rev();
                break;
            
            case 10: 
                printf("Exiting...\n");  
                return 0; 
                break;
                
            default:
                //printf("\nInvalid choice. Enter again.\n");
                break;
        }
        printf("\nThe list : ");
        L.print();
    }

    return 0;
}