/*
    Probleam: Prim's Algo.
*/

#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;

#define PII pair<int, int>

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

int primAlgo(list<Edge*> edges[], int n) {
    bool* vis = new bool[n];
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
    priority_queue<PII, vector<PII>, Compare>pq;
    pq.push({ 0,0 });
    int ans = 0;
    while (!pq.empty()) {
        PII pii = pq.top();
        pq.pop();
        if (!vis[pii.first]) {
            vis[pii.first] = true;
            ans += pii.second;
            for (auto e : edges[pii.first]) {
                pq.push({ e->dest,e->wt });
            }
        }
    }
    return ans;
}

int main() {
    int n = 4;
    list<Edge*> edges[n];
    edges[0].push_back(new Edge(0, 1, 10));
    edges[0].push_back(new Edge(0, 3, 30));
    edges[0].push_back(new Edge(0, 2, 15));
    edges[1].push_back(new Edge(1, 0, 10));
    edges[1].push_back(new Edge(1, 3, 40));
    edges[2].push_back(new Edge(2, 0, 15));
    edges[2].push_back(new Edge(2, 3, 50));
    edges[3].push_back(new Edge(3, 1, 40));
    edges[3].push_back(new Edge(3, 0, 30));
    edges[3].push_back(new Edge(3, 2, 50));

    cout << primAlgo(edges, n);
    return 0;
}