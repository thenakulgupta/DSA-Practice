/*
    Probleam: Sort by Frequency.

    Inout:
    cccaaa

    Output:
    aaaccc


    Inout:
    trrree

    Output:
    rrreet
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Node {
public:
    string key;
    string value;
    Node* next;

    Node(string key1, string value1) {
        key = key1;
        value = value1;
    }
};

class Node1 {
public:
    string key;
    string value;
    Node1* left;
    Node1* right;

    Node1(string key1, string value1) {
        key = key1;
        value = value1;
    }
};

class HashMap {
    Node* nodes[10] = { NULL };

    int getHash(string key) {
        int hash_val = abs(static_cast<int>(hash<string>{}(key)));
        string hash_str = to_string(hash_val);
        int hash_1 = 0;
        while (1) {
            if (hash_str.length() >= 1) {
                hash_1 += (hash_str[hash_str.length() - 1] - '0');
                hash_str.pop_back();
            }
            else {
                break;
            }
            if (hash_str.length() == 0 && hash_1 > 9) {
                hash_str = to_string(hash_1);
                hash_1 = 0;
            }
        }
        return hash_1 - 1;
    }

    void put(string key, int hash, string value) {
        Node* row = nodes[hash];
        if (row == NULL) {
            nodes[hash] = new Node(key, value);
            return;
        }
        while (row->next != NULL) {
            row = row->next;
        }
        row->next = new Node(key, value);
    }

    void edit(string key, int hash, string value) {
        Node* row = nodes[hash];
        while (row != NULL) {
            if (key == row->key) {
                row->value = value;
                break;
            }
            row = row->next;
        }
    }
    Node* find(string key, int hash) {
        Node* row = nodes[hash];
        while (row != NULL) {
            if (key == row->key) {
                return row;
            }
            row = row->next;
        }
        return NULL;
    }

public:
    bool find(string key) {
        int hash = getHash(key);
        Node* node = find(key, hash);
        return node != NULL;
    }
    string get(string key) {
        int hash = getHash(key);
        Node* node = find(key, hash);
        return (node == NULL ? "NULL" : node->value);
    }

    void add(string key, string value) {
        int hash = getHash(key);
        if (find(key, hash)) {
            edit(key, hash, value);
        }
        else {
            put(key, hash, value);
        }
    }

    Node* getAll() {
        Node* node = new Node("init", "NULL");
        Node* n1 = node;
        for (int i = 0;i < 10;i++) {
            Node* n = nodes[i];
            while (n != NULL) {
                n1->next = new Node(n->key, n->value);
                n1 = n1->next;
                n = n->next;
            }
        }
        node = node->next;
        return node;
    }

    int size() {
        Node* node = getAll();
        int size = 0;
        while (node != NULL) {
            size += 1;
            node = node->next;
        }
        return size;
    }

    bool empty() {
        return getAll() == NULL;
    }
};

int intval(string str) {
    return stoi(str);
}

void print(Node1* node) {
    if (node == NULL) {
        return;
    }
    print(node->right);
    for (int i = 0;i < intval(node->value);i++) {
        cout << node->key;
    }
    print(node->left);
}

int main() {
    string str;
    cin >> str;
    HashMap hm;
    for (int i = 0;i < str.length();i++) {
        string s(1, str[i]);
        hm.add(s, hm.find(s) ? to_string(intval(hm.get(s)) + 1) : "1");
    }
    Node* node = hm.getAll();
    Node1* node1 = new Node1(node->key, node->value);
    node = node->next;
    Node1* n1 = node1;
    while (node != NULL) {
        while (n1 != NULL) {
            if (intval(node->value) >= intval(n1->value)) {
                if (n1->right == NULL) {
                    n1->right = new Node1(node->key, node->value);
                    break;
                }
                n1 = n1->right;
            }
            else if (intval(node->value) < intval(n1->value)) {
                if (n1->left == NULL) {
                    n1->left = new Node1(node->key, node->value);
                    break;
                }
                n1 = n1->left;
            }
        }
        node = node->next;
    }
    print(node1);
    return 0;
}