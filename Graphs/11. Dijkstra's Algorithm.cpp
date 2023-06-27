/*
    Probleam: Dijkstra's Algorithm.
*/

#include <iostream>
#include <list>
#include <queue>

#define PII pair<int, int>

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

class Compare {
public:
    bool operator()(PII below, PII above)
    {
        if (below.second > above.second) {
            return true;
        }

        return false;
    }
};

void dijkstraAlgo(list<Edge> edges[], int n, int s) {
    int* distance = new int[n];
    int* visited = new int[n];
    distance[0] = 0;
    for (int i = 1;i < n;i++) {
        distance[i] = INT_MAX;
    }
    for (int i = 0;i < n;i++) {
        visited[i] = 0;
    }
    priority_queue < PII, vector<PII>, Compare> pq;
    pq.push({ s,0 });
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        if (!visited[p.first]) {
            visited[p.first] = true;
            for (auto edge : edges[p.first]) {
                if (edge.dest != -1) {
                    if (distance[edge.src] + edge.weight < distance[edge.dest]) {
                        distance[edge.dest] = distance[edge.src] + edge.weight;
                        pq.push({ edge.dest, distance[edge.dest] });
                    }
                }
            }
        }
    }
    cout << endl;

    for (int i = 0;i < n;i++) {
        cout << i << ": " << distance[i] << endl;
    }
}

int main() {
    int n = 6;
    /*
            1 --> 3
           ^|     ^\
         /  |     | v
        0   |     |  5
         \  |     | ^
          v v     |/
            2 --> 4

    */
    list<Edge> edges[n];
    edges[0].push_back({ 0,1,2 });
    edges[0].push_back({ 0,2,4 });
    edges[1].push_back({ 1,2,1 });
    edges[1].push_back({ 1,3,7 });
    edges[2].push_back({ 2,4,3 });
    edges[3].push_back({ 3,5,1 });
    edges[4].push_back({ 4,3,2 });
    edges[4].push_back({ 4,5,5 });
    edges[5].push_back({ 5,-1,-1 });

    int source = 0;

    dijkstraAlgo(edges, n, source);

    return 0;
}