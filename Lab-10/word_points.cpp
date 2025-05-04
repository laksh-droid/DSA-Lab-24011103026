//to find the minimum number of times to delete the first element from a sequence to get a sequence with unique numbers
#include <stdio.h>
#include <iostream>
#include <vector>
#include <stdbool.h>
using namespace std;

vector<int> process(vector<string>, vector<string>, vector<string>);
bool in(string, vector<string>);
int points(vector<string>, vector<string>, vector<string>);

int main() {
    vector<string> joe;
    vector<string> bob;
    vector<string> ann;
    vector<string> temp;

    vector<int> points;
    vector<vector<int>> out;
    string x;
    int t, n;
    cin >> t;

    for (int k = 0; k < t; ++k) {
        joe = temp;
        bob = temp;
        ann = temp;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> x;
            joe.push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            cin >> x;
            bob.push_back(x);
        }
        for (int i = 0; i < n; ++i) {
            cin >> x;
            ann.push_back(x);
        }

        points = process(joe, bob, ann);

        out.push_back(points);
    }

    printf("\nOUTPUT:\n");
    for (int i = 0; i < t; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}


bool in(string str, vector<string> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        if (str == vec[i]) {
            return true;
        }
    }
    return false;
}

int points(vector<string> vic, vector<string> ch1, vector<string> ch2) {
    int pt = 0;
    for (int i = 0; i < vic.size(); ++i) {
        if (in(vic[i], ch1) == true && in(vic[i], ch2) == false) {
            pt = pt + 1;
        }

        if (in(vic[i], ch2) == true && in(vic[i], ch1) == false) {
            pt = pt + 1;
        }

        if (in(vic[i], ch1) == false && in(vic[i], ch2) == false) {
            pt = pt + 3;
        }
    }
    return pt;
}

vector<int> process(vector<string> joe, vector<string> bob, vector<string> ann) {
    vector<int> pnts;

    pnts.push_back(points(joe, bob, ann));
    pnts.push_back(points(bob, joe, ann));
    pnts.push_back(points(ann, bob, joe));
    
    return pnts;
    
}