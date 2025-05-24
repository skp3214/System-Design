#include <iostream>
#include <string>
#include <vector>

class Employee {
public:
    std::string name;
    Employee(std::string n) : name(n) {}
    void work() { std::cout << name << " is working.\n"; }
};

class Department {
public:
    std::string deptName;
    std::vector<Employee*> employees; // Aggregation: Department has Employees
    Department(std::string name) : deptName(name) {}
    void addEmployee(Employee* emp) { employees.push_back(emp); }
    void showEmployees() {
        std::cout << "Department: " << deptName << "\n";
        for (auto emp : employees) {
            emp->work();
        }
    }
};

int main() {
    Employee emp1("Alice");
    Employee emp2("Bob");
    
    Department dept("Engineering");
    dept.addEmployee(&emp1); // Employees are part of the department
    dept.addEmployee(&emp2);
    dept.showEmployees(); // Output: Department: Engineering
                         // Alice is working.
                         // Bob is working.

    // Employees can exist independently if the department is destroyed
    return 0;
}