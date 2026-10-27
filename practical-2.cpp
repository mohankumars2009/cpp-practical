
#include <iostream>
#include <string>
using namespace std;

class Student
{
public:
    int rollNo;
    string name;

    // Constructor
    Student()
    {
        cout << "Student object created" << endl;
    }

    // Function to get input
    void getDetails()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Student Name: ";
        getline(cin >> ws, name);
    }

    // Function to display details
    void display()
    {
        cout << "\nRoll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }

    // Destructor
    ~Student()
    {
        cout << "Student object destroyed" << endl;
    }
};

int main(){
    Student s;
    s.getDetails();
    s.display();

    return 0;
}
