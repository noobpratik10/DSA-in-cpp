#include <bits/stdc++.h>
#include <queue>
using namespace std;

// Max heap implementation
class heap
{
    private:
    // array implementation
    vector<int> arr;
    int size;

    public:
    // constructor
    heap(int n)
    {
        size = 0;
        vector<int> arr(n);
        arr[0] = -1;
    }

    // isEmpty
    bool isEmpty()
    {
        if (size == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // isFull
    bool isFull()
    {
        if (size == arr.size() - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    // insertion
    void insertElement(int val)
    {
        if (isFull())
        {
            cout << "Heap is Full. Cannot insert element. " << endl;
            return;
        }
        // add element to last
        size++;
        int index = size;
        arr[index] = val;
        // move it to its correct position
        while (index > 1)
        {
            int parent = index / 2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    // deletion
    void deleteElement()
    {

        if (isEmpty())
        {
            cout << "Heap is Empty. Nothing to delete" << endl;
            return;
        }
        // delete element from root by putting lat el. at root
        arr[1] = arr[size];
        size--;

        int index = 1;
        // now move new root to its correct position
        while (index < size)
        {
            int left = 2 * index;
            int right = 2 * index + 1;

            if (left < size && arr[index] < arr[left])
            {
                swap(arr[index], arr[left]);
                index = left;
            }

            else if (right < size && arr[index] < arr[right])
            {
                swap(arr[index], arr[right]);
                index = right;
            }

            else
            {
                return;
            }
        }
    }

    // print the heap
    void print()
    {
        cout << "Heap is:" << endl;
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// heapify algorithm-->move indx to its correct position in heap
void heapify(vector<int> &arr, int size, int index)
{

    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1;

    if (left < size && arr[left] > arr[largest])
    {
        largest = left;
    }

    if (right < size && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, size, largest);
    }
}

// heap Sort
void heapSort(vector<int> &arr, int size)
{
    int index = size;

    while (index > 1)
    {
        // swap index with 1
        swap(arr[index], arr[1]);
        size--;

        // heapify
        heapify(arr, size, 1);
    }
}
int main()
{

    // heap h(100);
    // h.insertElement(4);
    // h.insertElement(5);
    // h.insertElement(55);
    // h.insertElement(50);
    // h.insertElement(52);

    // //heap creation
    // vector<int>arr(6);
    // int n=5;
    // arr[0]=-1;
    // arr[1]=54;
    // arr[2]=53;
    // arr[3]=55;
    // arr[4]=52;
    // arr[5]=50;

    // for(int i=n/2;i>=0;i--){
    //     heapify(arr,n,i);
    // }

    // cout<<"Printing array:"<<endl;
    // for(int i=1;i<=n;i++){
    //     cout<<arr[i]<<" ";
    // }cout<<endl;

    //  MAX Heap
    priority_queue<int>pq;
    pq.push(45);
    pq.push(55);
    pq.push(65);
    pq.push(53);
    pq.push(57);

    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;

    //MIN Heap
    priority_queue<int,vector<int>,greater<int>>minHeap;
    minHeap.push(45);
    minHeap.push(55);
    minHeap.push(65);
    minHeap.push(53);
    minHeap.push(57);

    cout<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<minHeap.top()<<endl;

    //pq functions
    /*
    -->pq.push()
    -->pq.pop()
    -->pq.top()
    -->pq.size()
    -->pq.empty()
    */

    return 0;
}