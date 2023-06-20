/*
    Probleam: startsWith Problem.

    Test cases:
    Input:
    5 app
    apple app mango man woman

    Output:
    1


    Input:
    5 moon
    apple app mango man woman

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

    bool startsWith(string str) {
        Node* curr = root;
        for (int i = 0;i < str.length();i++) {
            int idx = str[i] - 'a';
            if (curr->nodes[idx] == NULL) {
                return false;
            }
            curr = curr->nodes[idx];
        }
        return true;
    }
};

int main() {
    int n;
    string str;
    cin >> n >> str;
    string strs[n];
    Trie t;
    for (int i = 0;i < n;i++) {
        cin >> strs[i];
        t.insert(strs[i]);
    }
    cout << t.startsWith(str) << " ";
    return 0;
}