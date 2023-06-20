/*
    Probleam: Longest word with all prefix.

    Test cases:
    Input:
    7
    a banana app appl ap apply apple

    Output:
    apple

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

    string getLongestWord(Node* curr = NULL, bool init = false, string word = "") {
        if (curr == NULL) {
            if (init == true) {
                curr = root;
            }
            else {
                return word;
            }
        }
        string lw = word;
        for (int i = 0;i < 26;i++) {
            if (curr->nodes[i] != NULL && curr->nodes[i]->eow == true) {
                string w = getLongestWord(curr->nodes[i], false, word + char(i + 'a'));
                if (w.length() > lw.length()) {
                    lw = w;
                }
            }

        }
        return lw;
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
    cout << t.getLongestWord(NULL, true);
    return 0;
}