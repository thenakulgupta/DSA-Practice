/*
    Problem: Detect Cycle Using Union Find.
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

const int n = 5;
int par[n], rank1[n];

int find_function(int a) {
    if (par[a] == a) {
        return a;
    }
    par[a] = find_function(par[a]);
    return par[a];
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

bool detectCycle(list<Edge> edges[], int n) {
    for (int i = 0;i < n;i++) {
        for (auto edge : edges[i]) {
            if (edge.dest == -1) {
                continue;
            }
            int parA = find_function(edge.src);
            int parB = find_function(edge.dest);
            if (parA == parB) {
                return true;
            }
            else {
                union_function(edge.src, edge.dest);
            }
        }
    }
    return false;
}

int main() {
    /*
        0 ----- 3
        |       |
        |       |
        |       |
        1 ----- 2
    */
    for (int i = 0;i < n;i++) {
        par[i] = i;
        rank1[i] = 0;
    }
    list<Edge> edges[n];
    edges[0].push_back({ 0,1,0 });
    edges[1].push_back({ 1,2,0 });
    edges[2].push_back({ 2,3,0 });
    edges[3].push_back({ 3,0,0 });

    cout << detectCycle(edges, n);
    return 0;
}