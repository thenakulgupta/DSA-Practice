/*
    Probleam: Cheapest Price of Flight.
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

class Info {
public:
    int vertex;
    int path;
    int stops;
    Info(int v, int p, int s) {
        vertex = v;
        path = p;
        stops = s;
    }
};

int cheapestFlight(list<Edge> edges[], int n, int s, int d, int k) {
    int* distance = new int[n];
    bool* vis = new bool[n];
    distance[0] = 0;
    for (int i = 1;i < n;i++) {
        distance[i] = INT_MAX;
    }
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
    queue<Info> q;
    q.push({ s,0,0 });
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        if (p.stops > k) {
            break;
        }
        if (!vis[p.vertex]) {
            vis[p.vertex] = true;
            for (auto edge : edges[p.vertex]) {
                if (distance[edge.src] + edge.wt < distance[edge.dest]) {
                    distance[edge.dest] = distance[edge.src] + edge.wt;
                    q.push({ edge.dest, p.path + distance[edge.dest], p.stops + 1 });
                }
            }
        }
    }
    return distance[d] == INT_MAX ? -1 : distance[d];
}

int main() {
    /*
             0
       100 /   \ 100
          v 100 v
         1 ----> 2
      600 \     / 200
           v  v
            3
    */
    int n = 5;
    list<Edge> edges[n];
    edges[0].push_back(Edge(0, 1, 100));
    edges[1].push_back(Edge(1, 2, 100));
    edges[1].push_back(Edge(1, 3, 600));
    edges[2].push_back(Edge(2, 0, 100));
    edges[2].push_back(Edge(2, 3, 200));

    int s = 0;
    int d = 3;
    int k = 1;

    cout << cheapestFlight(edges, n, s, d, k);
    return 0;
}