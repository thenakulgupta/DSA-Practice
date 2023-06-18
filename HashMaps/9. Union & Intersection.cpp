/*
    Probleam: Find Itinerary for Tickets.

    Input:
    4
    Chennai Bengaluru
    Mumbai Delhi
    Goa Chennai
    Delhi Goa

    Output:
    Mumbai -> Delhi -> Goa -> Chennai -> Bengaluru
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class HashMap {
public:
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

    void remove(string key) {
        int hash = getHash(key);
        if (find(key, hash)) {
            remove(key, hash);
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

private:

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

    void remove(string key, int hash) {
        Node* row = nodes[hash];
        if (row->key == key) {
            nodes[hash] = row->next;
            return;
        }
        while (row->next != NULL) {
            if (key == row->next->key) {
                row->next = row->next->next;
            }
            row = row->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    HashMap hm;
    HashMap hm1;
    for (int i = 0;i < n;i++) {
        string a, b;
        cin >> a >> b;
        hm.add(a, b);
        hm1.add(b, a);
    }
    string sp;
    HashMap::Node* node = hm1.getAll();
    while (node != NULL) {
        if (!hm1.find(node->value)) {
            sp = node->value;
            break;
        }
        node = node->next;
    }
    cout << sp;
    while (1) {
        sp = hm.get(sp);
        if (sp == "NULL") {
            break;
        }
        cout << " -> " << sp;
    }
    return 0;
}