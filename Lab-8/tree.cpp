//Implementation of tree ADT using linked lists
#include <cstddef>
#include <cstdio>
#include <stdio.h>
#include <stdbool.h>
#include <iostream>
using namespace std;

class tree{
    private:
        struct TreeNode {
            int data;
            TreeNode *left;
            TreeNode *right;
        };
        TreeNode *root;

    public:
        TreeNode* create_node(int);
        void Inorder_traversal();
        void inorder_traversal(TreeNode*);
 
        void Postorder_traversal();
        void postorder_traversal(TreeNode*);

        void Preorder_traversal();
        void preorder_traversal(TreeNode*);

        void insert(int);
        bool search(int);
        
        tree() {
            root = NULL;
        }

};

//Inorder traversal of tree
void tree::Inorder_traversal() {
    inorder_traversal(root);
}

void tree::inorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder_traversal(root->left);
    cout << root->data << "  ";
    inorder_traversal(root->right);
}

//Postorder traversal of tree
void tree::Postorder_traversal() {
    postorder_traversal(root);
}

void tree::postorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << "  ";
}

//Preorder traversal of tree
void tree::Preorder_traversal() {
    preorder_traversal(root);
}

void tree::preorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << "  ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}


//level order insertion
void tree::insert(int x) {
    TreeNode* newNode = new TreeNode;
    newNode->data = x;
    newNode->left = nullptr;
    newNode->right = nullptr;

    if (!root) {
        root = newNode;
        return;
    }

    TreeNode* temp = root;
    while (true) {
        if (!temp->left) {
            temp->left = newNode;
            return;
        } else if (!temp->right) {
            temp->right = newNode;
            return;
        } else {
            temp = temp->left; 
        }
    }
}

//search for a node in tree
bool tree::search(int key) {
    TreeNode* temp = root;
    while (temp) {
        if (temp->data == key)
            return true;
        if (temp->left)
            temp = temp->left;
        else if (temp->right)
            temp = temp->right;
        else
            break;
    }

    if (temp->data == key) {
        return true;
    }
    return false;
}

int main() {
    tree T;

    int x, choice = 0;

    printf("MENU\n1 - Insert\n2 - Inorder traversal\n3 - Postorder traversal\n4 - Preorder traversal\n5 - Search\n6 - Exit\n");
    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter node to be inserted: ");
                scanf("%d", &x);
                T.insert(x);
                break;

            case 2:
                cout << "Inorder traversal: ";
                T.Inorder_traversal();
                printf("\n");
                break;

            case 3:
                cout << "Postorder traversal: ";
                T.Postorder_traversal();
                printf("\n");
                break;

            case 4:
                cout << "Preorder traversal: ";
                T.Preorder_traversal();
                printf("\n");
                break;

            case 5:
                printf("Enter node to search for: ");
                scanf("%d", &x);
                if (T.search(x)) {
                    printf("Node found\n");
                }
                else {
                    printf("Node is NOT found\n");
                }
                printf("\n");
                break;

            case 6:
                printf("Exiting...\n");
                return 0;
                break;

            default:
                printf("\nInvalid choice. Enter again.\n");
                break;
        }
        }






    return 0;
}
