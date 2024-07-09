#include <iostream>
#include <cassert>

using namespace std;

class Deque{
    private:
        int size{};
        int *arr{};
        int front{};
        int rear{};
        int added_elements{};

    public:
        Deque(int size):size(size){
            arr = new int[size]; 
        }

         // utility to return next pos or idx
        int next(int idx) { 
            idx ++;
            if(idx == size)
                idx = 0;
            return idx;
        }

       void enqueue_front(int val) {  // O(1)

       }
    
       void enqueue_rear(int val) {  // O(1)
            assert(!isFull());
            arr[rear] = val;
            rear = next(rear);
            added_elements ++;
        }

       int dequeue_rear() {   // O(1)

            return 0;
        }

       int dequeue_front() {   // O(1)
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

    Deque dq(6);

    dq.enqueue_front(3);
    dq.enqueue_front(2);
    dq.enqueue_rear(4);
    dq.enqueue_front(1);
    dq.display();  // 1 2 3 4
    cout<<dq.dequeue_rear()<<"\n";  // 4
    dq.display();  
    cout<<dq.dequeue_front()<<"\n";  // 1
    dq.display();  
    cout<<dq.dequeue_rear()<<"\n";  // 3
    cout<<dq.dequeue_front()<<"\n";  // 2
    dq.enqueue_rear(7);
    dq.display();  // 7

    return 0;
}