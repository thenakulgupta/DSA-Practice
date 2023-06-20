/*
    Probleam: Prefix Problem.

    Test cases:
    Input:
    4
    zebra dog duck dove

    Output:
    z dog du dov

*/

#include <iostream>
using namespace std;
class Node {
public:
    Node* nodes[26] = { NULL };
    bool eow = false;
    int noOfSubNodes = 0;
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
            curr->nodes[idx]->noOfSubNodes += 1;
            curr = curr->nodes[idx];
        }
        curr->eow = true;
    }

    string findPrefixs(string str) {
        Node* curr = root;
        string prefix = "";
        for (int i = 0;i < str.length();i++) {
            int idx = str[i] - 'a';
            if (curr->nodes[idx] == NULL) {
                return "NULL";
            }
            prefix += (char)(idx + 'a');
            if (curr->nodes[idx]->noOfSubNodes == 1) {
                break;
            }
            curr = curr->nodes[idx];
        }
        return prefix;
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
    for (int i = 0;i < n;i++) {
        cout << t.findPrefixs(strs[i]) << " ";
    }
    return 0;
}