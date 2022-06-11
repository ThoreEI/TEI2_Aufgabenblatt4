#include <iostream>
#include "fstream"
#include "string"
using namespace std;

#ifndef TEI2_AUFGABENBLATT4_PPM_H
#define TEI2_AUFGABENBLATT4_PPM_H

class PPM {
public:
    static string readData(const string& fileReadingImage) {
        string readData;
        ifstream inFile(fileReadingImage);
        if (!inFile)    // checking presence
            cout << "An error occurred by trying to open the file";
        else
            while (getline(inFile, readData, ';')); // reading all lines and "save" them in string data
                inFile.close();
        return readData;
    }

    static void writeData(const string& fileOfPpmImage, const string& fileOfNewPpmImage) {
        ofstream outFile;
        outFile.open(fileOfNewPpmImage,ios::out);
        if (!outFile) // checking presence
            cout << "An error occurred. Could not open the file.";
        else
            outFile << fileOfPpmImage << flush; // free up buffer after the data of the image is written down
        outFile.close();
    }
};
#endif //TEI2_AUFGABENBLATT4_PPM_H