//Queue ADT using array implementation with array having size 5
#include <iostream>
#include <stdbool.h>
using namespace std;
#define SIZE 5

class queue {
    private:
        int arr[SIZE];
        int front;
        int rear;
    public:
        void enqueue(int);
        int dequeue();
        int peek();
        void print();
        bool isfull();
        bool isempty();
        
    
        queue() {
            front = -1;
            rear = -1;
        }
};

void queue::enqueue(int x) {
    if (isfull()) {
        printf("  OverFlowError: Queue is Full\n");
        return;
    }
    if (isempty()) {
        arr[front+1] = x;
        front++;
        rear++;
        return;
    }

    if (front < rear) {
        if (rear == SIZE-1) {
            arr[0] = x;
            rear = 0;
        }
        else {
            arr[rear+1] = x;
            rear++;
        }
    }

    else if (front == rear) {
        if (rear == SIZE-1) {
            arr[0] = x;
            rear = 0;
        }
        else {
            arr[rear+1] = x;
            rear++;
        }
    }

    else if (front > rear) {
        arr[rear+1] = x;
        rear++;
    }

    else {
        return;
    }
    
}

int queue::dequeue() {
    if (isempty()) {
        printf("  UnderFlowError: Queue is Empty\n");
        return 0;
    }
    
    int del = arr[front];
    arr[front] = 0;

    if (front == rear) {
        front = -1;
        rear = -1;
    }

    else if (front < rear) {
        front++;
    }

    else if (front > rear) {
        if (front-1 == rear) {
            if (front == SIZE-1) {
                front = 0;
            }
            else {
                front++;
            }
        }
        else {
            if (front == SIZE-1) {
                front = 0;
            }
            else {
                front++;
            }
        }
    }

    return del;
}

int queue::peek() {
    if (isempty()) {
        return 0;
    }
    return arr[front];
}

void queue::print() {
    if (front < rear) {
        for (int i = front; i < rear+1; ++i) {
           printf("%d ", arr[i]);
        }
    }
    else if (front == rear && front != -1) {
        printf("%d", arr[front]);
    }

    else if (front > rear) {
        for (int i = front; i < SIZE; ++i) {
            printf("%d ", arr[i]);
        }
        for (int i = 0; i < rear+1; ++i) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

bool queue::isfull() {
    if (rear+1 == front)
        return true;
    if (front == 0 && rear == SIZE-1)
        return true;
    return false;
}

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

