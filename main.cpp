/*
 * Cole Deushane
 * 3 December 2019
 * Used to seperate sentences on a document for editing purposes
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    char ch;
    int count = 0;
    string fileName;
    ifstream inputFile;
    ofstream outputFile;

    cout << "Enter file name: ";
    cin >> fileName;

    inputFile.open(fileName);
    outputFile.open("output.txt");

    if(!inputFile) {
        cout << "Error, file did not open.\n";
        return -1;
    }

    if(!outputFile) {
        cout << "Error, output did not open.\n";
        return -1;
    }

    //cout << "==> ";
    outputFile << "==> ";

    while(inputFile.get(ch)) {
        if(ch == '.' || ch == '?' || ch == '!') {
            //cout << ch << endl << endl << "==> ";
            count++;
            outputFile << ch << endl << endl << "==> ";
        } else {
            //cout << ch;
            outputFile << ch;
        }
    }

    //cout << count;
    outputFile << count << " sentences.";

    inputFile.close();
    outputFile.close();
    cout << "finished";
    return 0;
}
