#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string line;
    ifstream in("fruit.txt");

    if (!in.is_open())
    {
        cout << "Error: fruit.txt was not found." << endl;
        return 1;
    }

    while (getline(in, line))
    {
        cout << line << endl;
    }
    in.close();

    ofstream file("fruit.txt", ios::app);
    if (!file.is_open())
    {
        cout << "Error: could not open fruit.txt for appending." << endl;
        return 1;
    }

    file << "\nFresh Fruits";
    file.close();

    return 0;
}
