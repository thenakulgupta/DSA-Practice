/*
    Probleam: Topological Sorting using BFS.
*/

#include <iostream>
#include <list>
#include <queue>

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

void topologicalSortBFSUtil(list<Edge> edges[], int n, int* indegree, queue<int> q, int pos) {
    if (indegree[pos] == 0) {
        q.push(pos);
    }
    else {
        indegree[pos] -= 1;
    }
    while (!q.empty()) {
        int val = q.front();
        cout << val << " ";
        q.pop();
        for (auto edge : edges[pos]) {
            topologicalSortBFSUtil(edges, n, indegree, q, edge.dest);
        }
    }
}

void topologicalSortBFS(list<Edge> edges[], int n) {
    queue<int> q;
    int* indegree = new int[n];
    for (int i = 0;i < n;i++) {
        indegree[i] = 0;
    }
    for (int i = 0;i < n;i++) {
        for (auto edge : edges[i]) {
            indegree[edge.dest] += 1;
        }
    }
    for (int i = 0;i < n;i++) {
        topologicalSortBFSUtil(edges, n, indegree, q, i);
    }
}

int main() {
    int n = 6;
    /*

        5           4
        |\         /|
        | \       / |
        |  \     /  |
        |   v   v   |
        |     0     |
        v           v
        2           1
         \         ^
          \       /
           \     /
            v   /
              3

    */
    list<Edge> edges[n];
    edges[0].push_back({ 0,-1,-1 });
    edges[1].push_back({ 1,-1,-1 });
    edges[2].push_back({ 2, 3,-1 });
    edges[3].push_back({ 3, 1,-1 });
    edges[4].push_back({ 4, 0,-1 });
    edges[4].push_back({ 4, 1,-1 });
    edges[5].push_back({ 5, 0,-1 });
    edges[5].push_back({ 5, 2,-1 });

    topologicalSortBFS(edges, n);
    cout << endl;

    return 0;
}