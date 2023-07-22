/*
    Probleam: Kosaraju's Algo.
*/

#include <iostream>
#include <list>
#include <stack>

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

stack<int> ts;
const int n = 5;
list<Edge> transposedEdges[n];
list<Edge> edges[n];

void topologicalSortUtil(int i, int* vis) {
    vis[i] = true;
    for (auto edge : edges[i]) {
        if (!vis[edge.dest]) {
            if (edge.dest != -1) {
                topologicalSortUtil(edge.dest, vis);
            }
        }
    }
    ts.push(i);
}

void topologicalSort() {
    int* vis = new int[n];
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            topologicalSortUtil(i, vis);
        }
    }
}

void transposeGraph() {
    for (int i = 0;i < n;i++) {
        for (auto edge : edges[i]) {
            if (edge.dest != -1) {
                transposedEdges[edge.dest].push_back({ edge.dest, edge.src, edge.weight });
            }
        }
    }
}

void DFSUtil(int* vis, int j) {
    cout << j << " ";
    vis[j] = true;
    for (auto i : transposedEdges[j]) {
        if (vis[i.dest] == false) {
            DFSUtil(vis, i.dest);
        }
    }
}

void DFS() {
    int* vis = new int[n];
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
    while (!ts.empty()) {
        int p = ts.top();
        if (!vis[p]) {
            DFSUtil(vis, p);
            cout << endl;
        }
        ts.pop();
    }
}


int main() {
    /*
        1 ---> 0 ---> 3
        ^     /       |
        |    /        |
        |   /         |
        |  v          v
         2            4
    */
    edges[0].push_back({ 0,2,-1 });
    edges[0].push_back({ 0,3,-1 });
    edges[1].push_back({ 1,0,-1 });
    edges[2].push_back({ 2,1,-1 });
    edges[3].push_back({ 3,4,-1 });
    edges[4].push_back({ 4,-1,-1 });

    topologicalSort();
    transposeGraph();
    DFS();

    return 0;
}