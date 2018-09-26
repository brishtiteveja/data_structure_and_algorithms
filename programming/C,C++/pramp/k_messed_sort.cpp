#include <iostream>
#include <queue>

using namespace std;

void swap(int &a, int &b)
{
    int temp = b;
    b = a;
    a = temp;
}

void insertion_sort(int *arr, int n) 
{
    int i, j;

    for(i=1; i<n; i++) 
    {
        int x = arr[i];
        // find the insertion point of arr[i]
        for(j=i-1; j>=0; j--)
        {
            // 3 2 6 1
            // 1 3 2 6
            //
            // 1 4 6 3 2 8
            //     4  6     
            if(arr[j] > x) 
            {
                arr[j+1] = arr[j];
            } else // found the insertion point
            {
                break;
            }
        }
        arr[j+1] = x;
    }

    return;
}

int left_child(int i) 
{
    return (2*i + 1);
}
int right_child(int i)
{
    return (2*i + 2);
}

int parent(int i) {
   return (i-1)/2; 
}

   /* heap is a complete binary tree
               20
              / \
            30  34
           /
          56
   
    * */


// int arr[10] = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
// 1 : 1
// 4 : 4 1
// 5 : 4 1 5 -> 5 1 4
// 2 : 5 1 4 2 -> 5 2 4 1
// 3 : 5 2 4 1 3 -> 5 3 4 2 1
// 7 : 5 3 4 2 1 7 -> 7 3 5 2 1 4
//
// a) insert an element in the open slot of a complete binary tree
// b) check whether its a heap
// c) if not heap, heapify
//
// How to heapify?
//
void build_heap(int *a, int n)
{
    int i, j;

    // heapify 
    // i = 0, p = 0
    // i = 1, p = 0
    // i = 2, p = 0
    // i = 3: c = 3, p = 1 -> c = 1, p = 0 
    //
    // i = 8: c = 8, p = 3 -> c = 3, p = 1 -> c=1, p = 0
    for (i=n/2-1; i<n; i++) {
        int c = i; // child
        int p = (i-1)/2; //parent
        while(p >= 0) {
            // check heap property between child and parent
            if (a[c] < a[p]) // min heap
                swap(a[c], a[p]);

            if (p==0)
                break;

            // update child and parent
            c = p;
            p = (c-1)/2;
        }
    }

    return;
}

void heap_sort(int *a, int n)
{
    int i;

    for(i=0; i<n; i++)
    {
        build_heap(a + i, n-i);
    }

    return;
}

class qcompare {
private:
    bool reverse;
public:
    qcompare(bool rev=false)
    {
        reverse = rev;
    }

    bool operator() (const int &lhs, const int &rhs)
    {
        if(reverse) return lhs < rhs;
        else return lhs > rhs;
    }
};

void print_heap(priority_queue<int, vector<int>, qcompare> pq)
{
    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    cout << endl;

    return;
}

void k_messed_sort_with_stl(int *a, int n, int k)
{
    // by default priority queue makes max heap, qcompare class to turn into a min heap
    priority_queue<int, vector<int>, qcompare> pq;

    // build min heap from first k+1 elements
    int i;
    for(int i=0; i<=k; i++) // O(k) 
        pq.push(a[i]);

    // sliding the k sized window 1 by 1
    for(i=0; i<n-k-1; i++)
    {
        // extract the min/top element from the heap 
        a[i] = pq.top();  // O(1)
        pq.pop(); // O(logk)  // because there's always k elements in the heap, one popped and then one pushed 

        // push the next array element
        pq.push(a[i+k+1]); //O(logk)
    }  // O(nlogk) 

    // the last k elements are still unsorted, so sort them
    for(i=n-k-1; i<n; i++) {
        a[i] = pq.top();
        pq.pop();
    } // O(k)

    return;
} // O(nlogk)

void k_messed_sort(int *a, int n, int k)
{
    // by default priority queue makes max heap, qcompare class to turn into a min heap
    int heap[n];

    // build min heap from first k+1 elements
    int i;
    for(int i=0; i<=k; i++) // O(k) 
    {
       heap[i] = a[i]; 
       build_heap(heap, i+1); // O(logk) 
    } // O(klogk)

    // sliding the k sized window 1 by 1
    for(i=0; i<n-k-1; i++)
    {
        // extract the min/top element from the heap 
        a[i] = heap[i];  // O(1)

        // push the next array element
        heap[i+k+1] = a[i+k+1];

        // heapify heap[(i+1)->i+1+k]
        build_heap(heap+i+1, k+1); //O(logk)
    }  // O(nlogk) 

    // the last k elements are still unsorted, so sort them
    for(i=n-k-1; i<n; i++) {
        a[i] = heap[i];
        build_heap(heap+i+1, n-i-1); // heap size decrease by 1 k+1
    } // O(klogk)

    return;
} // O(nlogk + klogk) = O(klogk)

void print(int *a, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << a[i] << " ";
    }

    cout << endl;

    return;
}

int main() 
{
    int arr[10] = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "1. Using Insertion sort" << endl;
    insertion_sort(arr, n);
    print(arr, n);

    int arr2[10] = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};

    cout << "2. Using Heap sort" << endl;
    heap_sort(arr2, n);
    print(arr2, n);

    int arr3[10] = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};

    cout << "3. Using K-messed sort with cpp priority queue/heap." << endl;
    int k = 2;
    k_messed_sort_with_stl(arr3, n, k);
    print(arr3, n);

    int arr4[10] = {1, 4, 5, 2, 3, 7, 8, 6, 10, 9};
    cout << "4.1 Using K-messed sort with simple array based heap." << endl;
    k_messed_sort(arr4, n, k);
    print(arr4, n);

    int arr5[10] = {4, 1, 5, 2, 7, 3, 6, 10, 8, 9};
    cout << "4.2 Using K-messed sort with simple array based heap." << endl;
    k = 3;
    k_messed_sort(arr5, n, k);
    print(arr5, n);

    return 0;
}
