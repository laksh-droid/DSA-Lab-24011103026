//menu driven program to calculate the area of square, cube, rectangle, cuboid
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//class for area
class area {
    private:
        int length, breadth, height;
    
    public:
        int square(int l);
        int cube(int l);
        int rectangle(int l, int b);
        int cuboid(int l, int b, int h);
};

//class method for area of square
int area::square(int l) {
    return l*l;
}

//class method for area of cube
int area::cube(int l) {
    return 6*l*l;
}

//class method for area of rectangle
int area::rectangle(int l, int b) {
    return l*b;
}

//class method for area of cuboid
int area::cuboid(int l, int b, int h) {
    return 2*(l*b + b*h + l*h);
}

int main(int argc, char* argv[]) {
    area obj;
    
    if (argc < 2) {
        return 0;
    }

    int *choice = (int*) malloc (sizeof(int));     
    printf("\n1 - Square\n2 - Cube\n3 - Rectangle\n4 - Cuboid\n5 - Exit\n");
    while ((*choice) != 5) { //menu
        printf("\nENter you choice:");
        scanf("%d", choice);

        switch (*choice) {
            case 1:
                printf("The area of the square of length %d is %d\n", atoi(argv[1]), obj.square(atoi(argv[1])));
                break;
            case 2:
                printf("The surface area of the cube of edge length %d is %d\n", atoi(argv[1]), obj.cube(atoi(argv[1])));
                break;
            case 3:
                printf("The area of the rectangle of length %d and breadth %d is %d\n", atoi(argv[1]), atoi(argv[2]), obj.rectangle(atoi(argv[1]), atoi(argv[2])));
                break;
            case 4:
                printf("The area of the cuboid of length %d, breadth %d and height %d is %d\n", atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), obj.cuboid(atoi(argv[1]), atoi(argv[2]), atoi(argv[3])));
                break;
            case 5:
                printf("exiting...\n");
                break;
            default:
                break;
        }
    }

    free(choice);

}