/*
    Probleam: Articulation Point (Tarjan's Algo).
*/

#include <iostream>
#include <list>
#include <stack>

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

const int n = 6;
list<Edge> edges[n];
int* dt = new int[n];
int* low = new int[n];
bool* vis = new bool[n];
bool* ap = new bool[n];
int cTime = 0;

void articulationPointTarjanAlgoUtil(int j, int par = -1) {
    vis[j] = true;
    dt[j] = low[j] = ++cTime;
    int children = 0;
    for (auto i : edges[j]) {
        if (i.dest == par) {
            continue;
        }
        else if (vis[i.dest] == true) {
            low[i.src] = min(low[i.src], dt[i.dest]);
        }
        else {
            articulationPointTarjanAlgoUtil(i.dest, i.src);
            low[i.src] = min(low[i.src], low[i.dest]);
            if (dt[i.src] <= low[i.dest]) {
                ap[j] = true;
            }
            children++;
        }
    }
    if (par != -1 && children > 1) {
        ap[j] = true;
    }
}

void articulationPointTarjanAlgo() {
    for (int i = 0;i < n;i++) {
        dt[i] = 0;
        low[i] = 0;
        vis[i] = false;
        ap[i] = false;
    }
    for (int i = 0;i < n;i++) {
        if (!vis[i]) {
            articulationPointTarjanAlgoUtil(i);
        }
    }
    for (int i = 0;i < n;i++) {
        if (ap[i]) {
            cout << "Articulation Point: " << i << endl;
        }
    }
}

int main() {
    /*
        1 ----- 0 ---- 3
        |      /       |
        |     /        |
        |    /         |
        |   /          |
        |  /           |
        | /            |
        2              4
    */
    edges[0].push_back({ 0,1,-1 });
    edges[0].push_back({ 0,2,-1 });
    edges[0].push_back({ 0,3,-1 });
    edges[1].push_back({ 1,0,-1 });
    edges[1].push_back({ 1,2,-1 });
    edges[2].push_back({ 2,0,-1 });
    edges[2].push_back({ 2,1,-1 });
    edges[3].push_back({ 3,0,-1 });
    edges[3].push_back({ 3,4,-1 });
    edges[3].push_back({ 3,5,-1 });
    edges[4].push_back({ 4,3,-1 });
    edges[4].push_back({ 4,5,-1 });
    edges[5].push_back({ 5,3,-1 });
    edges[5].push_back({ 5,4,-1 });

    articulationPointTarjanAlgo();

    return 0;
}