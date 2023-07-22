/*
    Probleam: Mother Vertex.

    Output:
    0 1 2
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Edge {
public:
    int src;
    int dest;
    int wt;
    Edge(int s, int d, int w) {
        src = s;
        dest = d;
        wt = w;
    }
};

void resetVisit(bool* vis, int n) {
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
}

void findMotherVertex(list<Edge> edges[], int n) {
    bool* vis = new bool[n];
    for (int i = 0;i < n;i++) {
        resetVisit(vis, n);
        queue<int> q;
        q.push(i);
        while (!q.empty()) {
            int p = q.front();
            q.pop();
            for (auto edge : edges[p]) {
                if (!vis[edge.dest]) {
                    vis[edge.dest] = true;
                    if (edge.dest == -1) {
                        continue;
                    }
                    q.push(edge.dest);
                }
            }
        }
        bool isMotherVertex = true;
        for (int j = 0;j < n;j++) {
            if (!vis[j]) {
                isMotherVertex = false;
                break;
            }
        }
        if (isMotherVertex) {
            cout << i << " ";
        }
    }
}

int main() {
    /*
        1 ----> 0
        ^      / \
         \    /   \
          \  v     v
            2      3
                  /
                 /
                v
                4
    */
    int n = 5;
    list<Edge> edges[n];
    edges[0].push_back({ 0,2,0 });
    edges[0].push_back({ 0,3,0 });
    edges[1].push_back({ 1,0,0 });
    edges[2].push_back({ 2,1,0 });
    edges[3].push_back({ 3,4,0 });
    edges[4].push_back({ 4,-1,0 });

    findMotherVertex(edges, n);
    return 0;
}