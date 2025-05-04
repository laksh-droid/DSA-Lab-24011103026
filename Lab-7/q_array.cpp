//Queue ADT using array implementation with array having size 5
#include <iostream>
#include <stdbool.h>
using namespace std;
#define SIZE 5

class queue {
    private:
        int arr[SIZE];
        int rear;
    public:
        void enqueue(int);
        int dequeue();
        int peek();
        void print();
        bool isfull();
        bool isempty();
        
    
        queue() {
            rear = -1;
        }
};

//adds element to back
void queue::enqueue(int x) {
    if (isfull()) {
        printf("  OverFlowError: Queue is Full\n");
        return;
    }

    arr[rear+1] = x;
    rear++;
}

//deletes front
int queue::dequeue() {
    if (isempty()) {
        printf("  UnderFlowError: Queue is Empty\n");
        return 0;
    }
    
    int del = arr[0];
    if (rear == 0) {
        rear = -1;
    }
    else {
        for (int i = 0; i < rear; ++i) {
            arr[i] = arr[i+1];
        }
        rear--;
    }

    return del;
}

//rturns the front
int queue::peek() {
    if (isempty()) {
        return 0;
    }
    return arr[0];
}

//displays the queue
void queue::print() {
    for (int i = 0; i < rear+1; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//checks if q is full
bool queue::isfull() {
    return rear == SIZE-1;
}

//checks if q is empty
bool queue::isempty() {
    return rear == -1;
}

int main() {
    queue Q;
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

