/*
    Probleam: Group Anagrams Together.

    Test cases:
    Input:
    6
    eat tea tan ate nat bat

    Output:
    bat
    eat tea ate
    tan nat

*/

#include <iostream>
#include <vector>

using namespace std;
class Node {
public:
    Node* nodes[26] = { NULL };
    bool eow = false;
    vector<string> data;
};

class Trie {
    Node* root = new Node();
    vector<vector<string>> ans;
public:
    void insert(string str) {   // O(L)
        string s = str;
        sort(s.begin(), s.end());
        Node* curr = root;
        for (int i = 0;i < s.length();i++) {
            int idx = s[i] - 'a';
            if (curr->nodes[idx] == NULL) {
                curr->nodes[idx] = new Node();
            }
            curr = curr->nodes[idx];
        }
        curr->eow = true;
        curr->data.push_back(str);
    }

    vector<vector<string>> groupAnagrams(Node* curr = NULL, bool init = false) {
        if (curr == NULL) {
            if (init == true) {
                curr = root;
            }
            else {
                return {};
            }
        }
        if (curr->eow == true) {
            ans.push_back(curr->data);
        }
        for (int i = 0;i < 26;i++) {
            groupAnagrams(curr->nodes[i]);
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    string str;
    Trie t;
    for (int i = 0;i < n;i++) {
        cin >> str;
        t.insert(str);
    }
    vector<vector<string>> anagrams = t.groupAnagrams(NULL, true);
    for (auto a : anagrams) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}