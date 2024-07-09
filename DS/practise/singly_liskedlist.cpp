#include <iostream>
#include <cassert>
#include <climits>

#include <vector>		// for debug
#include <algorithm>
#include <sstream>

using namespace std;

struct Node { 
    int data;
    Node* next;  // Pointer to same type
    Node(int data):data(data){  }
    
};
class LinkedList {
    private:
        Node* head{};
        Node* tail{};
        int length=0;

    vector<Node*> debug_data;	// add/remove nodes you use

	void debug_add_node(Node* node) {
		debug_data.push_back(node);
	}

	void debug_remove_node(Node* node) {
		auto it = std::find(debug_data.begin(), debug_data.end(), node);
		if (it == debug_data.end())
			cout << "Node does not exist\n";
		else
			debug_data.erase(it);
	}
    
    public:

    // Below 2 deletes prevent copy and assign to avoid this mistake
	LinkedList() {
	}
	LinkedList(const LinkedList&) = delete;
	LinkedList &operator=(const LinkedList &another) = delete;

	void debug_print_address() {
		for (Node* cur = head; cur; cur = cur->next)
			cout << cur << "," << cur->data << "\t";
		cout << "\n";
	}

	void debug_print_node(Node* node, bool is_seperate = false) {
		if (is_seperate)
			cout << "Sep: ";
		if (node == nullptr) {
			cout << "nullptr\n";
			return;
		}
		cout << node->data << " ";
		if (node->next == nullptr)
			cout << "X ";
		else
			cout << node->next->data << " ";

		if (node == head)
			cout << "head\n";
		else if (node == tail)
			cout << "tail\n";
		else
			cout << "\n";
	}
	void debug_print_list(string msg = "") {
		if (msg != "")
			cout << msg << "\n";
		for (int i = 0; i < (int) debug_data.size(); ++i)
			debug_print_node(debug_data[i]);
		cout << "************\n"<<flush;
	}

	string debug_to_string() {
		if (length == 0)
			return "";
		ostringstream oss;
		for (Node* cur = head; cur; cur = cur->next) {
			oss << cur->data;
			if (cur->next)
				oss << " ";
		}
		return oss.str();
	}

	void debug_verify_data_integrity() {
		if (length == 0) {
			assert(head == nullptr);
			assert(tail == nullptr);
		} else {
			assert(head != nullptr);
			assert(tail != nullptr);
			if (length == 1)
				assert(head == tail);
			else
				assert(head != tail);
			assert(!tail->next);
		}
		int len = 0;
		for (Node* cur = head; cur; cur = cur->next, len++)
			assert(len < 10000);	// Consider infinite cycle?
		assert(length == len);
		assert(length == (int)debug_data.size());
	}

	////////////////////////////////////////////////////////////
     void print() {
            Node* temp_node = head; //Don't change head if
            while(temp_node != nullptr) {
                cout<<temp_node->data <<" ";
                temp_node = temp_node->next;
            }
        cout<<"\n";
        }
      
    // These 2 simple functions just to not forget changing the vector and length
        void delete_node(Node* node) {
            debug_remove_node(node);
            delete node;
            length --;
        }

        void add_node(Node* node) {
            debug_add_node(node);
            length ++;
        }


      void insert_end(int value) {
		Node* item = new Node(value);
		add_node(item);

		if (!head)
			head = tail = item;
		else
			tail->next = item, tail = item;
	    }

        void delete_first() {
            if(length == 0) {  // head == nullptr
                return ;
            }
            Node* temp = head;
            head = head-> next;
            delete_node(temp);

            if(length == 0) {
              assert(head == nullptr);
			  assert(tail == nullptr);
            }
             if(length == 1) {
				assert(tail == head);
            }
        }

        void delete_last() {
			if(length <= 1) {
				delete_first();
				return ;
			}

			Node * prev = get_nth(length - 1);
			delete_node(tail);
			tail = prev;
			tail->next = nullptr;

			debug_verify_data_integrity();
        }

        void delete_nth(int n){ // index
            if(n < 1 || n > length){
				cout<<"Error. No such nth node\n";
			}
			else if (n == 1)
			{
				delete_first();
			}
					else {
			// Connect the node before nth with node after nth
			Node* before_nth = get_nth(n - 1);
			Node* nth = before_nth->next;
			bool is_tail = nth == tail;
			// connect before node with after
			before_nth->next = nth->next;
			if (is_tail)
				tail = before_nth;

			delete_node(nth);

			debug_verify_data_integrity();
		}
        }

		Node* get_nth(int n){  // index
			int idx = 0;
			for(Node* i = head; i != nullptr; i = i->next)
				if(++idx == n) 
					return i;

			return nullptr;
			}
		

        ~LinkedList() {

        }
};

/*print1 nodes chain basically (interatively)*/
/*
void print1(Node* head) {
    while(head != nullptr) {
        cout<<head->data <<" ";
        head = head->next;
    }
    cout<<"\n";
}
*/
/* print1 function using for loop instead of while loop */
void print1(Node* head) {
   for(Node*i = head; i!= nullptr; i= i->next) {
        cout<<i->data<<" ";
   }
   cout<<"\n";
}

/*print2 nodes chain recursively*/
void print2(Node* head){
    if(head == nullptr){
        cout<<" ";
        return ;
    }
    cout<<head->data<<" ";
    print2(head->next);
}

/*print it reversed*/
// int arr[4];
// int idx = -1;
// void print3_reversed(Node* head) {
//     if(head == nullptr) {
//         // cout<<" ";
//         for(int i = 3; i>=0; i--) {
//         cout<<arr[i]<<" ";
//         }
//         return ;
//     }
//     arr[++idx] = head->data;
//     print3_reversed(head->next);
// }

/*The whole trick to call recursively first, then print*/
void print3_reversed(Node* head) {
    if(head == nullptr) {
        return ;
    }
    print3_reversed(head->next);
    cout<<head->data;
}

void test0(){
        // create the 4 objects
    Node* node1 = new Node(6);
    Node* node2 = new Node(7);
    Node* node3 = new Node(10);
    Node* node4 = new Node(9);
    // link them
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = nullptr;
   
    // output is 9 for all of them
    cout<<node1->next->next->next->data<<"\n";
    cout<<node2->next->next->data<<"\n";
    cout<<node3->next->data<<"\n";
    cout<<node4->data<<"\n";

    print1(node1);
    // print2(node1);
    // print3_reversed(node1);
}

void test1(){
 cout << "\n\ntest3\n";
	LinkedList list;

	list.insert_end(1);
	list.insert_end(2);
	list.insert_end(3);
	list.insert_end(4);
	list.insert_end(5);

		list.print();

	list.delete_first();
	list.delete_nth(2);

	// some actions
	list.print();

	string expected = "2 4 5";
	string result = list.debug_to_string();
	if (expected != result) {
		cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	list.debug_print_list("********");
}

int main()
{
    // test0();
	test1();



   
    return 0;
}