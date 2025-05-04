//List ADT
#include <stdio.h>
#include <iostream>
#include <stdbool.h>
using namespace std;
#define SIZE 5

//class defition
class List {
    private:
        int arr[SIZE];

        int curr;
    
    public:
        List() {
            curr = -1;
        }

        void insert_beginning(int*, int);
        void insert_end(int*, int);
        void insert_position(int*, int, int);
        
        int delete_beginning(int*);
        int delete_ending(int*);
        int delete_position(int*, int);

        int search(int*, int);

        void rotate_n2(int*, int);
        void rotate(int*, int);

        bool empty();
        void print_list(int*);
    
    int getCurr() const { 
        return curr; 
    }
};

//INSERTIONS
//inserts the element in the beginnging
void List::insert_beginning(int arr[SIZE], int x) {
    if (curr >= SIZE-1) {
        return;
    }

    for (int i = curr; i > -1; i--) {
        arr[i+1] = arr[i];
    }
    arr[0] = x;  
    curr = curr + 1;  
}

//inserts the element in the end
void List::insert_end(int arr[SIZE], int x) {
    printf("curr: %d\n", curr);
    if (curr < SIZE-1){
        arr[curr+1] = x;
        printf("The end: %d\n", arr[curr+1]);
        print_list(arr);
    }
    curr = curr + 1;
    print_list(arr);
}   

//inserts the element in the specified position
void List::insert_position(int arr[SIZE], int x, int pos) {    
    if (pos < 0 || pos > curr) {
        printf("invalid pos\n");
        return;
    }
        
    if (curr < SIZE-1) {
        for (int i = curr; i >= pos; i--) {
            arr[i+1] = arr[i];
        }
        arr[pos] = x;
        curr = curr + 1;
    }
    else{
        printf("OverFlowError Detected: Ignoring Request.\n");
    }

    print_list(arr);
    
}

//DELETIONS
//delets the element from the beginning
int List::delete_beginning(int arr[SIZE]) {
    if (empty()){
        printf("UnderflowError: List is empty.\n");
        return 0;
    }
    int key = arr[0];
    
    for (int i = 0; i < (curr); i++) {
        arr[i] = arr[i+1];
    }
    curr = curr - 1;
    
    return key;
}

//delets the element from the end
int List::delete_ending(int arr[SIZE]) {
    if (empty()){
        printf("UnderflowError: List is empty.\n");
        return 0;
    }
    int key = arr[curr];
    
    curr = curr - 1;
    
    return key;
}

//delets the element from the specified position
int List::delete_position(int arr[SIZE], int pos) {
    if (pos > curr || pos < 0 || empty() == true) {
        printf("\nPossible Errors:\nUnderflowError: List is empty \n(or)\nPosition value is Invalid\n");
        return 0;
    }
    
    int key = arr[pos];
    printf("key : %d\n", key);
    for (int i = pos; i < (curr); i++) {
        arr[i] = arr[i+1];
    }
    curr = curr - 1;
    printf("key : %d\n", key);
    return key;
}


//SEARCH
int List::search(int arr[SIZE], int x) {
    for (int i = 0; i <= curr; i++) {
        if (arr[i] == x) {
            return 1;
        }
    }
    return 0;
}

//ROTATE in O(n^2)
void List::rotate_n2(int arr[SIZE], int k) {
    printf("I am inside\n");
    for (int i = 0; i < k; i++){
        printf("FOR lOOP1 A\n");
        int temp = arr[0];
        printf("FOR lOOP1 B\n");
        for (int j = SIZE-1; j >= 0; j--) {
            if (j+1 >= SIZE){
                printf("arr[j+1-SIZE] : %d,  arr[j] : %d\n", arr[j+1-SIZE], arr[j]);
                arr[j+1-SIZE] = arr[j];
            } 
            else if (j == 0) {
                arr[j+1] = temp;
            }
            else {
                printf("arr[j+1     ] : %d,  arr[j] : %d\n", arr[j+1], arr[j]);
                arr[j+1] = arr[j];
            }
        }
        //arr[0] = temp;
    }
}

//rotate in O(n)
void List::rotate(int arr[SIZE], int k) {
    int temp[SIZE];

    for (int i = 0; i < SIZE; i++) {
        temp[i] = arr[i];
    }
                                                                                                                                              
    for (int i = curr; i >= 0; i--) {
        if ((i+k) >= (curr+1)) {
            arr[i+k-curr-1] = temp[i];
        }
        else {
            arr[i+k] = temp[i];
        }
    }


    
}

//checks if the List is empty or not
bool List::empty() {
    return curr == -1;
}

//displays the elements of the List
void List::print_list(int A[]) {
    for (int i = 0; i <= curr; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main() {
    int A[SIZE] = {0};
    List L; 
    int x, pos;

    int choice;    
    printf("\n1 - Insert Beginning\n2 - Insert End\n3 - Insert Position\n");
    printf("\n4 - Delete Beginning\n5 - Delete End\n6 - Delete Positon\n");
    printf("\n7 - Search\n8 - Rotate\n9 - Exit\n");
    while (choice != 9) { //menu

        printf("\nEnter you choice:");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be added: ");
                scanf("%d", &x);
                L.insert_beginning(A, x);
                break;

            case 2:
                printf("Enter the element to be added: ");
                scanf("%d", &x);
                printf("%d", x);
                L.insert_end(A, x);
                break;
                
            case 3:
                printf("Enter the element to be added and its position: ");
                scanf("%d", &x);
                scanf("%d", &pos);
                L.insert_position(A, x, pos);
                break;
                
            case 4:
                printf("%d\n", L.delete_beginning(A));
                break;
                
            case 5:
                printf("%d\n", L.delete_ending(A));
                break;
                
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &pos);
                printf("%d\n", L.delete_position(A, pos));
                break;
                
            case 7:
                printf("Enter the element to be searched: ");
                scanf("%d", &x);
                if (L.search(A, x) == 1)
                    printf("Element found!\n");
                else 
                    printf("Element Not found!\n");
                break;
                
            case 8:
                int k;
                printf("Enter the number of time to be rotated: ");
                scanf("%d", &k);
                
                L.rotate(A, k);
                break;
                
            case 9:
                printf("Exiting...\n");
                return 0;
                break;
            
            default:
                break;
        }
        printf("\nThe List: ");
        L.print_list(A);
    }
}     

 