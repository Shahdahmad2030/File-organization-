#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main() {
    int grades[5] = {90, 85, 70, 95, 80};

    // 1. Create grades.txt and write five integer grades.
    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error: Could not create grades.txt\n";
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        outFile << grades[i] << endl;
    }
    outFile.close();

    // 2. Read and print the grades using a correct reading loop.
    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Error: Could not open grades.txt\n";
        return 1;
    }

    int grade;
    cout << "Grades before deletion:\n";
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();

    // 3. Ask the user which grade should be deleted.
    int gradeToDelete;
    cout << "Enter the grade to delete: ";
    if (!(cin >> gradeToDelete)) {
        cout << "Error: Invalid grade input.\n";
        return 1;
    }

    // Create a temporary file without the selected grade.
    inFile.open("grades.txt");
    ofstream tempFile("temp.txt");

    if (!inFile || !tempFile) {
        cout << "Error: Could not open the files.\n";
        return 1;
    }

    bool found = false;
    while (inFile >> grade) {
        if (grade == gradeToDelete) {
            found = true;
        } else {
            tempFile << grade << endl;
        }
    }

    inFile.close();
    tempFile.close();

    // 4. Replace the original file with the temporary file.
    if (!found) {
        remove("temp.txt");
        cout << "Error: Grade not found. Original file was not changed.\n";
        return 0;
    }

    if (remove("grades.txt") != 0) {
        cout << "Error: Could not remove the original file.\n";
        return 1;
    }

    if (rename("temp.txt", "grades.txt") != 0) {
        cout << "Error: Could not rename the temporary file.\n";
        return 1;
    }

    cout << "Grade deleted successfully!\n";
    cout << "Grades after deletion:\n";

    inFile.open("grades.txt");
    if (!inFile) {
        cout << "Error: Could not open the updated file.\n";
        return 1;
    }

    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();

    return 0;
}
