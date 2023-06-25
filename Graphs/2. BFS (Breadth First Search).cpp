/*
    Probleam: BFS (Breadth First Search).
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


void bfs(list<Edge> edges[]) {
    queue<int> q;
    bool arr[7] = { false };
    q.push(0);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (arr[curr] == false) {
            cout << curr << " ";
            arr[curr] = true;
            for (auto i : edges[curr]) {
                q.push(i.dest);
            }
        }
    }
}

int main() {
    /*
          1 --- 3
         /      | \
        0       |  5 --- 6
         \      | /
          2 --- 4

    */
    list<Edge> edges[7];
    edges[0].push_back({ 0,1,-1 });
    edges[0].push_back({ 0,2,-1 });
    edges[1].push_back({ 1,0,-1 });
    edges[1].push_back({ 1,3,-1 });
    edges[2].push_back({ 2,0,-1 });
    edges[2].push_back({ 2,4,-1 });
    edges[3].push_back({ 3,1,-1 });
    edges[3].push_back({ 3,4,-1 });
    edges[3].push_back({ 3,5,-1 });
    edges[4].push_back({ 4,2,-1 });
    edges[4].push_back({ 4,3,-1 });
    edges[4].push_back({ 4,5,-1 });
    edges[5].push_back({ 5,3,-1 });
    edges[5].push_back({ 5,4,-1 });
    edges[5].push_back({ 5,6,-1 });
    edges[6].push_back({ 6,5,-1 });

    bfs(edges);
    return 0;
}