//Implementation of stack ADT using array
#include <stdio.h>
#include <iostream>
using namespace std;
#define SIZE 5

class list {
    private:
        int arr[SIZE];
        int curr = -1;
    
    public:     
        void push(int*, int);
        int pop(int*);
        int peek(int*);

        bool empty();
        void print(int*);
    
    int getCurr() const { 
        return curr; 
    }
};

//appends to the stack
void list::push(int arr[SIZE], int x) {
    if (curr < SIZE-1) {
        arr[curr+1] = x;
        curr++;
        return;
    }
    cout << "OverFlowError: Stack is full\n";
    return;
}

//deletes the top
int list::pop(int arr[SIZE]) {
    if (empty()){
        printf("UnderflowError: Stack is empty.\n");
        return 0;
    }
    int key = arr[curr];
    
    curr = curr - 1;
    
    return key;
}

//returns the top
int list::peek(int arr[SIZE]) {
    return arr[curr];
}


//Prints the stack elements without modifying them in the terminal
void list::print(int A[SIZE]) {
    for (int i = 0; i <= curr; i++) {
        printf("%d ", A[i]);
    }
    cout << endl;
}

#include <stdbool.h>
bool list::empty() {
    return curr == -1;
}

int main() {
    int arr[SIZE] = {0};
    list stk; 

    int x, pos, choice = 0;
    printf("MENU\n1 - PUSH\n2 - POP\n3 - PEEK\n4 - Exit\n");
    
    while (choice != 4) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Element to be pushed: ");
                scanf("%d", &x);
                stk.push(arr, x);
                break;

            case 2:
                cout << stk.pop(arr) << endl;
                break;

            case 3:
                cout << "TOP = " << stk.peek(arr) << endl;
                break;
            
            case 4:
                printf("Exiting...\n");   
                break;
                
            default:
                printf("Invalid choice. Enter again.\n");
                break;
        }
        printf("\n\tThe stack : ");
        stk.print(arr);
    }
}