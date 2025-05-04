//Hearder file for sorting algorithms

//interchanges the values of two integer variables
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//displays the array in terminal
void print_array(int arr[], int n) {
    for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
    }
    printf("\n");
}

//sorts the array using bubble sort method
void bubble_sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] < arr[j]) {
                swap(arr+i, arr+j);
            }
        }
    }
}

//sorts the array using insertion sort method
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

//sorts the array using selection sort method
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

