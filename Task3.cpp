#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    // First write the original sentence to the file.
    ofstream createFile("welcome.txt");
    if (!createFile.is_open())
    {
        cout << "Error: could not create welcome.txt" << endl;
        return 1;
    }
    createFile << "Hello Everybody";
    createFile.close();

    // Read the sentence, replace "body" with "one",
    // then write the final sentence back to the same file.
    ifstream in("welcome.txt");
    string text;
    getline(in, text);
    in.close();

    size_t position = text.find("body");
    if (position != string::npos)
    {
        text.replace(position, 4, "one");
    }

    ofstream out("welcome.txt");
    out << text;
    out.close();

    cout << text << endl;
    return 0;
}
