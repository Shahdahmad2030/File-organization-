#include <iostream>
#include <fstream>
#include <limits>
using namespace std;

int main()
{
    char name[20];
    int id;
    float grade;
    char choice;

    // Use app so new records are added without deleting old records.
    ofstream file("students.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error: could not open students.txt" << endl;
        return 1;
    }

    do
    {
        cout << "Enter student name (maximum 19 characters): ";
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        // Each record is separated by the required $ delimiter.
        file << name << ", " << id << ", " << grade << " $" << endl;

        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice == 'y' || choice == 'Y');

    file.close();
    cout << "Student records saved successfully!" << endl;

    return 0;
}
