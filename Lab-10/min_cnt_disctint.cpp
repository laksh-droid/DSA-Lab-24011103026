//to find the minimum number of times to delete the first element from a sequence to get a sequence with unique numbers
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

bool distinct(vector<int>);
int process(int);


int main() {
    int t, n, cnt;
    vector<int> out;

    cin >> t;
    for (int i = 0; i < t; ++i) {
        cin >> n;
        cnt = process(n);
        out.push_back(cnt);
    }

    cout << "\nOUTPUT:\n";
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << endl;
    }
   
    return 0;
}

//checks if the sequence consists of distinct numbers or not
bool distinct(vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        for (int j = 0; j < vec.size(); ++j) {
            if (i != j && vec[i] == vec[j]) {
                return false;
            }
        }
    }
    return true;
}

//counts the minimum number of deletions needed to make the sequence distinct
int process(int n) {
    vector<int> vec;
    int x, count = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> x;
        vec.push_back(x);
    }
    
    while (vec.size() > 0) {
        if (distinct(vec) == true) {
            break;
        }
        vec.erase(vec.begin());
        count++;
    }
    return count;    
}

