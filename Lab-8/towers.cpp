//what is the maximum number of blocks possible in tower 1?
#include <iostream>

using namespace std;

void tower_one_blocks(int*, int);


int main() {
    int t;
    cin >> t;
    int* tes = (int*) malloc (t*sizeof(int));
    tower_one_blocks(tes, t);
    
    for (int j = 0; j < t; ++j) {
            cout << "Test Case " << j+1 << ": " << tes[j] << "\n";
        }
        cout << endl;    

}

//calculates the maximum number of blocks that can be possibly stored in the first tower 
//given the condition that a block can only be moved for a tower with higher number of blockas to a tower having lower number of blocks 
//for all test cases
void tower_one_blocks(int* tesarr, int t) {
    int n, blk;
    int arr[n];
    for (int i = 0; i < t; ++i) {
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        blk = arr[0];
        for (int j = 1; j < n; ++j) {
            while (true) {
                if (blk >= arr[j]) {
                    break;
                }
                arr[0]++;
                arr[j]--;
                blk = arr[0];
            }
        }
        tesarr[i] = blk;
    }
}


