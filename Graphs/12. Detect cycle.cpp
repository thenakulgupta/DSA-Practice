/*
    Probleam: Detect Cycle.
*/

#include <iostream>
#include <list>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;

    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        weight = w;
    }
};

bool detectCycleUtil(list<Edge> undirectedList_Cyclic[], int i, bool* visited, int parent = -1) {
    visited[i] = true;
    for (auto edge : undirectedList_Cyclic[i]) {
        if (visited[edge.dest] == false) {
            if (detectCycleUtil(undirectedList_Cyclic, edge.dest, visited, i)) {
                return true;
            }
        }
        else if (visited[edge.dest] == true && edge.dest != parent) {
            return true;
        }
    }
    visited[i] = false;
    return false;
}

bool detectCycle(list<Edge> undirectedList_Cyclic[], int n) {
    bool* visited = new bool[n];
    for (int i = 0;i < n;i++) {
        visited[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (visited[i] == false) {
            if (detectCycleUtil(undirectedList_Cyclic, i, visited)) {
                delete[] visited;
                return true;

            }
        }
    }
    delete[] visited;
    return false;
}

int main() {
    /*

        1 -- 0 -- 3
        |   /     |
        |  /      |
        | /       |
        2         4

    */
    int n = 5;
    list<Edge> undirectedList_Cyclic[n];
    undirectedList_Cyclic[1].push_back({ 1,0,-1 });
    undirectedList_Cyclic[1].push_back({ 1,2,-1 });
    undirectedList_Cyclic[2].push_back({ 2,1,-1 });
    undirectedList_Cyclic[2].push_back({ 2,0,-1 });
    undirectedList_Cyclic[0].push_back({ 0,1,-1 });
    undirectedList_Cyclic[0].push_back({ 0,2,-1 });
    undirectedList_Cyclic[0].push_back({ 0,3,-1 });
    undirectedList_Cyclic[3].push_back({ 3,4,-1 });
    undirectedList_Cyclic[4].push_back({ 4,3,-1 });

    cout << (detectCycle(undirectedList_Cyclic, n) ? "Yes" : "No");
    return 0;
}