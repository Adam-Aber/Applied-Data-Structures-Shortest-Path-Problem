// FILE: Graphs.cpp
#include "Graphs.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <set>
#include <limits>

using namespace std;


// Constructor
Graphs::Graphs() {
    E = V = order = 0;
}

// Destructor
Graphs::~Graphs() {
}


// Map vertex number (0,1,2,..) to (A,B,C,..)
char Graphs::Vname(const int s) const {
    return char(s+65);
}

void Graphs::getGraph(string fname) {
    ifstream source(fname.c_str());
    if (!source) {
        cerr << "The file could not be opened" << endl;
        return;
    }

    source >> V; // Read number of vertices

    E = 0; // Reset number of edges
    for (int r = 0; r < V; r++) {
        for (int c = 0; c < V; c++) {
            source >> AdjMatrix[r][c];
            if (r < c && AdjMatrix[r][c] != 0) {
                edges[E++] = Edge{r, c, AdjMatrix[r][c]};
            }
        }
    }
    source.close();
}


// Display Adjacency Matrix
void Graphs::dispGraph() const {
    cout << "Adjacency Matrix\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << setw(3) << AdjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Get Non-Zero edges from adjacency matrix
// and store them in array edges[].
void Graphs::getEdges() {
    int r, c;
    E = 0;
    for (r = 0; r < V; r++) {
        for (c = r + 1; c < V; c++) {
            if (AdjMatrix[r][c] > 0) {
                edges[E++] = Edge{r, c, AdjMatrix[r][c]};
            }
        }
    }
}


// Display Graph Edges
void Graphs::dispEdges() const {
    cout << "Graph Edges\n";
    for (int i = 0; i < E; i++) {
        printEdge(edges[i]);
    }
}

// Shortest paths from node s
void Graphs::shPath(int s) {
    for (int i = 0; i < V; i++) {
        via[i] = -1;
        distance[i] = numeric_limits<weightType>::max();
    }

    set<pair<weightType, int>> st;
    distance[s] = 0;
    st.insert({0, s});

    while (!st.empty()) {
        int u = st.begin()->second;
        st.erase(st.begin());

        for (int v = 0; v < V; v++) {
            if (AdjMatrix[u][v]) {
                weightType newDist = distance[u] + AdjMatrix[u][v];
                if (newDist < distance[v]) {
                    // If there is a shorter path to v through u.
                    if (distance[v] != numeric_limits<weightType>::max()) {
                        st.erase(st.find({distance[v], v}));
                    }
                    distance[v] = newDist;
                    st.insert({distance[v], v});
                    via[v] = u;
                }
            }
        }
    }
}

void Graphs::recurse(int v, vector<bool> &visited){};

// Depth First Search Traversal
void Graphs::DFS() {
    vector<bool> visited(V, false);
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            recurse(i, visited);
        }
    }
}

// Get number of vertices
int Graphs::No_of_Verices() const {
    return V;
}


// Get Number of Non-zero edges
int Graphs::No_of_Edges() const {
    return E;
}

// Output an edge
void Graphs::printEdge(Edge e) const {
    cout << Vname(e.u) << " " << Vname(e.v) << " => " << e.w << endl;
}


// Print path (vertex names) from source (s) to destination (i)
void Graphs::printPath(int s, int i) const {
    if (i == s) {
        cout << Vname(s);
        return;
    } else if (via[i] == -1) {
        cout << "There is not a path from " << Vname(s) << " to " << Vname(i);
        return;
    } else {
        printPath(s, via[i]);
        cout << " => " << Vname(i);
    }
}

void Graphs::visit(int k) {
    val[k] = order++;
    cout << "Visited vertex " << Vname(k) << " at the order " << val[k] << endl;
}