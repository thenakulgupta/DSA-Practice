/*
    Probleam: Sliding Window Maximum.

    Test cases:
    Input:
    8 3
    1 3 -1 -3 5 3 6 7

    Output:
    3 3 5 5 6 7



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
    int data;
    Rows(int idx1, int data1) {
        idx = idx1;
        data = data1;
    }
    bool compareTo(Rows* r2) {
        return data < r2->data;
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
        sort();
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
    void sort() {
        for (int i = heap.size() / 2;i >= 0;i--) {
            heapify(heap, i, heap.size());
        }
        for (int i = heap.size() - 1;i >= 0;i--) {
            Rows* temp = heap[i];
            heap[i] = heap[0];
            heap[0] = temp;
            heapify(heap, 0, i);
        }
    }

    vector<Rows*> findSums(vector<Rows*>v, int k) {
        vector<Rows*> result;
        int j = k - 1;
        for (int i = 0; i <= j; i++) {
            add(v[i]);
        }
        result.push_back(peek());
        j++;
        while (j < v.size()) {
            for (int i = 0; i < heap.size(); i++) {
                if (heap[i]->idx <= (j - k)) {
                    remove(i);
                    add(v[j]);
                }
            }
            result.push_back(peek());
            j++;
        }
        return result;
    }

    void print(vector<Rows*> v) {
        for (int i = 0;i < v.size();i++) {
            cout << v[i]->data << " ";
        }
        cout << endl;
    }
};
int main() {
    /* Getting index value
        Parent To Child:
            left: 2i + 1
            right: 2i + 2

        Child to Parent: (x-1)/2
    */
    int n, k;
    cin >> n >> k;
    Heap* heap = new Heap();
    vector<Rows*> v;
    for (int i = 0;i < n;i++) {
        int a;
        cin >> a;
        v.push_back(new Rows(i, a));
    }
    vector<Rows*> result = heap->findSums(v, k);
    heap->print(result);
    return 0;
}
