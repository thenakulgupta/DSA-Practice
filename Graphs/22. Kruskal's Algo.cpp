/*
    Probleam: Kruskal's Algo.
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

const int n = 7;
int par[n], rank1[n];

int find_function(int a) {
    if (par[a] == a) {
        return a;
    }
    return find_function(par[a]);
}

void union_function(int a, int b) {
    int parA = find_function(a);
    int parB = find_function(b);
    if (rank1[parA] == rank1[parB]) {
        par[parB] = parA;
        rank1[parA] += 1;
    }
    else if (rank1[parA] < rank1[parB]) {
        par[parA] = parB;
    }
    else {
        par[parB] = parA;
    }
}

int kruskalAlgo(list<Edge*> edges[], int n) {
    bool* vis = new bool[n];
    for (int i = 0;i < n;i++) {
        vis[i] = false;
    }
    int ans = 0;
    int count = 0;

    for (int i = 0;count < n - 1;i++) {
        for (auto e : edges[i]) {
            int parA = find_function(e->src);
            int parB = find_function(e->dest);
            if (!vis[e->dest] && parA != parB) {
                vis[e->dest] = true;
                union_function(e->src, e->dest);
                ans += e->wt;
                count++;
            }
        }
    }
    return ans;
}

int main() {
    /*
             0 ---- 2
           /  \    /
          /    \  /
         1 ---- 3
    */

    for (int i = 0;i < n;i++) {
        par[i] = i;
        rank1[i] = 0;
    }

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

    cout << kruskalAlgo(edges, n);
    return 0;
}