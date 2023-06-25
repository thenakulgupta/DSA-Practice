/*
    Probleam: Bipartite Graph.



    Shortcut to check if a graph is Bipartite or not.

    Acyclic: TRUE
    Even Cycle: TRUE
    Odd Cycle: FALSE
*/

#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Edge {
public:
    int src;
    int dest;
    int color;
    Edge(int s, int d) {
        src = s;
        dest = d;
    }
};

bool checkIsBipartiteGraphUtil(list<Edge> edges[], int n, int pos, queue<int> q, int* col) {
    q.push(pos);
    col[pos] = 0;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto i : edges[curr]) {
            if (col[i.dest] == -1) {
                col[i.dest] = 1 - col[curr];
                q.push(i.dest);
            }
            else if (col[i.dest] == col[curr]) {
                return false;
            }
        }
    }
    return true;
}

bool checkIsBipartiteGraph(list<Edge> edges[], int n) {
    queue<int> q;
    int* col = new int[n];
    for (int i = 0;i < n;i++) {
        col[i] = -1;
    }
    for (int i = 0;i < n;i++) {
        if (col[i] == -1) {
            if (checkIsBipartiteGraphUtil(edges, n, i, q, col)) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    /*
            0                   0
          /   \               /   \
         1     2            /       \
          \   /            /         \
            3             1           2
                           \         /
                            \       /
                             3 --- 4

    */
    list<Edge> edges1[4];
    edges1[0].push_back({ 0,1 });
    edges1[0].push_back({ 0,2 });
    edges1[1].push_back({ 1,0 });
    edges1[1].push_back({ 1,3 });
    edges1[2].push_back({ 2,3 });
    edges1[2].push_back({ 2,0 });
    edges1[3].push_back({ 3,1 });
    edges1[3].push_back({ 3,2 });

    list<Edge> edges2[5];
    edges2[0].push_back({ 0,1 });
    edges2[0].push_back({ 0,2 });
    edges2[1].push_back({ 1,0 });
    edges2[1].push_back({ 1,3 });
    edges2[2].push_back({ 2,4 });
    edges2[2].push_back({ 2,0 });
    edges2[3].push_back({ 3,1 });
    edges2[3].push_back({ 3,4 });
    edges2[4].push_back({ 4,3 });
    edges2[4].push_back({ 4,2 });

    cout << checkIsBipartiteGraph(edges1, 4) << endl;
    cout << checkIsBipartiteGraph(edges2, 5);
    return 0;
}