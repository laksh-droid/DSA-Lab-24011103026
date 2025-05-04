//how many would be declared as winners?
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int calculateWinners(int n, const vector<int>& a) {
    vector<int> players(n);
    for (int i = 0; i < n; ++i) players[i] = i; // initial lineup

    while (true) {
        vector<int> toKick;
        for (int pos : a) {
            if (pos <= players.size()) {
                toKick.push_back(pos - 1); // 0-based index
            }
        }

        if (toKick.empty()) break;

        set<int> kickSet(toKick.begin(), toKick.end());
        vector<int> newPlayers;
        for (int i = 0; i < players.size(); ++i) {
            if (kickSet.find(i) == kickSet.end()) {
                newPlayers.push_back(players[i]);
            }
        }

        if (newPlayers.size() == players.size()) break;
        players = newPlayers;
    }

    return players.size();
}

int main() {
    int t;
    cin >> t;

    vector<vector<int>> results; // store results for all test cases

    while (t--) {
        int k, q;
        cin >> k >> q;

        vector<int> a(k);
        for (int i = 0; i < k; ++i) cin >> a[i];

        vector<int> queries(q);
        for (int i = 0; i < q; ++i) cin >> queries[i];

        vector<int> currentResult;
        for (int n : queries) {
            currentResult.push_back(calculateWinners(n, a));
        }
        results.push_back(currentResult);
    }

    cout << "\nOUTPUT:" << endl;
    // Print all results at the end
    for (const auto& testCase : results) {
        for (int x : testCase) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}
