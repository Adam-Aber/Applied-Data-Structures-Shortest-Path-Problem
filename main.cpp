#include <iostream>
#include "Graphs.h"
//Adam Aberbach - 900225980
using namespace std;

int main() {
    Graphs g;
    string file = "C:\\Users\\Adam\\CLionProjects\\AppliedDataStructureAssignment6\\AssignBonus\\Sample.txt";
    int initial = 0;
    int final = 6;
    g.getGraph(file);

    g.dispGraph(); g.dispEdges();

    g.shPath(initial);
    cout << "The shortest path from A to G is ";
    g.printPath(initial, final);

    return 0;
}
