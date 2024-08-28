#include <iostream>
#include <cassert>

using namespace std;

class Queue{
    private:
        int size{};
        int *arr{};
        int idx{};

    public:

        Queue(int size):size(size){
            arr = new int[size]; 
        }

       void enqueue(int val) {  // O(1)
            assert(!isFull()); 
            arr[idx] = val;
            idx++;
        }

       int dequeue() {   // O(n)   shift left
            int val = arr[0];
            for(int i = 1; i < size ; i++){
                arr[i-1] = arr[i];
            }
            idx--;
            return val;
        }

        bool isFull(){
            return idx == size;
        }
        bool isEmpty(){
            return idx == 0;
        }
        void display() {
            for(int i = 0 ; i < idx; i++){
                cout<<arr[i]<<" ";
            }
            cout<<"\n";
        }

};

int main(){

    Queue qu(5);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);
    qu.enqueue(50);
    qu.display();  // 10 20 30 40 50
    qu.dequeue();
    qu.display(); // 20 30 40 50
    qu.dequeue();
    qu.display(); // 30 40 50
    qu.enqueue(5);
    qu.display(); // 30 40 50 5

    return 0;
}