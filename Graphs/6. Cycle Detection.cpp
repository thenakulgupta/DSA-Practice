/*
    Probleam: Cycle Detection.
*/

#include <iostream>
#include <list>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int weight;
    Edge(int src1, int dest1, int weight1) {
        src = src1;
        dest = dest1;
        weight = weight1;
    }
};

bool cycleDetectionUndirectedUtil(list<Edge> edges[], int n, bool* visits, int parent) {
    visits[n] = true;
    for (auto i : edges[n]) {
        if (visits[i.dest] == false) {
            if (cycleDetectionUndirectedUtil(edges, i.dest, visits, n)) {
                return true;
            }
        }
        if (visits[i.dest] == true && i.dest != parent) {
            return true;
        }
    }
    visits[n] = false;
    return false;
}

bool cycleDetectionUndirected(list<Edge> edges[], int n) {
    bool* visits = new bool[n];
    for (int i = 0;i < n;i++) {
        visits[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (visits[i] == false) {
            if (cycleDetectionUndirectedUtil(edges, i, visits, -1)) {
                delete[] visits;
                return true;
            }
        }
    }
    delete[] visits;
    return false;
}

bool cycleDetectionDirectedUtil(list<Edge> edges[], int n, int pos, bool* visited, bool* stack) {
    visited[pos] = true;
    stack[pos] = true;
    for (auto edge : edges[pos]) {
        if (stack[edge.dest] == true) {
            return true;
        }
        else if (visited[edge.dest] == false) {
            if (cycleDetectionDirectedUtil(edges, n, edge.dest, visited, stack)) {
                return true;
            }
        }
    }
    stack[pos] = false;
    return false;
}

bool cycleDetectionDirected(list<Edge> edges[], int n) {
    bool* visited = new bool[n];
    bool* stack = new bool[n];
    for (int i = 0;i < n;i++) {
        visited[i] = false;
    }
    for (int i = 0;i < n;i++) {
        stack[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (visited[i] == false) {
            if (cycleDetectionDirectedUtil(edges, n, i, visited, stack)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int n = 5;
    /*
           0 --- 3
          /      |
         /       |
        1        |
         \       |
          \      |
           2     4
    */
    list<Edge> undirectedList_ACyclic[n];
    undirectedList_ACyclic[0].push_back({ 0,1,-1 });
    undirectedList_ACyclic[0].push_back({ 0,3,-1 });
    undirectedList_ACyclic[1].push_back({ 1,0,-1 });
    undirectedList_ACyclic[1].push_back({ 1,2,-1 });
    undirectedList_ACyclic[2].push_back({ 2,1,-1 });
    undirectedList_ACyclic[3].push_back({ 3,0,-1 });
    undirectedList_ACyclic[3].push_back({ 3,4,-1 });
    undirectedList_ACyclic[4].push_back({ 4,3,-1 });



    /*

        1 --- 0
              |\
              | 3
              |/
              2

    */
    list<Edge> undirectedList_Cyclic[n];
    undirectedList_Cyclic[0].push_back({ 0,1,-1 });
    undirectedList_Cyclic[0].push_back({ 0,2,-1 });
    undirectedList_Cyclic[0].push_back({ 0,3,-1 });
    undirectedList_Cyclic[1].push_back({ 1,0,-1 });
    undirectedList_Cyclic[2].push_back({ 2,0,-1 });
    undirectedList_Cyclic[2].push_back({ 2,3,-1 });
    undirectedList_Cyclic[3].push_back({ 3,0,-1 });
    undirectedList_Cyclic[3].push_back({ 3,2,-1 });



    /*

        1 --> 0
              |^
              | \
              | 3
              | ^
              v/
              2

    */
    list<Edge> directedList_Cyclic[n];
    directedList_Cyclic[0].push_back({ 0,2,-1 });
    directedList_Cyclic[1].push_back({ 1,0,-1 });
    directedList_Cyclic[2].push_back({ 2,3,-1 });
    directedList_Cyclic[3].push_back({ 3,0,-1 });



    /*

            0
           / \
          /   \
         v     v
        2       1
         \     /
          \   /
           v v
            3

    */
    list<Edge> directedList_ACyclic[n];
    directedList_ACyclic[0].push_back({ 0,2,-1 });
    directedList_ACyclic[0].push_back({ 0,1,-1 });
    directedList_ACyclic[1].push_back({ 1,3,-1 });
    directedList_ACyclic[2].push_back({ 2,3,-1 });

    cout << cycleDetectionUndirected(undirectedList_ACyclic, n) << endl;
    cout << cycleDetectionUndirected(undirectedList_Cyclic, n) << endl;

    cout << cycleDetectionDirected(directedList_ACyclic, n) << endl;
    cout << cycleDetectionDirected(directedList_Cyclic, n) << endl;

    return 0;
}