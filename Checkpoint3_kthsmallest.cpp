//Use a maxheap of K elements and insert the first K elements
//Insert n-k elements into the heap depending on the value
//At the end of iteration, we get the kth smallest element

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b;
    *b = temp;
}

class MaxHeap 
{
    int *arr; //internal implementation through an array
    int heap_size; 
    
    public:
    MaxHeap(int a[], int size);
    void maxHeapify(int i); 
    int parent(int i) { return (i-1)/2; }
    int left(int i) { return (2*i + 1); }
    int right(int i) { return (2*i + 2); }
 
    int extractMax();  // extracts root (maximum) element
    int getMax() { return arr[0]; } // Returns maximum
 
    // to replace root with new node x and heapify() new root
    void replaceMax(int x) { arr[0] = x;  maxHeapify(0); }
}; 

MaxHeap::MaxHeap(int a[], int size)
{
    heap_size = size;
    arr = a;  // store address of array
    int i = (heap_size - 1)/2;
    while (i >= 0)
    {
        maxHeapify(i);
        i--;
    }
}

// Method to remove maximum element (or root) from max heap
int MaxHeap::extractMax()
{
    if (heap_size == 0)
        return INT_MAX;
 
    // Store the maximum vakue.
    int root = arr[0];
 
    // If there are more than 1 items, move the last item to root
    // and call heapify.
    if (heap_size > 1)
    {
        arr[0] = arr[heap_size-1];
        maxHeapify(0);
    }
    heap_size--;
 
    return root;
}
 
// A recursive method to heapify a subtree with root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::maxHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < heap_size && arr[l] > arr[i])
        largest = l;
    if (r < heap_size && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        maxHeapify(largest);
    }
}


int Solution::kthsmallest(const vector<int> &A, int k) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int *arr = new int[A.size()]; 
    int n = A.size();
    std::copy(A.begin(), A.end(), arr);
    MaxHeap mh(arr, k);
 
    // Process remaining n-k elements.  If current element is
    // smaller than root, replace root with current element
    for (int i=k; i<n; i++)
        if (arr[i] < mh.getMax())
           mh.replaceMax(arr[i]);
 
    //delete [] arr;
    
    // Return root
    return mh.getMax();
}

