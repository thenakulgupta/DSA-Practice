/*
    Probleam: Weakest Soldier.

    Test cases:
    Input:
    4 4 2
    1 0 0 0
    1 1 1 1
    1 0 0 0
    1 0 0 0

    Output:
    row0 row2



    Getting index value
    Parent To Child:
        left: 2i +1
        right: 2i + 2

    Child to Parent: (x-1)/2
*/


#include <iostream>
#include <vector>
using namespace std;
class Rows {
public:
    int idx;
    int soldiers;
    Rows(int idx1, int soldiers1) {
        idx = idx1;
        soldiers = soldiers1;
    }
    bool compareTo(Rows* r2) {
        return soldiers > r2->soldiers;
    }
};
class Heap {
public:
    vector<Rows*> heap;
    void add(Rows* data) {
        heap.push_back(data);
        int x = heap.size() - 1;
        int parent = (x - 1) / 2;
        while (heap[parent]->compareTo(heap[x])) {
            Rows* temp = heap[parent];
            heap[parent] = heap[x];
            heap[x] = temp;

            x = parent;
            parent = (parent - 1) / 2;
        }
    }
    void heapify(vector<Rows*>& heap, int idx = 0,
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
            Rows* temp = heap[minIdx];
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
        heapify(heap, idx, heap.size());
    }
    Rows* peek() {
        return heap.at(0);
    }
    vector<Rows*> sort() {
        vector<Rows*> arr = heap;
        for (int i = arr.size() / 2;i >= 0;i--) {
            heapify(arr, i, arr.size());
        }
        for (int i = arr.size() - 1;i >= 0;i--) {
            Rows* temp = arr[i];
            arr[i] = arr[0];
            arr[0] = temp;
            heapify(arr, 0, i);
        }
        return arr;
    }

    void findKWeekest(vector<Rows*> arr, int k) {
        for (int i = 0;i < min(k, static_cast<int>(heap.size()));i++) {
            cout << "row" << arr[i]->idx << " ";
        }
        cout << endl;
    }

    void print(vector<int> v) {
        for (int i = 0;i < v.size();i++) {
            cout << v[i] << " ";
        }
        cout << endl;
    }
};
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    Heap* heap = new Heap();
    for (int i = 0;i < m;i++) {
        int soldiers = 0;
        for (int j = 0;j < n;j++) {
            int a;
            cin >> a;
            if (j == 0 && a == 0) {
                soldiers = n + 1;

                continue;
            }
            if (a == 1) {
                soldiers += 1;
            }

        }

        heap->add(new Rows(i, soldiers));
    }
    vector<Rows*> arr = heap->sort();
    heap->findKWeekest(arr, k);
    return 0;
}
