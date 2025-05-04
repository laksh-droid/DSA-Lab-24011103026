//conducting conversions using .h file that performs actions on expression trees
#include "exptree.h"
int main() {
    ExpressionTree tree;
    int choice;

    cout << "\n1. Postfix Expression\n2. Construct Expression Tree\n3. Preorder\n4. Inorder\n5. Postorder\n6. Exit\n";
    while (true) {
        cout << "\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                tree.readPostfix();
                break;
            case 2:
                tree.constructTree();
                break;
            case 3:
                tree.displayPreorder();
                break;
            case 4:
                tree.displayInorder();
                break;
            case 5:
                tree.displayPostorder();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice.\n";
        }
    }
}
