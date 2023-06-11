/*
    Probleam: Heap Sort.

    Test cases:
    Input:
    5
    1 2 4 5 3

    Output:
    1 2 4 5 3
    1 2 3 4 5




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
        heapify(heap, idx, heap.size());
    }
    void heapify(vector<int>& arr, int idx = 0,
        int last = 0, bool isMaxHeep = true) {
        if (idx == last - 1) {
            return;
        }
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;
        int minIdx = idx;
        if (left < last && (!isMaxHeep ? arr[minIdx] < arr[left]
            : arr[minIdx] > arr[left])) {
            minIdx = left;
        }
        if (right < last && (!isMaxHeep ? arr[minIdx] < arr[right]
            : arr[minIdx] > arr[right])) {
            minIdx = right;
        }
        if (minIdx != idx) {
            int temp = arr[minIdx];
            arr[minIdx] = arr[idx];
            arr[idx] = temp;
            heapify(arr, minIdx, last, isMaxHeep);
        }
    }

    vector<int> sort(bool isDsc = false) {

        vector<int> arr = heap;

        for (int i = arr.size() / 2;i >= 0;i--) {
            heapify(arr, i, arr.size(), isDsc);

        }

        for (int i = arr.size() - 1;i >= 0;i--) {
            int temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr, 0, i, isDsc);

        }

        return arr;
    }

    void print(vector<int> heap) {
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
    heap->print(heap->heap);
    vector<int> arr = heap->sort();
    heap->print(arr);
    return 0;
}