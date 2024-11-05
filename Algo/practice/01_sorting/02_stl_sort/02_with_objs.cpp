#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare_right(int a, int b)
{
    return a < b;
}

bool compare_wrong(int a, int b)
{
    return a <= b;
}

class Employee
{
private:
    int salary = 0;

public:
    Employee(int salary) : salary(salary)
    {
    }
    bool operator<(Employee &e)
    {
        return e.salary < salary;
    }
    int get_salary()
    {
        return salary;
    }
};

int main()
{


    Employee emp1(100), emp2(200);
    vector<Employee> emps;
    emps.push_back(emp1);
    emps.push_back(emp2);

    for (Employee &item : emps)
        cout << item.get_salary() << " ";
    cout << "\n";

    sort(emps.begin(), emps.end());

    for (Employee &item : emps)
        cout << item.get_salary() << " ";
    cout << "\n";

    return 0;
}