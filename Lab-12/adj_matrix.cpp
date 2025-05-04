//Implementation of graphs using adjacency matrix
#include <iostream>
#include <vector>
using namespace std;

class graph {
    private:
        int n;
        vector<vector<int>> adjmat;

    public:
        graph(int nodes) : n(nodes) {
            adjmat.resize(n+1, vector<int>(n+1, 0)); 
        }
        void insert_edge(int, int, int);
        void print_graph();
};

int main() {
    int nodes, choice, u, v, cost;
    cout << "Enter the number of nodes: ";
    cin >> nodes;
    graph G(nodes);
    cout << "\nMENU\nInsert - 1\nExit - 2\n";
    while (true) {
        cout << "\nAdjacency Matrix:\n";
        G.print_graph();
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "node1 node2 cost: ";
                cin >> u >> v >> cost;
                G.insert_edge(u, v, cost);
                break;

            case 2:
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid choice. Try again.\n";
                break;
        }
    }
}


void graph::insert_edge(int u, int v, int cost) {
    if (u > 0 && u < n+1 && v > 0 && v < n+1) {
        adjmat[u][v] = cost;
        // adjmat[v][u] = cost; //if undirected graph
    }
}

void graph::print_graph() {
    for (int i = 1; i < n+1; ++i) {
        for (int j = 1; j < n+1; ++j) {
            cout << adjmat[i][j] << " ";
        }
        cout << endl;
    }
}
