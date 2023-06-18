/*
    Probleam: LRU Cache.

    LeetCode Link: https://leetcode.com/problems/lru-cache/
*/

#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto find1 = hashmap.find(key);
        if (find1 == hashmap.end()) {
            return -1;
        }
        int value = hashmap[key]->value;
        deleteNode(key);
        put(key, value);
        return hashmap[key]->value;
    }

    void deleteNode(int key) {
        auto find1 = hashmap.find(key);
        if (find1 == hashmap.end()) {
            return;
        }

        Node* node = hashmap[key];
        if (node->prev) {
            node->prev->next = node->next;
        }
        else {
            head = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        else {
            tail = node->prev;
        }
        hashmap.erase(key);
        delete node;
    }

    void put(int key, int value) {
        auto find1 = hashmap.find(key);
        if (find1 != hashmap.end()) {
            // Update node
            deleteNode(key);
            put(key, value);
            return;
        }
        if (hashmap.size() == cap) {
            // Capacity is full. Remove oldest element.
            Node* removeNode = head;
            head = head->next;
            if (head) {
                head->prev = NULL;
            }
            else {
                tail = NULL;
            }
            hashmap.erase(removeNode->key);
            delete removeNode;
        }

        // Add new Node
        Node* newNode = new Node(key, value);
        newNode->prev = tail;
        newNode->next = NULL;
        if (tail) {
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
        hashmap[key] = newNode;
    }
private:
    class Node {
    public:
        int key;
        int value;
        Node* next;
        Node* prev;
        Node(int key1, int value1) {
            key = key1;
            value = value1;
        }
    };

    int cap = 0;
    unordered_map<int, Node*> hashmap;
    Node* head = NULL;
    Node* tail = NULL;
};

int main() {
    LRUCache lRUCache(2);
    lRUCache.put(2, 1); // cache is {1=1}
    lRUCache.put(1, 1); // cache is {1=1, 2=2}
    lRUCache.put(2, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
    lRUCache.put(4, 1); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
    cout << lRUCache.get(1) << endl;    // return 1
    cout << lRUCache.get(2) << endl;    // return 1

    // for (auto a : lRUCache.cacheMap) {
    //     cout << a.first << ":" << lRUCache.cacheVector[a.second] << endl;
    // }
    return 0;
}