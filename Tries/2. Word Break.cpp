/*
    Probleam: Word Break.

    Test cases:
    Input:
    6 ilikesamsung
    i like sam samsung mobile ice

    Output:
    1


    Input:
    6 ilikesung
    i like sam samsung mobile ice

    Output:
    0

*/

#include <iostream>
using namespace std;
class Node {
public:
    Node* nodes[26] = { NULL };
    bool eow = false;
};

class Trie {
    Node* root = new Node();
public:
    void insert(string str) {   // O(L)
        Node* curr = root;
        for (int i = 0;i < str.length();i++) {
            int idx = str[i] - 'a';
            if (curr->nodes[idx] == NULL) {
                curr->nodes[idx] = new Node();
            }
            curr = curr->nodes[idx];
        }
        curr->eow = true;
    }

    bool search(string str) {
        Node* curr = root;
        for (int i = 0;i < str.length();i++) {
            int idx = str[i] - 'a';
            if (curr->nodes[idx] == NULL) {
                return false;
            }
            curr = curr->nodes[idx];
        }
        return curr->eow;
    }

    bool wordBreak(string str) {
        if (str.length() == 0) {
            return true;
        }
        for (int i = 1;i <= str.length();i++) {
            if (search(str.substr(0, i)) && wordBreak(str.substr(i))) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int n;
    string find;
    cin >> n >> find;
    string strs[n];
    Trie t;
    for (int i = 0;i < n;i++) {
        cin >> strs[i];
        t.insert(strs[i]);
    }
    cout << t.wordBreak(find) << endl;
    return 0;
}