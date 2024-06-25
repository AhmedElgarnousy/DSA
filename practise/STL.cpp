#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

void test_vector()
{
    vector<int> v1;
    v1.push_back(30);
    v1.push_back(10);
    v1.push_back(20);
    // now we have 3 elements only

    for (int i = 0; i < (int)v1.size(); i++)
    {
        cout << v1[i] << " "; // 30 10 20
    }

    cout << "\n"; // 30 10 20

    vector<string> str_vec{"ahmed", "mostafa", "mohamed", "mohaned"};
    cout << str_vec[2] << " "; // 30 10 20

    // we can make nested vectors similar to 2D/3D arrays

    // vector<int> vec_2D[2][2];
    // // vec_2D [0][1] = 5;
    // cout << vec_2D[0][0];
}

void test_stack()
{
    stack<string> stk;
    stk.push("ahmed");
    stk.push("ahmed");
    stk.push("ahmed");

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    cout << "\n";
}

void test_queue()
{
    queue<int> que;
    que.push(10);
    que.push(20);
    que.push(30);

    cout << "Last element in queue: " << que.back() << "\n";

    cout << "Queue elements: ";

    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
    cout << "\n";
    queue<string> q_names;
    q_names.push("ahmed");
    string name = q_names.front();
    cout << name << "\n";
}

void test_pairs()
{
    pair<int, string> pair1 = make_pair(23, "ahmed");

    cout << pair1.first << " " << pair1.second << "\n"; // 10 ali
    pair1.first += 3;

    pair<float, pair<int, string>> pair2 = make_pair(20.5, pair1);
    cout << pair2.second.first << "\n"; // 26

    pair1 = pair2.second;

    vector<pair<int, string>> vec1;
    vec1.push_back(pair1);
}

void show_deque(deque<int> deq)
{
    deque<int>::iterator it;

    for (it = deq.begin(); it != deq.end(); ++it)
    {
        cout << '\t' << *it;
    }
    cout << "\n";
}

void test_deque()
{
    deque<int> deque1;

    deque1.push_back(10);
    deque1.push_back(20);
    deque1.push_back(30);
    deque1.push_back(15);

    cout << "The deque is: ";
    show_deque(deque1);

    cout << "\ngdeque1.size() : " << deque1.size();
    cout << "\ngdeque1.max_size() : " << deque1.max_size();

    cout << "\ndeque1.at(2) : " << deque1.at(2);
    cout << "\ndeque1.front() : " << deque1.front();
    cout << "\ndeque1.back() : " << deque1.back();

    cout << "\ndeque1.pop_front() : ";
    deque1.pop_front();
    show_deque(deque1);

    cout << "\ndeque1.pop_back() : ";
    deque1.pop_back();
    show_deque(deque1);
}

int main()
{

    // test_vector();
    // test_stack();
    // test_queue();
    // test_pairs();
    test_deque();

    return 0;
}