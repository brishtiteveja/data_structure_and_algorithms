#include<iostream>
#include<climits>

using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    int *harr; // pointer to array of elements in heap
    int heap_size; // Current number of elements in min heap
    int capacity; // maximum possible size of min heap

public:
    MinHeap(int a[], int size);
    void MinHeapify(int i); // To minheapify subtree rooted with index i
    int parent(int i) { return (i-1) / 2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }

    int extractMin(); // extracts root (minimum) element
    int getMin() { return harr[0]; } // Returns minimum
};

MinHeap::MinHeap(int a[], int size) {
    heap_size = size;
    harr = a; // store address of array
    int i = (heap_size -1)/2;
    while (i >= 0 ) {
        MinHeapify(i);
        i--;
    }
}

int MinHeap::extractMin() {
    if (heap_size == 0) 
        return INT_MAX;

    // Store the minimum value
    int root = harr[0];

    if (heap_size > 1) {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
}
