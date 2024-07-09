
#include <iostream>
#include<cassert>


using namespace std;
class Stack {
    private:
        struct Node{
            int data{};
            Node* next{};
            Node(int data) 
                :data(data) {
            }
            ~Node() {
		        cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	        }
        };
        
    public:
    Node* head{};

    void push (int val) {
        Node* node = new Node(val);
        node ->next = head;
        head = node;
    }

    void display(){
        for(Node * cur = head; cur; cur= cur->next) {
            cout<<cur->data<<" ";
        }
        cout<<"\n";
    }

};

int main() {
        Stack stack1;

        stack1.push(5);
        stack1.push(4);
        stack1.push(3);
        stack1.push(2);
        stack1.push(1);
        stack1.display();
        // stack1.pop();
        stack1.display();

    return 0;
}