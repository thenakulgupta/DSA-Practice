/*
    Probleam: Nearby Cars.

    Test cases:
    Input:
    3 2
    3 3 5 -1 -2 4

    Output:
    C0 C2




    Getting index value
    Parent To Child:
        left: 2i +1
        right: 2i + 2

    Child to Parent: (x-1)/2
*/

#include <iostream>                                       
#include <vector>
using namespace std;
class Point {
public:
    int x;
    int y;
    int dist;
    int idx;
    Point(int x1, int y1, int dist1, int idx1) {
        x = x1;
        y = y1;
        dist = dist1;
        idx = idx1;
    }
};
class Heap {
public:
    vector<Point*> heap;
    void add(Point* data) {
        heap.push_back(data);
        int x = heap.size() - 1;
        int parent = (x - 1) / 2;
        while (heap[parent]->dist > heap[x]->dist) {
            Point* temp = heap[parent];
            heap[parent] = heap[x];
            heap[x] = temp;

            x = parent;
            parent = (parent - 1) / 2;
        }
    }
    bool isEmpty() {
        return heap.empty();
    }
    Point* peek() {
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
    void heapify(vector<Point*>& arr, int idx = 0,
        int last = 0, bool isMaxHeep = true) {
        if (idx == last - 1) {
            return;
        }
        int left = (2 * idx) + 1;
        int right = (2 * idx) + 2;
        int minIdx = idx;
        if (left < last && (!isMaxHeep ? arr[minIdx]->dist < arr[left]->dist
            : arr[minIdx]->dist > arr[left]->dist)) {
            minIdx = left;
        }
        if (right < last && (!isMaxHeep ? arr[minIdx]->dist < arr[right]->dist
            : arr[minIdx]->dist > arr[right]->dist)) {
            minIdx = right;
        }
        if (minIdx != idx) {
            Point* temp = arr[minIdx];
            arr[minIdx] = arr[idx];
            arr[idx] = temp;
            heapify(arr, minIdx, last, isMaxHeep);
        }
    }
    vector<Point*> sort(bool isDsc = false) {
        vector<Point*> arr = heap;
        for (int i = arr.size() / 2;i >= 0;i--) {
            heapify(arr, i, arr.size(), isDsc);
        }
        for (int i = arr.size() - 1;i >= 0;i--) {
            Point* temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr, 0, i, isDsc);
        }
        return arr;
    }

    vector<Point*> findNearestKElements(vector<Point*> arr, int k) {
        vector<Point*> arr1;
        for (int i = 0;i < k;i++) {
            arr1.push_back(arr[i]);
        }
        return arr1;
    }

    void print(vector<Point*> heap) {
        for (int i = 0;i < heap.size();i++) {
            cout << "C" << heap[i]->idx << " ";
        }
        cout << endl;
    }
};
int main() {
    int n, k;
    cin >> n >> k;
    Heap* heap = new Heap();
    for (int i = 0;i < n;i++) {
        int a, b;
        cin >> a >> b;
        Point* p = new Point(a, b, a * a + b * b, i);
        heap->add(p);
    }
    vector<Point*> sorted = heap->sort();
    vector<Point*> arr = heap->findNearestKElements(sorted, k);
    heap->print(arr);
    return 0;
}