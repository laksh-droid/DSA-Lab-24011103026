//Singly Linked List using list ADT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

//class definition for SLL
class node {
    private:
        int data;
        struct node *next;
    
    public:
        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int, int);

        int delete_beginning();
        int delete_end();
        int delete_position(int);

        bool search(int);

        void reverse_display(struct node*);
        node* reverse(node*);

        int len();
        void print();

} *head = NULL;

//method to insert element x at the start of the SLL
void node::insert_beginning(int x) {
    struct node* newnode = (struct node*) malloc (sizeof(struct node));
    newnode -> data = x;
    newnode -> next = head;
    head = newnode;
}

//method to insert element x at the end of the SLL
void node::insert_end(int x) {
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

//method to insert element x at the specified position in the SLL
void node::insert_position(int x, int pos) {
    struct node *newnode = (struct node*) malloc (sizeof(struct node));
    
    if (pos > len() || pos < 1) {
        printf("Invalid Postion.\n");
        return;
    }

    if (pos == 1) {
        insert_beginning(x);
        return;
    }

    newnode -> data = x;
    struct node* temp = head;
    for (int i = 1; (temp -> next != NULL) && i < pos-1; i++) {
        temp = temp -> next;
    }
    newnode -> next = temp -> next;
    temp -> next = newnode;
}

//method to delete the first element of the SLL
int node::delete_beginning() {
    if (head == NULL) {
        printf("UnderFlow Error: List is Empty.\n");
        return 0;
    }

    int elem;
    elem = head -> data;
    head = head -> next;

    return elem; 
}

//method to delete last element of the SLL
int node::delete_end() {
    if (head == NULL) {
        printf("UnderFlow Error: List is Empty.\n");
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

//method to delete the element present in the specified position
int node::delete_position(int pos) {
    if (head == NULL) {
        printf("\nUnderFlow Error: List is Empty.\n");
        return 0;
    }

    if (pos > len() || pos < 0) {
        printf("\nInvalid Position.\n");
        return 0;
    }
    int elem;

    struct node* temp = head;
    if (pos == 1) {
        elem = head -> data;
        head = head -> next;
        return elem;
    }
    for (int i = 1; temp -> next != NULL && i < pos-1; i++) {
        temp = temp -> next;
    }

    elem = temp -> next -> data;
    temp -> next = temp -> next -> next;

    return elem; 
}

//method to check if element x is presentin the SLL or not
bool node::search(int x) {
    struct node* temp = head;
    for (int i = 0; temp -> next != NULL; temp = temp -> next){
        if (temp -> data == x) {
            return 1;
        }
        i++;
    }
    if (temp -> data == x) {
        return 1;
    }

    return 0;
}

//method to display the reverse of the SLL
void node::reverse_display(struct node* temp) {
    if (temp -> next == NULL) {
        printf("%d ", temp -> data);
        return;
    }

    reverse_display(temp->next);
    printf("<- %d ", temp->data);
}

//method to reverse the SLL
node* node::reverse(node *head) {
    node *curr = head, *P = NULL, *N;

    while (curr != NULL) {
        N = curr->next;
        curr->next = P;

        P = curr;
        curr = N;
    }

    return P;
}

//method to find the number of elements in the SLL
int node::len() {
    int len = 0;
    struct node* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
        len++;
    }

    return len+1;
}

//method to display the singly liked list
void node::print() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("head -> NULL\n");
        return;
    }

    //printf("head -> ");
    for (; temp -> next != NULL; temp = temp -> next) {
        printf("%d -> ", temp -> data);
    }
    printf("%d -> NULL\n", temp -> data);
}


int main() {
    node L;
    int x, pos, choice = 0;
    printf("MENU\n1 - Insert Beginning\n2 - Insert At End\n3 - Insert At Position\n\n");
    printf("4 - delete Beginning\n5 - delete At End\n6 - delete At Position\n\n");
    printf("7 - Search\n8 - Reverse\n9 - Display\n\n10 - Exit\n\n");

    while (choice != 10) {
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
                L.insert_position(x, pos);
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
                printf("%d \n", L.delete_position(pos));
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
                printf("Reverse of the list: ");
                L.reverse_display(head);
                printf("\n");
                break;
            
            case 9:    
                head = L.reverse(head);
                break;
            
            case 10: 
                printf("Exiting...\n");   
                break;
                
            default:
                //printf("\nInvalid choice. Enter again.\n");
                break;
        }
        if (choice != 10) {
            if (head == NULL) {
                printf("NULL");
            }
            else {
                printf("\nThe list : ");
                L.print();
            }
        }
    }
}