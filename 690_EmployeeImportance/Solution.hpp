/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        stack<Employee*> employeesStk;
        map<int, Employee*> idEmployeeMap;
        int sum = 0;
        
        for (int i = 0; i < employees.size(); i++){
            Employee* e = employees[i];
            idEmployeeMap.insert(make_pair(e->id, e));
        }
        
        Employee* head = idEmployeeMap[id];
        employeesStk.push(head);
    
        while(!employeesStk.empty()){
            Employee* e = employeesStk.top();
            employeesStk.pop();
            sum += e->importance;
            for (int i = 0; i < e->subordinates.size(); i++){
                int subId = e->subordinates[i];
                Employee* subE = idEmployeeMap[subId];
                employeesStk.push(subE);
            }                
        }
        return sum;
    }
};
