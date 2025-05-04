#include <iostream>
#include <stdbool.h>
using namespace std;

int* reverse(int*);
bool palindrome(int*);

int* len(int*);
int* pow(int*, int*);
bool armstrong_number(int*);
bool perfect_number(int*);

//returns the reverse of an integer
int* reverse(int *m) {
    int *u = (int*) malloc (sizeof(int));
    int *r = (int*) malloc (sizeof(int));
    int *n = (int*) malloc (sizeof(int));
    *n = *m;
    
    *r = 0;

    while ((*n) > 0) {
        *u = (*n) % 10;
        *r = (*r)*10 + (*u);
        *n = (*n) / 10;
    }

    free(u);
    return r;
}

//checks if the integer is palindrome or not
bool palindrome(int* n) {
    int *u = (int*) malloc (sizeof(int));
    *u = *n;    
    
    if (*u == (*reverse(n))) {
        free(u);
        return true;
    }
    
    free(u);
    return false;
}

//returns the length of the integer
int* len(int *n) {
    int *u = (int*) malloc (sizeof(int));
    *u = *n;    
    int *count = (int*) malloc (sizeof(int));
    *count = 0;
    while ((*u) > 0) {
        (*u) = (*u) /10;
        (*count)++;
    }

    return count;
}

//returns a^m
int* pow(int* a, int* m) {
    int *e = (int*) malloc (sizeof(int));
    *e = 1;
    int *b = (int*) malloc (sizeof(int));
    *b = *m;
    for(; (*b) > 0; (*b)--) {
        *e = (*e) * (*a);
    }

    return e;
}

//checks if the integer is an armstrong number or not
bool armstrong_number(int *n) {
    int *l = (int*) malloc (sizeof(int));
    *l = *(len(n));

    int *arm = (int*) malloc (sizeof(int));
    *arm = 0;
    
    int *m = (int*) malloc (sizeof(int));
    *m = *n;
    
    int *u = (int*) malloc (sizeof(int));

    while ((*m) > 0) {
        *u = (*m) % 10;
        *arm = (*arm) + (*pow(u, l));        
        *m = (*m) / 10;
    }
    free(u);
    free(l);
    free(m);

    if ((*arm) == (*n)) {
        free(arm);
        return true;
    }
    free(arm);
    return false;
}

//checks if the integer is a perfect number or not
bool perfect_number(int* n) {
    int *p = (int*) malloc (sizeof(int));
    *p = 0;
    int *i = (int*) malloc (sizeof(int));

    for ((*i) = 1; (*i) < (*n); (*i)++) {
        if ((*n) % (*i) == 0) {
            (*p) = (*p) + (*i);
        }
    }
    if ((*p) == (*n)){
        return true;
    }
    return false;
    }

int main() {
    int *n = (int*) malloc (sizeof(int)); 

    printf("Enter a number: ");
    scanf("%d", n);

    int *choice = (int*) malloc (sizeof(int));     
    printf("\n1 - Palindrome or Not\n2 - Armstrong Number or Not\n3 - Perfect Number or Not\n4 - Exit");
    while ((*choice) != 4) { //menu
        printf("\nENter you choice:");
        scanf("%d", choice);

        switch (*choice) {
            case 1:
                if (palindrome(n) == true) 
                    cout << "IT IS A PALINDROME!!!" << endl;
                else 
                    cout << "IT IS NOT A PALINDROME" << endl;
                break;

            case 2:
                if (armstrong_number(n) == true) 
                    cout << "IT IS AN ARMSTRONG NUMBER!!!" << endl;
                else 
                    cout << "IT IS NOT AN ARMSTRONG NUMBER." << endl;
                break;

            case 3:
                if (perfect_number(n) == true) 
                    cout << "IT IS AN PERFECT NUMBER!!!" << endl;
                else 
                    cout << "IT IS NOT AN PERFECT NUMBER." << endl;
                break;
            
            case 4:
                printf("exiting...\n");
                break;
            
            default:
                break;
        }
    }
    free(n);
    return 0; 
}