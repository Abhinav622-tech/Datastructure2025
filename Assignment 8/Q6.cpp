#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
public:
    vector<int> heap;

    MaxPriorityQueue() {
        heap.push_back(-1); // dummy at index 0
    }

    // Insert element into max heap
    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;

        // Bubble up
        while (i > 1 && heap[i] > heap[i/2]) {
            swap(heap[i], heap[i/2]);
            i /= 2;
        }
    }

    // Return highest priority element
    int top() {
        if (heap.size() == 1) {
            cout << "Queue empty!\n";
            return -1;
        }
        return heap[1];
    }

    // Delete highest priority element
    void pop() {
        if (heap.size() == 1) {
            cout << "Queue empty!\n";
            return;
        }

        heap[1] = heap.back();
        heap.pop_back();

        heapify(1);
    }

    // Heapify downward
    void heapify(int i) {
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;

        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapify(largest);
        }
    }

    bool empty() {
        return heap.size() == 1;
    }

    int size() {
        return heap.size() - 1;
    }
};

int main() {
    MaxPriorityQueue pq;

    pq.push(50);
    pq.push(20);
    pq.push(40);
    pq.push(10);
    pq.push(60);

    cout << "Top element: " << pq.top() << endl;

    pq.pop();
    cout << "After popping, new top: " << pq.top() << endl;

    return 0;
}
