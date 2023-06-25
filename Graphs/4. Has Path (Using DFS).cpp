/*
    Probleam: Has Path (Using DFS).
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


bool visits[7];

bool checkHasPath(list<Edge> edges[], int src, int dest) {
    if (src == dest) {
        return true;
    }
    visits[src] = true;
    for (auto i : edges[src]) {
        if (visits[i.dest] == false && checkHasPath(edges, i.dest, dest)) {
            return true;
        }
    }
    return false;
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

    for (int i = 0;i < 7;i++) {
        visits[i] = false;
    }
    cout << checkHasPath(edges, 0, 5);

    return 0;
}