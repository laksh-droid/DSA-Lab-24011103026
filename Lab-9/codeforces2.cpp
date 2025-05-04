//maximum strength of any participant that is not i
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;

    vector<string> results; // Store outputs for all test cases

    while (t--) {
        int n;
        cin >> n;
        vector<int> strengths(n);
        for (int i = 0; i < n; ++i) {
            cin >> strengths[i];
        }

        int max_strength = INT_MIN, second_max_strength = INT_MIN;
        for (int i = 0; i < n; ++i) {
            if (strengths[i] > max_strength) {
                second_max_strength = max_strength;
                max_strength = strengths[i];
            } else if (strengths[i] > second_max_strength && strengths[i] != max_strength) {
                second_max_strength = strengths[i];
            }
        }

        int count_max = count(strengths.begin(), strengths.end(), max_strength);
        string output_line;

        for (int i = 0; i < n; ++i) {
            int diff;
            if (strengths[i] == max_strength) {
                diff = (count_max > 1) ? 0 : strengths[i] - second_max_strength;
            } else {
                diff = strengths[i] - max_strength;
            }
            output_line += to_string(diff) + " ";
        }

        results.push_back(output_line);
    }

    cout << "\nOUTPUT:" << endl;
    // Output all results at the end
    for (const string& res : results) {
        cout << res << endl;
    }

    return 0;
}
