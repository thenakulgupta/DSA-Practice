/*
    Problem: Find whether is it possible to finish all tasks or not.

    Input #1:
    2
    1 0
    0 1

    Output #1:
    0


    Input #2
    1
    1 0

    Output #2
    1
*/

#include <iostream>
#include <vector>
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
int find_function(int a, int* par) {
    if (par[a] == a) {
        return a;
    }
    par[a] = find_function(par[a], par);
    return par[a];
}

void union_function(int a, int b, int* par, int* rank1) {
    int parA = find_function(a, par);
    int parB = find_function(b, par);
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

bool checkPossibilityToFinishTask(vector<pair<int, int>> v, int* par, int* rank1) {
    for (int i = 0;i < v.size();i++) {
        int parA = find_function(v[i].first, par);
        int parB = find_function(v[i].second, par);
        if (parA == parB) {
            return false;
        }
        else {
            union_function(v[i].first, v[i].second, par, rank1);
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    int maxN = INT_MIN;
    vector<pair<int, int>> v;
    for (int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        maxN = max(maxN, max(a, b));
        v.push_back({ a,b });
    }
    int* par = new int[maxN];
    int* rank1 = new int[maxN];
    for (int i = 0;i <= maxN;i++) {
        par[i] = i;
        rank1[i] = 0;
    }
    cout << checkPossibilityToFinishTask(v, par, rank1);
    return 0;
}