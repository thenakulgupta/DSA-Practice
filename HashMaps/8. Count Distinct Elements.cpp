/*
    Probleam: Count Distinct Elements.

    Input:
    10
    4 3 2 5 6 7 3 4 2 1

    Output:
    Distinct: 7
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
    int n;
    cin >> n;
    LinkedHashMap lhm;
    for (int i = 0;i < n;i++) {
        int a;
        cin >> a;
        lhm.add(to_string(a));
    }
    cout << "Distinct: " << lhm.size();
    return 0;
}