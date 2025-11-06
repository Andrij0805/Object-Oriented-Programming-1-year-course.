#include <iostream>
#include <string>
using namespace std;

class Person
{
protected:
    string name;
    int age;

public:

    Person(string n, int a) : name(n), age(a) {}
    virtual ~Person() {}

    virtual void operator++()
    {
        age++;
        cout << name << " is now " << age << " years old." << endl;
    }

    virtual void print() const
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};
class Student : public Person
{
private:
    int course;

public:
    Student(string n, int a, int c) : Person(n, a), course(c) {}


    void operator++() override
    {
        course++;
        cout << name << " has moved to course " << course << "." << endl;
    }

    void print() const override
    {
        cout << "Name: " << name << ", Age: " << age
            << ", Course: " << course << endl;
    }
};
int main()
{
    Person* person1 = new Person("Oleh", 30);
    Person* person2 = new Student("Maria", 19, 2);

    cout << "Initial data:" << endl;
    person1->print();
    person2->print();

    cout << "\nCalling operators ++" << endl;
    ++(*person1);
    ++(*person2);

    cout << "\nAfter changes:" << endl;
    person1->print();
    person2->print();

    delete person1;
    delete person2;

    return 0;
}
