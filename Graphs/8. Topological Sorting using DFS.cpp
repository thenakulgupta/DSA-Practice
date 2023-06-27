/*
    Probleam: Topological Sorting using DFS.
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

stack<int> stack1;

void topologicalSortDFSUtil(list<Edge> edges[], int n, bool* visited, int pos) {
    visited[pos] = true;
    for (auto edge : edges[pos]) {
        if (visited[edge.dest] == false) {
            if (edge.dest != -1) {
                topologicalSortDFSUtil(edges, n, visited, edge.dest);
            }
        }
    }
    stack1.push(pos);
}

void topologicalSortDFS(list<Edge> edges[], int n) {
    bool* visited = new bool[n];
    for (int i = 0;i < n;i++) {
        visited[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (visited[i] == false) {
            topologicalSortDFSUtil(edges, n, visited, i);
        }
    }
    while (!stack1.empty()) {
        cout << stack1.top() << " ";
        stack1.pop();
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

    topologicalSortDFS(edges, n);
    cout << endl;

    return 0;
}