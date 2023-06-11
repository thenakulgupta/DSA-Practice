/*
    Probleam: Minimum time required to fill given N slots.

    Test cases:
    Input:
    5 5
    1 2 3 4 5

    Output:
    2


    Input:
    6 2
    2 6

    Output:
    2




    Getting index value
    Parent To Child:
        left: 2i +1
        right: 2i + 2

    Child to Parent: (x-1)/2
*/


#include <iostream>
#include <queue>
using namespace std;

void findMinTime(int arr[], int n, int k) {
    queue<int> q;
    bool vis[n + 1];
    int time = 0;
    for (int i = 0;i < n + 1;i++) {
        vis[i] = false;
    }
    for (int i = 0;i < k;i++) {
        q.push(arr[i]);
        vis[arr[i]] = true;
    }
    while (q.size() > 0) {
        for (int i = 0;i < q.size();i++) {
            int curr = q.front();
            q.pop();
            if (curr - 1 >= 1 && !vis[curr - 1]) {
                vis[curr - 1] = true;
                q.push(curr - 1);
            }
            if (curr + 1 <= n && !vis[curr + 1]) {
                vis[curr + 1] = true;
                q.push(curr + 1);
            }
        }
        time += 1;
    }
    cout << (time - 1);
}

int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0;i < n;i++) {
        cin >> arr[i];
    }
    findMinTime(arr, n, k);
    return 0;
}
