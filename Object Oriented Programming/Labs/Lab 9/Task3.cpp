#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
#include <numeric>
#include <functional>

class Employee {
public:
    int id;
    std::string name;
    std::string department;
    double salary;

    Employee(int i, std::string n, std::string d, double s)
        : id(i), name(n), department(d), salary(s) {}

    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << '\n';
    }

    void displayFull() const {
        std::cout << "ID: " << id << ", Name: " << name
                  << ", Department: " << department
                  << ", Salary: $" << salary << '\n';
    }
};

class EmployeeManager {
private:
    std::map<int, Employee> employees;

public:
    void addEmployee(const Employee& a) {
        employees[a.id] = a;
    }

    void deleteEmployee(int id) {
        if (employees.erase(id))
            std::cout << "Employee with ID " << id << " deleted." << std::endl;
        else
            std::cout << "No employee found with ID " << id << "." << std::endl;
    }

    void displayAll(void (*displayFunc)(const Employee&)) const {
        for (const auto& [id, emp] : employees)
            displayFunc(emp);
    }

    void Sort(std::function<bool(const Employee&, const Employee&)> comp) const {
        std::vector<Employee> sortedEmployees;
        for (const auto& [_, emp] : employees)
            sortedEmployees.push_back(emp);

        std::sort(sortedEmployees.begin(), sortedEmployees.end(), comp);

        for (const auto& emp : sortedEmployees)
            emp.displayFull();
    }

    void HighEarners(double threshold) const {
        std::cout << "Employees with salary above $" << threshold << ":" << std::endl;
        std::for_each(employees.begin(), employees.end(), [threshold](const auto& pair) {
            if (pair.second.salary > threshold)
                pair.second.displayFull();
        });
    }

    void AveSalary() const {
        if (employees.empty()) {
            std::cout << "No employees to calculate average." << std::endl;
            return;
        }

        double total = std::accumulate(
            employees.begin(), employees.end(), 0.0,
            [](double sum, const auto& pair) {
                return sum + pair.second.salary;
            }
        );

        double average = total / employees.size();
        std::cout << "Average Salary: $" << average << std::endl;
    }
};

void basicDisplay(const Employee& b) {
    b.display();
}

void fullDisplay(const Employee& c) {
    c.displayFull();
}


int main() {
    EmployeeManager manager;

    manager.addEmployee(Employee(101, "Alice", "HR", 50000));
    manager.addEmployee(Employee(102, "Bob", "Finance", 65000));
    manager.addEmployee(Employee(103, "Charlie", "Engineering", 70000));
    manager.addEmployee(Employee(104, "Diana", "Engineering", 55000));

    std::cout << std::endl << "Basic Display" << std::endl;
    manager.displayAll(basicDisplay);

    std::cout << std::endl << "Full Display" << std::endl;
    manager.displayAll(fullDisplay);

    std::cout << std::endl << "Deleting Employee with ID 102" << std::endl;
    manager.deleteEmployee(102);

    std::cout << std::endl << "Sorted by Salary" << std::endl;
    manager.Sort([](const Employee& e1, const Employee& e2) {
        return e1.salary > e2.salary;
    });

    std::cout << std::endl << "High Earners" << std::endl;
    manager.HighEarners(55000);

    std::cout << std::endl << "Average Salary" << std::endl;
    manager.AveSalary();

}