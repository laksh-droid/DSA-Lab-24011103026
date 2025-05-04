//Implementation of graphs using adjacency list
#include "sll.h"
#include <vector>
#include <iostream>

using namespace std;

class graph {
private:
    int n;
    vector<list> adjlist;

public:
    graph(int nodes) : n(nodes) {
        adjlist.resize(n+1); 
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
        cout << "\nAdjacency List:\n";
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
    return 0;
}

void graph::insert_edge(int u, int v, int cost) {
    if (u > 0 && u < n+1 && v > 0 && v < n+1) {
        adjlist[u].insert_beginning(v, cost);
    }
}

void graph::print_graph() {
    for (int i = 1; i < n+1; ++i) {
        cout << i << ": ";
        adjlist[i].print();
        cout << endl;
    }
}

