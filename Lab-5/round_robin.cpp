#include "robin.h"

int main() {
    List L;
    int x, pos, choice = 0;
    printf("MENU\n1 - Insert\n2 - Execute\n3 - Exit\n\n");

    while (choice != 3) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter Element to be inserted: ");
                scanf("%d", &x);
                L.insert(x);
                L.display();
                break;

            case 2:
                printf("Enter Time contraint: ");
                scanf("%d", &x);
                L.execute(x);
                L.display();
                break;

            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("invalid option\n");
                break;
        }
    }
}
