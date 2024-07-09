#include <iostream>
#include <cassert>

using namespace std;

class Queue{
    private:
        int size{};
        int *arr{};
        int front{};
        int rear{};
        int added_elements{};

    public:
        Queue(int size):size(size){
            arr = new int[size]; 
        }

         // utility to return next pos or idx
        int next(int idx) { 
            idx ++;
            if(idx == size)
                idx = 0;
            return idx;
        }

       void enqueue(int val) {  // O(1)
            assert(!isFull());
            arr[rear] = val;
            rear = next(rear);
            added_elements ++;
        }

       int dequeue() {   // O(1)
            assert(!isEmpty());
            int val = arr[front];
            front = next(front);
            added_elements --;
            return val;
        }

        bool isFull(){
           return added_elements == size;
        }
        bool isEmpty(){
           return added_elements == 0;
        }
        void display() {
            cout<< " Front " << front <<" - rear " << rear <<"\t";
            if(isFull()) {
                cout<<"circular queue is full\n";
            }
            else if(isEmpty()) {
                cout<<"circular queue is Empty\n";
            }
            
            else {
                for(int cur = front, step = 0 ; step < added_elements; cur = next(cur), step ++){
                    cout<<arr[cur]<<" ";
                }
                cout<<"\n";
                }
        }

};

int main(){

    Queue qu(5);
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.display();  // 10 20 30 
    qu.dequeue();
    qu.display(); // 20 30 


    return 0;
}