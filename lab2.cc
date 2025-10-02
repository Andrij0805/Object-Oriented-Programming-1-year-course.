#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class ConsolIO 
{
public:
    static double GetValue()
    {
        double value;
        while (true)
        {
            cin >> value;
            if (cin.fail())
            {
                cout << "\n\tINVALID INPUT! Expected a number.\nPlease try again: ";
                cin.clear();
                while (cin.get() != '\n');
            }
            else break;
        }
        cin.ignore();
        return value;
    }

    static string GetText() 
    {
        string buffer;
        while (true)
        {
            getline(cin, buffer);
            bool allSpaces = true;
            for (char c : buffer) if (c != ' ') allSpaces = false;
            if (!buffer.empty() && !allSpaces) break;
            cout << "\n\tINVALID INPUT! Please enter text: ";
        }
        return buffer;
    }
};

class Student 
{
private:
    string lastName;
    int studentID;
    int* grades;
    int numGrades;

public:
    Student() : lastName("Unknown"), studentID(0), grades(nullptr), numGrades(0) {}

    ~Student()
    {
        delete[] grades;
    }

    void setLastName(const string& ln) { lastName = ln; }
    string getLastName() { return lastName; }

    void setStudentID(int id) { studentID = id; }
    int getStudentID() { return studentID; }

    void setGrades(int* arr, int n)
    {
        delete[] grades;
        numGrades = n;
        grades = new int[n];
        for (int i = 0; i < n; i++) grades[i] = arr[i];
    }

    double getAverage()
    {
        if (numGrades == 0) return 0;
        double sum = 0;
        for (int i = 0; i < numGrades; i++) sum += grades[i];
        return sum / numGrades;
    }

    void printInfo()
    {
        cout << "Student: " << lastName
            << " | ID: " << studentID
            << " | Average Grade: " << getAverage() << endl;
    }
};

class Group 
{
private:
    Student* students;
    int count;

public:
    Group(int n) : count(n) { students = new Student[n]; }

    ~Group() 
    {
        delete[] students; 
    }

    void FillStudents() 
    {
        for (int i = 0; i < count; i++)
        {
            cout << "\nStudent #" << i + 1 << endl;

            cout << "Last Name: ";
            students[i].setLastName(ConsolIO::GetText());

            cout << "Student ID: ";
            students[i].setStudentID((int)ConsolIO::GetValue());

            cout << "Number of grades: ";
            int n = (int)ConsolIO::GetValue();
            int* arr = new int[n];
            for (int j = 0; j < n; j++) {
                cout << "Grade #" << j + 1 << ": ";
                arr[j] = (int)ConsolIO::GetValue();
            }
            students[i].setGrades(arr, n);
            delete[] arr;
        }
    }

    void ShowAll()
    {
        cout << "\n   All Students   \n";
        for (int i = 0; i < count; i++)
            students[i].printInfo();
    }

    void ShowTop5() 
    {
        Student** sorted = new Student * [count];
        for (int i = 0; i < count; i++) sorted[i] = &students[i];

     
        for (int i = 0; i < count - 1; i++)
        {
            for (int j = i + 1; j < count; j++)
            {
                if (sorted[i]->getAverage() < sorted[j]->getAverage()) 
                {
                    Student* tmp = sorted[i];
                    sorted[i] = sorted[j];
                    sorted[j] = tmp;
                }
            }
        }

        cout << "\n   Top 5 Students by Average Grade   \n";
        int top = count < 5 ? count : 5;
        for (int i = 0; i < top; i++)
            sorted[i]->printInfo();

        delete[] sorted;
    }
};

int main() 
{
    cout << "Enter number of students in the group: ";
    int n = (int)ConsolIO::GetValue();
    Group group(n);

    group.FillStudents();
    group.ShowAll();
    group.ShowTop5();

    cout << "\nPress any key to exit...\n";
    while (!_kbhit());
    return 0;
}
