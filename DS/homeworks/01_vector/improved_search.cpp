#include <iostream>
#include <cassert>

class vector
{
  private: 
    int * arr = nullptr;
    int size { 0 };  // user size
    int capacity {}; // actual size , init with 0

    void expand_size () {
      // Double the actual array size
      capacity *= 2;
      std::cout<< "";
      int * arr2 = new int [capacity];
      for(int i = 0; i < size; i++) {
          arr2[i] = arr[i];
      }
      std::swap(arr2, arr);
      delete [] arr2;
    }

  public:
    vector (int size) : size(size){
       if(size < 0) {
        size = 1;
       }
       capacity = size + 10;
       // the actual size array will
       // be bigger than needed
       arr = new int [capacity] {};
    }
  
    ~vector ()
    {
      delete [] arr;
      arr = nullptr;
    }

    void push_back(int val) {
      if(size == capacity) {
        expand_size();
      }
      arr[size++] = val;
    }

    int find_transposition(int value) {
        // search on val, its idx will be known
        // store it in temp val
        // replace it with pre pos


        for(int i = 0; i < size; i++) {
            if(arr[i] == value) {
                if(i == 0)  // it's 1st element
                    return 0;

                std::swap(arr[i], arr[i-1]);
                return i - 1;
            }
        }
        return -1;
    }

    // 0 1 2 3 4
    // 0 1 3 4
    int pop(int idx) {
        int req_item = arr[idx];
        for(int i = idx; i < size - 1 ; i++) {
            arr[i] = arr[i+1];
        }
        size --;
        return req_item;
    }

    // 0 1 2 3 4
    // 1 2 3 4 0
    void left_rotate() {
        if(size <= 1) 
            return ;

        int first_item = arr[0];
        for(int i = 0 ; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        arr[size -1] = first_item;
    }

    void right_rotate() {
        // make sure that vector has elements
        if(size <= 1) 
            return ;

        int last_item = arr[size - 1]; 
        // shift right
        for(int i = size - 2; i>=0; i--)
            arr[i+1] = arr[i];
        arr[0] = last_item;
    }

    void right_rotate(int stepNumber) {
        // to handle a large number of steps
        // if(stepNumber > size) 
            stepNumber %=size;

        // there are 2 solutions
        std::cout<<"# of steps is "<<stepNumber<<"\n";
        for(int i = 0; i< stepNumber; i++){
            right_rotate();
        }
    }

    int get(int idx) {
        assert(0<= idx && idx < size);
        return arr[idx];
    }

    void set(int idx, int val) {
        assert(0<= idx && idx < size);
        arr[idx] = val;
    }

    int get_front() {
		  return arr[0];
	  }

	  int get_back() {
		  return arr[size - 1];
	  }

    void print (){
      for(int i = 0; i< size; i++) {
        std::cout<< arr[i] << " ";
      }
        std::cout<<"\n";
    }

    int find(int value) {
      for(int i = 0; i< size; i++) {
        if(arr[i] == value ) {
            return i;
        }
      }
    return -1; // -1 for NOT found
    }

    void insert(int idx , int val) {
      // check validitiy of the input
      assert(0 <= idx && idx< size);
      // we can't add any more
      if(size == capacity) {
        expand_size();
      }
      // shift right the data
      for(int i = size-1; i >= idx; i--) {
        arr[i+1] = arr[i];
      }
      arr[idx] = val;
      ++size; 
    }
};

int main()
{
    // 0 1 2 3 4
    // 0 2 1 3 4  // 1
    int n = 5;
    vector v(n);
    for (int i = 0; i< n; ++i)
        v.set(i,i);

    v.print();
    std::cout<<"new idx: "<<v.find_transposition(4)<<"\n";
    v.print();

    return 0;
}