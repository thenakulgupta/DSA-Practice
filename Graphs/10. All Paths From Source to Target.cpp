/*
    Probleam: All Paths From Source to Target.
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

void findPathsUtil(list<Edge> edges[], int n, queue<int> q, int pos, int dest) {
    cout << pos << " ";
    if (pos == dest) {
        return;
    }
    for (auto edge : edges[pos]) {
        if (edge.dest != -1) {
            findPathsUtil(edges, n, q, edge.dest, dest);
        }
    }
}

void findPaths(list<Edge> edges[], int n, int s, int d) {
    queue<int> q;
    for (auto edge : edges[s]) {
        cout << s << " ";
        findPathsUtil(edges, n, q, edge.dest, d);
        cout << endl;
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
        v     |     v
        2     |     1
         \    |    ^
          \   |   /
           \  |  /
            v v /
              3

    */
    list<Edge> edges[n];
    edges[0].push_back({ 0,-1,-1 });
    edges[0].push_back({ 0, 3,-1 });
    edges[1].push_back({ 1,-1,-1 });
    edges[2].push_back({ 2, 3,-1 });
    edges[3].push_back({ 3, 1,-1 });
    edges[4].push_back({ 4, 0,-1 });
    edges[4].push_back({ 4, 1,-1 });
    edges[5].push_back({ 5, 0,-1 });
    edges[5].push_back({ 5, 2,-1 });

    int source = 5;
    int dest = 1;

    findPaths(edges, n, source, dest);

    return 0;
}