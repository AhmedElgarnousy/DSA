#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Employee
{
private:
public:
    int id;
    int importance;
    vector<int> subordinates;
};

int dfs(int id, unordered_map<int, Employee *> id_to_emp)
{
    Employee *emp = id_to_emp[id];
    int result = emp->importance;
    for (auto &subEmp : emp->subordinates)
        result += dfs(subEmp, id_to_emp);

    return result;
}

int getImportance(vector<Employee *> employees, int id, unordered_map<int, Employee *> id_to_emp)
{
    for (auto &emp : employees)
        id_to_emp[emp->id] = emp;
    return dfs(id, id_to_emp);
}

int main()
{
    unordered_map<int, Employee *> id_to_emp;

    return 0;
}