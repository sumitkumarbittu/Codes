/*

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Student
{
    string name;
    int roll;
    string section;

    public:
    Student(string studentName, int studentroll, string studentsection) 
    {
        for(char c : studentName)
        {
            if (isdigit(c)) {
                cerr << "Error: Student name contains digits." << endl;
                exit(1);
            }
        }
        name = studentName;
        roll = studentroll;
        section = studentsection;
        cout << "Student created successfully." << endl;
    }

    void displayDetails() const {
        cout << "Name: " << name << endl;
        cout << "Roll No: " << roll << endl;
        cout << "Section: " << section << endl;
    }
};

int main()
{
    try
    {
        Student student1("JohnDoe", 20, "A");
        student1.displayDetails();

        Student student2("John123", 22, "B");
        student2.displayDetails();
    }
    catch (const exception &e)
    {
        cout << "Exception caught: " << e.what() << endl;
    }
    return 0;
}

*/ 











/*

#include<iostream>

using namespace std;

int main()
{
    try 
    {
        int a = 10, b = 0;
        if (b == 0) 
        {
            throw "Division by zero error!";
        }
        cout << "Result: " << a / b << endl;
    } catch (const char* m) {
        cout << "Exception caught: " << m << endl;
    }
    return 0;
}

*/