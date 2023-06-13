/*
    Probleam: LinkedHashMap Implementation.
*/

#include <iostream>
#include <string>

using namespace std;
class Node {
public:
    string key;
    int value;
    Node* next;
    Node* prev;

    Node(string key1, int value1) {
        key = key1;
        value = value1;
        next = NULL;
        prev = NULL;
    }
};

class LinkedHashMap {
    Node* head = NULL;
    Node* tail = NULL;

    void put(string key, int value) {
        Node* newNode = new Node(key, value);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void edit(string key, int value) {
        Node* row = head;
        while (row != NULL) {
            if (key == row->key) {
                row->value = value;
                break;
            }
            row = row->next;
        }
    }
    Node* findAndGet(string key) {
        Node* row = head;
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
        Node* node = findAndGet(key);
        return node != NULL;
    }
    int get(string key) {
        Node* node = findAndGet(key);
        return (node == NULL ? -1 : node->value);
    }

    void add(string key, int value) {
        if (findAndGet(key)) {
            edit(key, value);
        }
        else {
            put(key, value);
        }
    }

    Node* getAll() {
        return head;
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

int main() {
    LinkedHashMap lhm;
    lhm.add("a", 11);
    lhm.add("b", 12);
    lhm.add("c", 13);
    lhm.add("d", 14);
    lhm.add("e", 15);
    lhm.add("b", 20);
    Node* node = lhm.getAll();
    while (node != NULL) {
        cout << node->key << ":" << node->value << endl;
        node = node->next;
    }
    cout << lhm.get("b") << endl;
    cout << (lhm.find("b") ? "Key Found" : "Key Not Found") << endl;
    cout << (lhm.find("g") ? "Key Found" : "Key Not Found") << endl;
    cout << lhm.size() << endl;
    cout << lhm.empty() << endl;
    return 0;
}