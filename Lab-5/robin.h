//methods that help simulate a round robin scheduling process
#include<iostream>
#include<stdio.h>
using namespace std;


#include<cstdio>
#include<cstdlib>

class List{
    private:
    struct Node{
    int data;
    Node* next;
    
    };
    struct Node *head;
    
    public:
        void insert(int);
        void insertatend(int);
        void deleteatbeg();
        void display();
        void execute(int);

    List(){
        head = NULL;
    }

};

//inserts element into the queue
void List::insert(int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = num;
    if(head == NULL){
        newNode->next = newNode;
        head = newNode;
    }
    else{
        Node*temp = head;
        while(temp-> next!= head ){
            temp = temp ->next;}
            
            newNode->next = head;
            temp -> next = newNode;
            head = newNode ;

    }
}


void List::insertatend(int num){
    struct Node* newNode = (struct Node*)malloc(sizeof(Node));
    newNode->data = num;
    if(head == NULL){
        newNode -> next = newNode;
        head = newNode;}
    else{
        Node*temp = head;
        while(temp ->next != head){
            temp = temp->next;
            }

            temp ->next = newNode;
            newNode -> next = head; 
    }    
}


void List::deleteatbeg(){
    if (head == NULL){
        printf("The list is empty\n");
        return;
    }
    if(head->next == head){
    free(head);
    head = NULL;
    return;}

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;}

        Node* deletea = head;
        head = head ->next;
        temp ->next = head;
        free(deletea);
    
}

void List::display(){
    if(head == NULL){
        printf("The list is empty");
    }

    else{
        Node* temp = head;
        while(temp -> next  != head){
            printf("%d -> ", temp->data);
            temp = temp ->next;}

        printf("%d -> Head\n", temp->data);
    }
}  

void List::execute(int x) {
    if (head == NULL) {
        return;
    }

    if ((head -> data) - x <= 0) {
        deleteatbeg();
    }

    else {
        int a = (head -> data) - x;
        deleteatbeg();
        insertatend(a);       
    }
    
    display();
    cout << endl;
}


