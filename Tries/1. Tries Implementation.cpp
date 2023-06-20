/*
    Probleam: Tries Implementation.

    Test cases:
    Input:
    6
    the a there their any thee
    the
    ther

    Output:
    String Found
    String Not Found

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
};

int main() {
    int n;
    cin >> n;
    string strs[n];
    Trie t;
    for (int i = 0;i < n;i++) {
        cin >> strs[i];
        t.insert(strs[i]);
    }
    string find;
    cin >> find;
    cout << "String " << (t.search(find) ? "Found" : "Not Found") << endl;
    cin >> find;
    cout << "String " << (t.search(find) ? "Found" : "Not Found") << endl;
    return 0;
}