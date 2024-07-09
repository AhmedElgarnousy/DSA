
#include <iostream>
#include<cassert>


using namespace std;
class Stack {
    private:
    int top {};
    int size {};
    int *array{};

    public:
        Stack(int size):
                size(size), top(-1) {
            array = new int[size];
        }

        // utilities
        bool isFull() {
            return top == size -1;
        }
        bool isEmpty() {
            return top == -1;
        }

        void display() {
            for(int i = top; i >= 0; i--) {
                cout<<array[i]<<" ";
            }
            cout<<"\n";
        }
        // methods
        void push(int val) {
            assert(!isFull());
            array[++top] = val;
        }

        int pop() {
            assert(!isEmpty());
            return array[top--];
        }

        int peek(){
            assert(!isEmpty());
            return array[top];
        }

};

int main() {
        Stack stack1(5);

        stack1.push(5);
        stack1.push(4);
        stack1.push(3);
        stack1.push(2);
        stack1.push(1);
        stack1.display();
        stack1.pop();
        stack1.display();

    return 0;
}