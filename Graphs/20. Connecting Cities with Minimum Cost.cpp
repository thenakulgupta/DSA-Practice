/*
    Probleam: Connecting Cities with Minimum Cost.

    Input:
    5 5
    0 1 2 3 4
    1 0 5 0 7
    2 5 0 6 0
    3 0 6 0 0
    4 7 0 0 0

    Output:
    10
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
    bool operator()(PII below, PII above) {
        if (below.second > above.second) {
            return true;
        }
        return false;
    }
};

int minimumCostToConnectCities(list<Edge> edges[], int n) {
    bool* vis = new bool[n];
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
    priority_queue<PII, vector<PII>, Compare> pq;
    pq.push({ 0,0 });
    int ans = 0;
    while (!pq.empty()) {
        PII curr = pq.top();
        pq.pop();
        if (!vis[curr.first]) {
            vis[curr.first] = true;
            ans += curr.second;
            for (auto edge : edges[curr.first]) {
                pq.push({ edge.dest,edge.wt });
            }
        }
    }
    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;
    list<Edge> edges[n];
    int vis[m][n];
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            vis[i][j] = 0;
        }
    }
    for (int i = 0;i < m;i++) {
        for (int j = 0;j < n;j++) {
            int a;
            cin >> a;
            if (i != j && vis[i][j] == 0 && vis[j][i] == 0 && a != 0) {
                vis[i][j] = 1;
                vis[j][i] = 1;
                edges[i].push_back(Edge(i, j, a));
            }
        }
    }

    cout << minimumCostToConnectCities(edges, n);
    return 0;
}