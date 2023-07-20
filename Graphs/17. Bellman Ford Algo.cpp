/*
    Probleam: Bellman Ford Algo.
*/

#include <iostream>
#include <list>
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

void bellmanFordAlgo(list<Edge*> edges[], int n) {
    int u = 0;
    int v = n;
    int* distance = new int[n];
    int* visited = new int[n];
    distance[0] = 0;
    for (int i = 1;i < n;i++) {
        distance[i] = INT_MAX;
    }
    for (int i = 0;i < n;i++) {
        visited[i] = 0;
    }
    for (int i = u;i < v - 1;i++) {
        for (int j = 0;j < n;j++) {
            if (!visited[j]) {
                visited[j] = true;
                for (auto edge : edges[j]) {
                    if (distance[edge->src] != INT_MAX && (distance[edge->src] + edge->wt) < distance[edge->dest]) {
                        distance[edge->dest] = distance[edge->src] + edge->wt;
                    }
                }
            }
        }
    }
    for (int i = 0;i < n;i++) {
        cout << distance[i] << " ";
    }
}

int main() {
    int n = 5;
    list<Edge*> edges[n];
    edges[0].push_back(new Edge(0, 1, 2));
    edges[0].push_back(new Edge(0, 2, 4));
    edges[1].push_back(new Edge(1, 2, -4));
    edges[2].push_back(new Edge(2, 3, 2));
    edges[3].push_back(new Edge(3, 4, 4));
    edges[4].push_back(new Edge(4, 1, -1));

    bellmanFordAlgo(edges, n);
    return 0;
}