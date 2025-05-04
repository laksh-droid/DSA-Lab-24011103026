//Implementation of priority Queue ADT using max heap
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <stdbool.h>
using namespace std;



class PriorityQueue {
    private:
        vector<int> heap;

    public:
        void heapify(vector<int> &heap, int, int);
        
        void run_heap();
        void print();
        void insert(int);
        int deletion();
        
        bool Search(int);
        bool search(vector<int> &heap, int, int);

        void heapSort();
    
};

int main() {
    PriorityQueue pq;
    int choice, value;
    vector<int> initial;
    cout << "\n--- Priority Queue Menu ---\n";
    cout << "1. Insert\n2. Delete Max\n3. Search\n4. Display\n5. Heap Sort\n6. Exit\n";
    
    while (true) {
        
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                pq.insert(value);
                break;
            case 2:
                cout << "Deleted max: " << pq.deletion() << endl;
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                if (!pq.Search(value))
                    cout << "Not found.\n";
                else
                    cout << "Found.\n";
                break;
            case 4:
                cout << "Heap contents: ";
                pq.print();
                break;
            case 5:
                pq.heapSort();
                cout << "Heap sorted: ";
                pq.print();
                break;
            case 6:
                printf("Exiting...\n");
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
        cout << "\n\tThe queue: ";
        pq.print();
    }
}

void PriorityQueue::heapify(vector<int> &heap, int i, int n) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < n && heap[left] > heap[largest]) {
        largest = left;
    }
    
    if (right < n && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[largest], heap[i]);
        heapify(heap, largest, n);
    }
}

void PriorityQueue::run_heap() {
    for (int i = heap.size()-1; i >= 0; --i) {
        heapify(heap, i, heap.size());
    }
}

void PriorityQueue::print() {
    for (int i = 0; i < heap.size(); ++i) {
        cout << heap[i] << " ";
    }
    cout << endl;
}


void PriorityQueue::insert(int key) {
    heap.push_back(key);
    run_heap();
}


int PriorityQueue::deletion() {
    int dat = heap[0];
    heap[0] = heap[heap.size()-1];
    heap.erase(heap.begin()+heap.size()-1);
    
    run_heap();
    
    return dat;
}

bool PriorityQueue::Search(int key) {
    return search(heap, 0, key);
}

bool PriorityQueue::search(vector<int> &heap, int i, int key) {
    if (i >= heap.size()) {
        return false;
    }

    if (heap[i] == key) {
        return true;
    }

    bool leftSearch = search(heap, 2*i + 1, key);
    bool rightSearch = search(heap, 2*i + 2, key);

    return leftSearch || rightSearch;
}


void PriorityQueue::heapSort() {
    int n = heap.size();
    int key;
    vector<int> sorted;

    // One by one extract from heap
    for (int i = 0; i < n; ++i) {
        key = heap[0];
        heap.erase(heap.begin());
        run_heap();
        sorted.push_back(key);
    }
    heap = sorted;
}
