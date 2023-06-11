/*
    Probleam: Add, Peek, Remove, Heapify In Heap.

    Test cases:
    Input:
    4
    3 4 1 5

    Output:
    peek: 1
    1 3 4 5




    Getting index value
    Parent To Child:
        left: 2i +1
        right: 2i + 2

    Child to Parent: (x-1)/2
*/

#include <iostream>
#include <vector>
using namespace std;
class Heap {
    vector<int> heap;
public:
    void add(int data) {
        heap.push_back(data);
        int x = heap.size() - 1;
        int parent = (x - 1) / 2;
        while (heap[parent] > heap[x]) {
            int temp = heap[parent];
            heap[parent] = heap[x];
            heap[x] = temp;

            x = parent;
            parent = (parent - 1) / 2;

        }
    }
    bool isEmpty() {
        return heap.empty();
    }
    int peek() {
        return heap.at(0);
    }
    void remove(int idx) {
        if (idx == heap.size() - 1) {
            heap.erase(heap.begin() + idx);
            return;
        }
        heap[idx] = heap[heap.size() - 1];
        heap.erase(heap.begin() + heap.size() - 1);
        heapify(idx);
    }
    void heapify(int idx = 0) {
        if (idx == heap.size() - 1) {
            return;
        }
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;

        int minIdx = idx;

        if (left < heap.size() && heap[minIdx] > heap[left]) {
            minIdx = left;

        }
        if (right < heap.size() && heap[minIdx] > heap[right]) {
            minIdx = right;

        }
        if (minIdx != idx) {
            int temp = heap[minIdx];
            heap[minIdx] = heap[idx];
            heap[idx] = temp;
            heapify(minIdx);

        }
    }
};
int main() {
    int n;
    cin >> n;
    Heap* heap = new Heap();
    for (int i = 0;i < n;i++) {
        int a;
        cin >> a;
        heap->add(a);
    }
    cout << "peek: " << heap->peek() << endl;
    while (!heap->isEmpty()) {
        cout << heap->peek() << " ";
        heap->remove(0);
    }
    return 0;
}