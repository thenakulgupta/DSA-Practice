/*
    Problem: Alien Dictionary.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> calculateIndegree(vector<vector<int>> v, int n) {
    vector<int> indegree(n, 0);
    for (int i = 0;i < n;i++) {
        for (auto a : v[i]) {
            indegree[a]++;
        }
    }
    return indegree;
}

bool alienDict(vector<string> str) {
    int n = 26;
    vector<vector<int>> v(n);
    for (int i = 0;i < str.size() - 1;i++) {
        string w1 = str[i];
        string w2 = str[i + 1];
        int len = min(w1.length(), w2.length());
        int j = 0;
        while (j < len) {
            if (w1[j] != w2[j]) {
                v[w1[j] - 'a'].push_back(w2[j] - 'a');
                break;
            }
            j++;
        }
    }
    vector<int> indegree = calculateIndegree(v, n);
    queue<int> q;
    for (int i = 0;i < n;i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (int n : v[curr]) {
            indegree[n]--;
            if (indegree[n] == 0) {
                q.push(n);
            }
        }
    }
    for (int i = 0;i < n;i++) {
        if (indegree[i] > 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> str;
    for (int i = 0;i < n;i++) {
        string a;
        cin >> a;
        str.push_back(a);
    }
    cout << alienDict(str);
    return 0;
}