/*
    Probleam: Merge K Sorted Linked List.

    Test cases:
    Input:
    3 3
    2 4 8
    1 3 7
    9 10 11

    Output:
    1->2->3->4->7->8->9->10->11->NULL




    Getting index value
    Parent To Child:
        left: 2i +1
        right: 2i + 2

    Child to Parent: (x-1)/2
*/


#include <iostream>
#include <vector>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node(int data1) {
        data = data1;
    }

    bool compareTo(Node* n2) {
        return data > n2->data;
    }
};
class Heap {
public:
    vector<Node*> heap;
    void add(Node* data) {
        heap.push_back(data);
        int x = heap.size() - 1;
        int parent = (x - 1) / 2;
        while (heap[parent]->compareTo(heap[x])) {
            Node* temp = heap[parent];
            heap[parent] = heap[x];
            heap[x] = temp;

            x = parent;
            parent = (parent - 1) / 2;
        }
        sort();
    }
    void heapify(vector<Node*>& heap, int idx = 0,
        int last = 0) {
        if (idx == last - 1) {
            return;
        }
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;
        int minIdx = idx;
        if (left < last && heap[left]->compareTo(heap[minIdx])) {
            minIdx = left;
        }
        if (right < last && heap[right]->compareTo(heap[minIdx])) {
            minIdx = right;
        }
        if (minIdx != idx) {
            Node* temp = heap[minIdx];
            heap[minIdx] = heap[idx];
            heap[idx] = temp;
            heapify(heap, minIdx, last);
        }
    }
    void remove(int idx) {
        if (idx == heap.size() - 1) {
            heap.erase(heap.begin() + idx);
            return;
        }
        heap[idx] = heap[heap.size() - 1];
        heap.erase(heap.begin() + heap.size() - 1);
        sort();
    }
    Node* peek() {
        return heap.at(0);
    }
    void sort() {
        for (int i = heap.size() / 2;i >= 0;i--) {
            heapify(heap, i, heap.size());
        }
        for (int i = heap.size() - 1;i >= 0;i--) {
            Node* temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            heapify(heap, 0, i);
        }
    }

    Node* mergeNodes(int k, int n) {
        if (heap.empty()) {
            return NULL;
        }
        Node* head = new Node(0);
        Node* last = head;
        while (!heap.empty()) {
            Node* curr = peek();
            remove(0);
            last->next = curr;
            last = last->next;
            if (curr->next != NULL) {
                add(curr->next);
            }
        }
        return head->next;
    }

    void print(Node* v) {
        while (v != NULL) {
            cout << v->data << "->";
            v = v->next;
        }
        cout << "NULL" << endl;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Heap* heap = new Heap();
    vector<Node*> v;
    for (int i = 0;i < k;i++) {
        Node* n1 = new Node(-1);
        Node* n2 = n1;
        for (int j = 0;j < n;j++) {
            int a;
            cin >> a;
            n1->data = a;
            n1->next = new Node(-1);
            n1 = n1->next;
        }
        n1 = n2;
        while (n1->next != NULL && n1->next->data != -1) {
            n1 = n1->next;
        }
        n1->next = NULL;
        heap->add(n2);
    }
    Node* result = heap->mergeNodes(k, n);
    heap->print(result);
    return 0;
}
