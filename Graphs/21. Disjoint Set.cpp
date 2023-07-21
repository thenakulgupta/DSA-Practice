/*
    Probleam: Disjoint Set.

    Output:
    3
    1
    1
    1
*/

#include <iostream>
using namespace std;

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

int main() {
    for (int i = 0;i < n;i++) {
        par[i] = i;
        rank1[i] = 0;
    }
    cout << find_function(3) << endl;
    union_function(1, 3);
    cout << find_function(3) << endl;
    union_function(2, 4);
    union_function(3, 6);
    union_function(1, 4);
    cout << find_function(3) << endl;
    cout << find_function(4) << endl;
    union_function(1, 5);
    return 0;
}