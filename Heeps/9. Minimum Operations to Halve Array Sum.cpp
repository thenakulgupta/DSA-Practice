/*
    Probleam: Minimum Operations to Halve Array Sum.

    Test cases:
    Input:
    4
    5 8 1 19

    Output:
    3



    Input:
    6
    4 6 3 9 10 2

    Output:
    5





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
public:
    vector<int> heap;
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
        sort();
    }
    void heapify(vector<int>& heap, int idx = 0,
        int last = 0) {
        if (idx == last - 1) {
            return;
        }
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;
        int minIdx = idx;
        if (left < last && heap[left] < heap[minIdx]) {
            minIdx = left;
        }
        if (right < last && heap[right] < heap[minIdx]) {
            minIdx = right;
        }
        if (minIdx != idx) {
            int temp = heap[minIdx];
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
    int peek() {
        return heap.at(0);
    }
    void sort() {
        for (int i = heap.size() / 2;i >= 0;i--) {
            heapify(heap, i, heap.size());
        }
        for (int i = heap.size() - 1;i >= 0;i--) {
            int temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            heapify(heap, 0, i);
        }
    }

    int getMinimumOperations() {
        int sum = getHeapSum();
        int cSum = getHeapSum();
        int operations = 0;
        while (cSum > (sum / 2)) {
            int val = peek();
            remove(0);
            add(val / 2);
            cSum = getHeapSum();
            operations++;
        }
        return operations;
    }

    int getHeapSum() {
        int sum = 0;
        for (int i = 0;i < heap.size();i++) {
            sum += heap[i];
        }
        return sum;
    }

    void print() {
        for (int i = 0;i < heap.size();i++) {
            cout << heap[i] << " ";
        }
        cout << endl;
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
    cout << heap->getMinimumOperations();
    return 0;
}
