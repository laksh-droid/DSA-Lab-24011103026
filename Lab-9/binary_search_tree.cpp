//implementation of binary search tree
#include <stdio.h>

class BinaryTree{
    private:
        struct TreeNode {
            int data;
            struct TreeNode* left;
            struct TreeNode* right;
        };
        struct TreeNode* root;
    
    public:
        TreeNode* CreateNode(int);

        TreeNode* insert(TreeNode*, int);
        void Insert(int);
        
        void inorder_traversal(TreeNode*);
        void InorderTraversal();
        
        void preorder_traversal(TreeNode*);
        void PreorderTraversal();

        void postorder_traversal(TreeNode*);
        void PostorderTraversal();

        TreeNode* Search(int);
        TreeNode* search(TreeNode*, int);

        
        BinaryTree(){
            root = NULL;
        }
};

BinaryTree::TreeNode* BinaryTree::CreateNode(int key) {
    TreeNode* newnode = new TreeNode;
    newnode -> data = key;
    newnode -> left = NULL;
    newnode -> right = NULL;

    return newnode;
}


void BinaryTree::Insert(int key) {
    root = insert(root, key);
}

BinaryTree::TreeNode* BinaryTree::insert(TreeNode* root, int key) {
    if (root == NULL) {
        root = CreateNode(key);
        return root;
    }

    if (key < root -> data) {
        root -> left = insert(root->left, key);
    }

    else if (key > root -> data) {
        root -> right = insert(root->right, key);
    }

    return root;
}


BinaryTree::TreeNode* BinaryTree::Search(int key) {
    return search(root, key);
}

BinaryTree::TreeNode* BinaryTree::search(TreeNode* root, int key) {
    if (root == NULL || key == root->data) {
        return root;
    }

    if (key < root -> data) {
        return search(root->left, key);
    }

    return search(root->right, key);

}


//inorder traversal
void BinaryTree::InorderTraversal() {
    inorder_traversal(root);
}

void BinaryTree::inorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

//preorder traversal
void BinaryTree::PreorderTraversal() {
    preorder_traversal(root);
}

void BinaryTree::preorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->data);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

//postorder traversal
void BinaryTree::PostorderTraversal() {
    postorder_traversal(root);
}

void BinaryTree::postorder_traversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%d ", root->data);
}


int main() {
    BinaryTree tree;
    int x, choice = 0;

    printf("MENU\n1 - Insertion\n2 - Indorder Traversal\n3 - Preorder Traversal\n4 - Postorder Traversal\n5 - Search\n6 - Exit\n");
    printf("Zero is not allowed in the queue. If the UnderFlowError occurs zero will be returned.\n");
    while (true) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter node to be inserted: ");
                scanf("%d", &x);
                tree.Insert(x);
                break;

            case 2:
                printf("Inorder Traversal: ");
                tree.InorderTraversal();
                printf("\n");
                break;

            case 3:
                printf("Preorder Traversal: ");
                tree.PreorderTraversal();
                printf("\n");
                break;
            
            case 4:
                printf("Postorder Traversal: ");
                tree.PostorderTraversal();
                printf("\n");
                break;

            case 5:
                printf("Enter node to be searched: ");
                scanf("%d", &x);
                if (tree.Search(x) != NULL) {
                    printf("Node is present in tree\n");
                }
                else {
                    printf("Node is NOT present in tree\n");
                }
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

}
