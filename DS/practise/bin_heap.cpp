#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class MinHeap
{
private:
    int *array;
    int size {};
    int capacity {1000};

    // utilties 
    int left(int node) { // idx
        int p =  2 * node + 1;
        // -1 indcates that cur node doesn't have child or its a root 
        return p >= size ? -1 : p;
    }
    int right(int node) {
          int p =  2 * node + 2;
        return p >= size ? -1 : p;
    }

    int parent(int node) {
          int p =  (node - 1) /2;
        // -1 indcates that cur node doesn't have child or its a root 
        return node == 0 ? -1 : p;
    }

    void heapify_up(int child_pos) {
        int par_pos = parent(child_pos);

        if(child_pos == 0|| array[child_pos] > array[par_pos])
        {
            return;
        }
        swap(array[child_pos], array[par_pos]);
        heapify_up(par_pos);
    }

    void heapify_down(int parent_pos){
        int child_pos = left(parent_pos);
        int right_child = right(parent_pos);

        if(child_pos == -1) // no children because it's complete BT
            return;
        
        // is right smaller than left?
        if(right_child != -1 && array[right_child] < array[child_pos])
            child_pos = right_child;

        if(array[parent_pos] > array[child_pos])
        {
            swap(array[parent_pos] , array[child_pos]);
            heapify_down(child_pos);
        }
        
    }

public:
    MinHeap()
    {
      array = new int[capacity];
      size = 0;
    }

    int top() {
        assert(!isEmpty());
        return array[0];
    }
    bool isEmpty()
    {
        return size == 0;
    }

    void push(int val) {
        assert(size + 1 <= capacity);
        array[size++] = val;
        heapify_up(size -1);
    }
    int pop()
    {
        assert(!isEmpty());
        array[0] = array[--size];
        heapify_down(0);
    }
    
    ~MinHeap()
    {
        delete[] array;
        array =nullptr;
    }
};

int main()
{
    MinHeap heap;
    vector<int> vec{2, 17, 22, 10, 8, 37, 14, 19, 7, 6, 5, 12, 25, 30};

    for (int i = 0; i < vec.size(); i++)
        heap.push(vec[i]);

    while(!heap.isEmpty()){
       cout<<heap.top()<<" ";
        heap.pop();
    }

    return 0;
}