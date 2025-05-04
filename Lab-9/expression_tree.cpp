#include <iostream>
#include <stack>
using namespace std;

class ExpressionTree {
    struct TreeNode {
        char data;
        TreeNode* left;
        TreeNode* right;
    };

    TreeNode* root;

    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%';
    }

    void inorder(TreeNode* node) {
        if (node) {
            if (isOperator(node->data)) cout << "(";
            inorder(node->left);
            cout << node->data;
            inorder(node->right);
            if (isOperator(node->data)) cout << ")";
        }
    }

    void preorder(TreeNode* node) {
        if (node) {
            cout << node->data;
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(TreeNode* node) {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data;
        }
    }

public:
    ExpressionTree() : root(NULL) {}

    void buildTree(string postfix) {
        stack<TreeNode*> stk;
        for (char ch : postfix) {
            TreeNode* node = new TreeNode{ch, NULL, NULL};
            if (isOperator(ch)) {
                node->right = stk.top(); stk.pop();
                node->left = stk.top(); stk.pop();
            }
            stk.push(node);
        }
        root = stk.top();
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }

    void preorder() {
        preorder(root);
        cout << endl;
    }

    void postorder() {
        postorder(root);
        cout << endl;
    }
};

int main() {
    ExpressionTree et;
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;
    et.buildTree(postfix);
    
    cout << "Inorder: ";
    et.inorder();
    
    cout << "Preorder: ";
    et.preorder();
    
    cout << "Postorder: ";
    et.postorder();

    return 0;
}
