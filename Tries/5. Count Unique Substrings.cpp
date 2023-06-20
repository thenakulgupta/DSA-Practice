/*
    Probleam: Count Unique Substrings.

    Test cases:
    Input:
    ababa

    Output:
    Count: 10

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

    int uniqueSubStrs(Node* curr = NULL, bool init = false) {
        if (curr == NULL) {
            if (init == true) {
                curr = root;
            }
            else {
                return 0;
            }
        }
        int count = 1;
        for (int i = 0;i < 26;i++) {
            int c = uniqueSubStrs(curr->nodes[i]);
            count += c;
        }
        return count;
    }
};

int main() {
    string str;
    cin >> str;
    Trie t;
    string tempStr = "";
    for (int i = str.length() - 1;i >= 0;i--) {
        tempStr = str[i] + tempStr;
        t.insert(tempStr);
    }
    cout << "Count: " << t.uniqueSubStrs(NULL, true);
    return 0;
}