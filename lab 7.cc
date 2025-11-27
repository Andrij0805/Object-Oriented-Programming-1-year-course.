#include <iostream>
#include <vector>
#include <random>
#include <ctime>
using namespace std;

class Employee
{
private:
    int hoursWorked;
    double hourlyRate;

public:
    Employee(int hours, double rate) : hoursWorked(hours), hourlyRate(rate) {}

    double getSalary() 
    {
        return hoursWorked * hourlyRate;
    }

    void showInfo() 
   
    {
        cout << "Hours: " << hoursWorked << ", Rate: " << hourlyRate
            << ", Salary: " << getSalary() << endl;
    }
};

int main() 
{
    srand(time(0));

    vector<Employee*> employees;
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int hours = rand() % 161 + 40;      
        double rate = (rand() % 2001 + 500) / 100.0;
        employees.push_back(new Employee(hours, rate));
    }

    double totalCompanyCost = 0;
    cout << "\n--- Employee data ---\n";

    for (auto emp : employees) 
    {
        emp->showInfo();
        totalCompanyCost += emp->getSalary();
    }

    cout << "\nTotal cost for company: " << totalCompanyCost << endl;

   
    for (auto emp : employees)
    {
        delete emp;
    }

    return 0;
}
