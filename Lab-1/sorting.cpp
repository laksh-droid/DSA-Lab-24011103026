//Menudriven program for sorting algorithms
#include <stdio.h>

//swaps the values of two variables
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//prints the elements of the input array in terminal
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
    }
    printf("\n");
}

//sorts the input array of length n using the bubble sorting method
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr+i, arr+j);
            }
        }
    }
}

//sorts the input array of length n using the insertion sorting method
void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;

    }
}

//sorts the input array of length n using the bubble sorting method
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min_index = i;
        
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        swap(arr+min_index, arr+i);
   }
}


int main() {
    int n = 5;
//    int a[n] = {15,2,13,4,5};
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", a+i);
    }
    printf("\n");

    printf("1 - Bubble Sort\n2 - Selection Sort\n3 - Insertion Sort\n4 - Exit\n");
    int choice;
    while (choice != 4) { //menu
        printf("\nEnter you choice:");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                bubble_sort(a, n);
                print_array(a, n);
                break;
            case 2:
                selection_sort(a, n);
                print_array(a, n);
                break;
            case 3:
                insertion_sort(a, n);
                print_array(a, n);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}