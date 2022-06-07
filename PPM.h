#include <iostream>
#include "fstream"
#include "string"
using namespace std;

#ifndef TEI2_AUFGABENBLATT4_PPM_H
#define TEI2_AUFGABENBLATT4_PPM_H

class PPM {
public:
    static string readData(const string& fileReadingImage) {
        string readInformation;
        ifstream inFile(fileReadingImage);
        if (!inFile.is_open())
            cout << "An error occurred. Could not open the file.";
        else
            while (getline(inFile, readInformation, ';'));

        inFile.close();
        return readInformation;
    }

    static void writeData(const string& dataOfImage, const string& fileWritingImage) {
        ofstream outFile;
        outFile.open(fileWritingImage,ios::out);
        if (!outFile)
            cout << "An error occurred. Could not open the file.";
        else
            outFile << dataOfImage << flush;

        outFile.close();
    }
};
#endif //TEI2_AUFGABENBLATT4_PPM_H