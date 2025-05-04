#include <stdio.h>
#include <stdbool.h>
#include "sort.h"

//searches input array of length n for element x through linear search method
bool linear_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return true;
        }
    }
    return false;
}

//searches input array of length n for element x through binary search method
bool binary_search(int arr[], int low, int high, int x) {

    while (low <= high) {
        int mid = low + (high-low)/2;

        if (arr[mid] == x) {
            return true;
        }

        if (x > arr[mid]) {
            low = mid + 1;
        }

        if (x < arr[mid]) {
            high = mid - 1;
        }
        
    }
    return false;
}

int main() {
    int n, element;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i+1);
        scanf("%d", arr+i);
    }
    printf("\nThe array: ");

    print_array(arr, n);


    printf("\n1 - Linear Search\n2 - Binary Search\n3 - Exit\n");
    int choice;
    while (choice != 3) { //menu
        printf("\nENter you choice:");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter the element to search for: ");
                scanf("%d", &element);
                
                if (linear_search(arr, n, element)){
                    printf("Found\n");
                } 
                else {
                    printf("not found\n");
                }
                break;
            
            case 2:
                printf("Enter the element to search for: ");
                scanf("%d", &element);
                
                selection_sort(arr, n);
                if (binary_search(arr, 0, n-1, element)){
                    printf("Found\n");
                } 
                else {
                    printf("not found\n");
                }
                break;
            
            case 3:
                printf("...exiting\n");
                break;
            
            default:
                printf("Invalid Choice\n");
                break;
        }
    }
    return 0;
}