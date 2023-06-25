#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    string inputFileName;
    string outputFileName;

    cout << "Input file: ";
    cin >> inputFileName;

    cout << "Output file: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    istream_iterator<int> inputIter(inputFile);
    istream_iterator<int> inputEnd;

    ostream_iterator<int> outputIter(outputFile, " ");

    // Використання алгоритму remove_copy_if для відбору чисел з непарними порядковими номерами
    remove_copy_if(inputIter, inputEnd, outputIter,
        [&](int value) {
            static int count = 0;
    bool isOdd = ++count % 2 != 0; // Перевірка на непарний порядковий номер
    if (isOdd) {
        cout << value << " "; // Виведення числа на консоль
    }
    return !isOdd;
        });

    inputFile.close();
    outputFile.close();

    cout << endl << "Work finished." << endl;

    return 0;
}