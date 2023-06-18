/*
    Probleam: Bottom View of a Binary Tree.

    Output:
    14 10 5 3 25
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Node {
public:
    string key;
    int value;
    Node* next;

    Node(string key1, int value1) {
        key = key1;
        value = value1;
    }
};

class Node1 {
public:
    int data;
    Node1* left;
    Node1* right;

    Node1(int data1) {
        data = data1;
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

    void put(string key, int hash, int value) {
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

    void edit(string key, int hash, int value) {
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
    int get(string key) {
        int hash = getHash(key);
        Node* node = find(key, hash);
        return (node == NULL ? -1 : node->value);
    }

    void add(string key, int value) {
        int hash = getHash(key);
        if (find(key, hash)) {
            edit(key, hash, value);
        }
        else {
            put(key, hash, value);
        }
    }

    Node* getAll() {
        Node* node = new Node("init", -1);
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

void calculateNodes(Node1* n, HashMap* hm, int val = 0) {
    if (n == NULL) {
        return;
    }
    hm->add(to_string(val), n->data);
    calculateNodes(n->right, hm, val + 1);
    calculateNodes(n->left, hm, val - 1);
}

int main() {
    int n;
    cin >> n;
    Node1* n1 = new Node1(20);
    n1->left = new Node1(8);
    n1->left->left = new Node1(5);
    n1->left->right = new Node1(3);
    n1->left->right->left = new Node1(10);
    n1->left->right->right = new Node1(14);
    n1->right = new Node1(22);
    n1->right->right = new Node1(25);

    HashMap* hm = new HashMap();
    calculateNodes(n1, hm);

    Node* node = hm->getAll();
    while (node != NULL) {
        cout << node->value << " ";
        node = node->next;
    }
    return 0;
}