/*
    Probleam: Connected Components.
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

void dfsUtil(list<Edge> edges[], int n, bool* visits) {
    cout << n << " ";
    visits[n] = true;
    for (auto i : edges[n]) {
        if (visits[i.dest] == false) {
            dfsUtil(edges, i.dest, visits);
        }
    }
}

void dfs(list<Edge> edges[], int n) {
    bool* visits = new bool[n];
    for (int i = 0;i < n;i++) {
        visits[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (visits[i] == false) {
            dfsUtil(edges, i, visits);
        }
    }
}

void bfsUtil(list<Edge> edges[], bool visits[], int i) {
    queue<int> q;
    q.push(i);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (visits[curr] == false) {
            cout << curr << " ";
            visits[curr] = true;
            for (auto i : edges[curr]) {
                q.push(i.dest);
            }
        }
    }
}

void bfs(list<Edge> edges[], int n) {
    bool visits[7] = { false };
    for (int i = 0;i < n;i++) {
        bfsUtil(edges, visits, i);
    }
}

int main() {

    /*
          0                 4 --- 5
         / \                     /
        /   \                   /
       1     2                 6
              \
               \
                3

    */
    list<Edge> edges[7];
    edges[0].push_back({ 0,1,-1 });
    edges[0].push_back({ 0,2,-1 });
    edges[1].push_back({ 1,0,-1 });
    edges[2].push_back({ 2,0,-1 });
    edges[2].push_back({ 2,3,-1 });
    edges[3].push_back({ 3,2,-1 });

    edges[4].push_back({ 4,5,-1 });
    edges[5].push_back({ 5,4,-1 });
    edges[5].push_back({ 5,6,-1 });
    edges[6].push_back({ 6,5,-1 });

    bfs(edges, 7);
    cout << endl;
    dfs(edges, 7);

    return 0;
}