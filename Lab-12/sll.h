//Singly Linked List using list ADT
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
using namespace std;

class list {
    private:
        int vertex;
        int cost;
        struct list *next;
        struct list *head;
    
    public:
        void insert_beginning(int, int);
        void insert_end(int);
        void insert_position(int, int);

        int delete_beginning();
        int delete_end();
        int delete_position(int);

        bool search(int);

        int len();
        void print();
        
        list() {
            head = NULL;
        }

} ;

void list::insert_beginning(int x, int c) {
    struct list* newnode = (struct list*) malloc (sizeof(struct list));
    newnode -> vertex = x;
    newnode -> cost = c;
    newnode -> next = head;
    head = newnode;
}


int list::len() {
    int len = 0;
    struct list* temp = head;
    for (; temp -> next != NULL; temp = temp -> next) {
        len++;
    }

    return len+1;
}

void list::print() {
    struct list *temp = head;
    if (temp == NULL) {
        printf("head -> NULL\n");
        return;
    }

    for (; temp -> next != NULL; temp = temp -> next) {
        printf("(%d, %d) -> ", temp -> vertex, temp -> cost);
    }
    printf("(%d, %d) -> NULL\n", temp -> vertex, temp -> cost);
}
