#include <iostream>

#include <vector>		// for debug
#include <algorithm>    // for find algorithms for debug
#include <cassert>    // used by debug utlity
#include <sstream>
#include <climits>

using namespace std;


struct Node{
    int data {};
    Node* next {};
    Node(int Data):data(Data){};
    ~Node() {
		cout << "Destroy value: " << data <<" at address "<< this<< "\n";
	}

};
class LinkedList {

private:
    Node *head{ };
    Node *tail{ };
    int length = 0;	// let's maintain how many nodes

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

        void add_node(Node * node){
                debug_add_node(node);
                length ++;
        }
        void delete_node(Node* node){
                debug_add_node(node);
                length --;
                delete node;
        }
        void insert_end(int data){      
            Node*node = new Node(data);
            if(!head) { // len == 0
                head = tail = node;
                tail->next = nullptr;
            }
            else {
                tail->next =node;
                tail =node;
            }
        }

        void print() {
        	for(Node * i = head; i ; i = i->next) {
        	   cout<<i->data<<" ";
        	}
        	cout << "\n";
        }

		//////////////////////////////New Functions/////////////////////////////////
	~LinkedList() {	 // O(n) time - O(1) memory
		while(head) {
			Node *current = head -> next ;
			delete head;
			head = current;
		}
	}
};


int main() {
	
    return 0;
}