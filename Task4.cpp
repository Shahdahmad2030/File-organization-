#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;

    cout << "Enter number of persons: ";
    cin >> n;

    ofstream outFile("persons.txt");

    for (int i = 0; i < n; i++)
    {
        Person p;

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, p.name);

        cout << "Enter age: ";
        cin >> p.age;

        outFile << p.name << endl;
        outFile << p.age << endl;
    }

    outFile.close();

    vector<Person> persons;
    ifstream inFile("persons.txt");
    Person p;

    while (getline(inFile, p.name))
    {
        inFile >> p.age;
        inFile.ignore();
        persons.push_back(p);
    }

    inFile.close();

    if (persons.empty())
    {
        cout << "No persons found!" << endl;
        return 0;
    }

    Person youngest = persons[0];
    Person oldest = persons[0];

    for (int i = 1; i < persons.size(); i++)
    {
        if (persons[i].age < youngest.age)
            youngest = persons[i];

        if (persons[i].age > oldest.age)
            oldest = persons[i];
    }

    ofstream resultFile("results.txt");

    resultFile << "Youngest Person: "
               << youngest.name << " "
               << youngest.age << endl;

    resultFile << "Oldest Person: "
               << oldest.name << " "
               << oldest.age << endl;

    resultFile.close();

    cout << "Results saved successfully!" << endl;
    return 0;
}
