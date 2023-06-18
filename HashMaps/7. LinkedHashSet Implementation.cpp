/*
    Probleam: LinkedHashSet Implementation.
*/

#include <iostream>
#include <string>

using namespace std;
class Node {
public:
    string value;
    Node* next;
    Node* prev;

    Node(string value1) {
        value = value1;
        next = NULL;
        prev = NULL;
    }
};

class LinkedHashMap {
    Node* head = NULL;
    Node* tail = NULL;

    void put(string value) {
        Node* newNode = new Node(value);
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

    Node* findAndGet(string value) {
        Node* row = head;
        while (row != NULL) {
            if (value == row->value) {
                return row;
            }
            row = row->next;
        }
        return NULL;
    }

public:
    bool find(string value) {
        Node* node = findAndGet(value);
        return node != NULL;
    }

    void add(string value) {
        if (!findAndGet(value)) {
            put(value);
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

    void clear() {
        head = NULL;
    }
};

int main() {
    LinkedHashMap lhm;
    lhm.add("11");
    lhm.add("12");
    lhm.add("13");
    lhm.add("NULL");
    lhm.add("15");
    lhm.add("20");
    Node* node = lhm.getAll();
    while (node != NULL) {
        cout << "Value:" << node->value << endl;
        node = node->next;
    }
    cout << (lhm.find("11") ? "Key Found" : "Key Not Found") << endl;
    cout << (lhm.find("45") ? "Key Found" : "Key Not Found") << endl;
    cout << lhm.size() << endl;
    cout << lhm.empty() << endl;
    lhm.clear();
    cout << lhm.size() << endl;
    cout << lhm.empty() << endl;
    return 0;
}