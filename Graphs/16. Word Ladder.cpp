/*
    Probleam: Word Ladder.

    Test Cases:
    Input #1
    7 TOON PLEA
    POON PLEE SAME POIE PLEA PLIE POIN

    Output #1
    7
*/

#include <iostream>
#include <queue>
using namespace std;

int wordLadder(vector<string> v, int n, string s, string t) {
    int ans = 0;
    queue<string> q;
    q.push(s);
    while (!q.empty()) {
        ans++;
        int len = q.size();
        string word = q.front();
        q.pop();
        for (int i = 0;i < len;i++) {
            for (int j = 0;j < s.size();j++) {
                string i_word = word;
                for (char a = 'A';a <= 'Z';a++) {
                    word[j] = a;
                    if (word == t) {
                        return ans + 1;
                    }
                    auto f = find(v.begin(), v.end(), word);
                    if (f == v.end()) {
                        continue;
                    }
                    v.erase(f);
                    q.push(word);
                }
                word = i_word;
            }
        }
    }
    return ans;
}

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    vector<string> v;
    for (int i = 0;i < n;i++) {
        string a;
        cin >> a;
        v.push_back(a);
    }
    cout << wordLadder(v, n, s, t);
    return 0;
}