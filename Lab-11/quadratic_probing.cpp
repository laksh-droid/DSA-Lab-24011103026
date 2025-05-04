//hash tables using quadratic probing
#include <stdio.h>
#include <iostream>
#include <stdbool.h>
#define SIZE 10
using namespace std;
 

class hash_table {
    private:
        int m = SIZE;
        int table[SIZE] = {};
    
    public:
        int hash_function(int);
        int quadratic_probing(int, int);

        void insert(int);
        int deletion(int);
        bool search(int);
        bool is_full();
        void print();
};

int main() {
    hash_table tab;
    int key, choice = 0;

    printf("MENU\n1 - Insert\n2 - Delete\n3 - Search\n4 - Exit\n");
    printf("Zero is not allowed in the hash table unless it is representing empty space\n");
    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                tab.insert(key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                
                printf("%d\n", tab.deletion(key));
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (tab.search(key))
                    printf("key present in hash table\n");
                else
                    printf("key not present in hash table\n");
                break;

            case 4:
                printf("Exiting...\n");
                return 0;
                break;

            default:
                printf("\nInvalid choice. Enter again.\n");
                break;
        }
        printf("\n\tThe hash table: ");
        tab.print();   
    }
}

//hash function definition
int hash_table::hash_function(int key) {
    return key % m;
}

//linear probing if collisions occur
int hash_table::quadratic_probing(int key, int i) {
    if (hash_function(key) + i*i > m-1) {
        return (hash_function(key) + i*i + i) % m;    
    }
    return hash_function(key) + i*i;
}

//insertion of keys into hash table
void hash_table::insert(int key) {
    if (is_full()) {
        printf("OverFlowError: The hash table is Full\n");
        return;
    }
    int i = hash_function(key);
    int j, collision = 0;
    if (table[i] != 0) {
        while (true) {
            collision = collision + 1;
            j = quadratic_probing(key, collision);
            if (table[j] == 0) {
                table[j] = key;
                break;
            }
        }
    }
    else {
        table[i] = key;
    }
}

//deletes a specified key from the hash table
int hash_table::deletion(int key) {
    int del;
    for (int i = 0; i < m; ++i) {
        if (table[i] == key) {
            del = table[i];
            table[i] = 0;
            return del;
        }
    }
    
    printf("key not present in table\n");
    return 0;
}

//checks if a key is present in the table or not
bool hash_table::search(int key) {
    for (int i = 0; i < m; ++i) {
        if (table[i] == key) {
            return true;
        }
    }
    return false;
}

//checks if the hash table is full or not
bool hash_table::is_full() {
    for (int i = 0; i < m; ++i) {
        if (table[i] == 0) {
            return false;
        }
    }
    return true;
}

//displays the hash table
void hash_table::print() {
    for (int i = 0; i < m; ++i) {
        printf("%d ", table[i]);
    }
    printf("\n");
}
