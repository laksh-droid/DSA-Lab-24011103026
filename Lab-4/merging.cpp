#include<iostream>
#include<stdio.h>
using namespace std;
#include "list.h"


int main(){
    List l1; 
    int choice;
    int number1, number2, value;
    do  {
        cout << "\nMENU:" << endl;
        cout << "1. Insert " << endl;
        cout << "2. Merge the two lists " << endl;
        cout << "3. Display " << endl; 
        cout << "4. Exit" << endl;
        
        cout << "\nEnter your choice from the above menu: ";
        cin >> choice;

        switch(choice) {
            case 1:    //This function enters the lists
                cout << "Enter the number of elements you want to add in list1 (in descending order): ";
                cin >> number1;

                printf("Enter the elements seperated by spaces: ");
                for(int i=0 ;i < number1 ;i++)
                {
                    scanf("%d", &value);
                    l1.insert_beginning( l1.gethead1(),value);
                }
                    cout << "List 1: ";
                    l1.display(l1.gethead1());

                cout << "Enter the number of elements you want to add in list2 (in descending order): " ;
                cin >> number2;
                
                printf("Enter the elements seperated by spaces: ");
                for(int i=0 ; i< number2 ; i++){
                    scanf("%d", &value);
                    l1.insert_beginning(l1.gethead2() , value);
                }
                cout << "List 2: ";
                l1.display(l1.gethead2());

            break;

            case 2: // to merge and diplay the list
                cout << "The function of merging and sorting the lists in ascending order is performed." << endl;
                cout << "Click on the Display option to display the merged list." << endl; 
            break;

            case 3:
            cout << "Merged list: " ;
            l1.displaym();
            break;

            case 4:
            cout << "Exiting..." << endl;
            break;

        }
    } while(choice != 4);

   return 0;     
    
}

