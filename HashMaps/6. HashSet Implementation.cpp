/*
    Probleam: HashSet Implementation.
*/

#include <iostream>
#include <string>
#include <math.h>

using namespace std;
class Node {
public:
    string value;
    Node* next;

    Node(string value1) {
        value = value1;
    }
};

class HashMap {
    Node* nodes[10] = { NULL };

    int getHash(string value) {
        int hash_val = abs(static_cast<int>(hash<string>{}(value)));
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

    void put(string value, int hash) {
        Node* row = nodes[hash];
        if (row == NULL) {
            nodes[hash] = new Node(value);
            return;
        }
        while (row->next != NULL) {
            row = row->next;
        }
        row->next = new Node(value);
    }

    Node* find(string value, int hash) {
        Node* row = nodes[hash];
        while (row != NULL) {
            if (value == row->value) {
                return row;
            }
            row = row->next;
        }
        return NULL;
    }

public:
    void add(string value) {
        int hash = getHash(value);
        if (!find(value, hash)) {
            put(value, hash);
        }
    }

    Node* getAll() {
        Node* node = new Node("-1");
        Node* n1 = node;
        for (int i = 0;i < 10;i++) {
            Node* n = nodes[i];
            while (n != NULL) {
                n1->next = new Node(n->value);
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
    bool find(string value) {
        int hash = getHash(value);
        Node* node = find(value, hash);
        return node != NULL;
    }
    void clear() {
        for (int i = 0;i < 10;i++) {
            delete nodes[i];
            nodes[i] = NULL;
        }
    }
};

int main() {
    HashMap hm;
    hm.add("11");
    hm.add("12");
    hm.add("13");
    hm.add("NULL");
    hm.add("15");
    hm.add("20");
    Node* node = hm.getAll();
    while (node != NULL) {
        cout << "Value:" << node->value << endl;
        node = node->next;
    }
    cout << (hm.find("11") ? "Key Found" : "Key Not Found") << endl;
    cout << (hm.find("54") ? "Key Found" : "Key Not Found") << endl;
    cout << hm.size() << endl;
    cout << hm.empty() << endl;
    hm.clear();
    cout << hm.size() << endl;
    cout << hm.empty() << endl;
    return 0;
}