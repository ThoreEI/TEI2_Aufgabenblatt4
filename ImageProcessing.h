#include <iostream>
#include <sstream>
#include "fstream"
#include "string"
using namespace std;

#ifndef TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
#define TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H

class ImageProcessing {
public:
    ImageProcessing() = default;

    struct Header {
        string type; //type of the given map (P1, P2, P3)
        int width;
        int height;  //information about the given map-image
        int brightness;
    } header;

    struct RGB {
        int red;
        int green;
        int blue;
    };

    void convertToGray(const char *filename) {
        // check the presence of the file
        FILE * file = nullptr;
        file = fopen(filename, "r");
        if (file == nullptr) {
            cout << "An error occurred by trying to open the file";
            return;
        }
        // read the file
        string dataOfImage = PPM::readData(filename); // whole ppm saved in a string

        /*
         * 1. search for comments
         * 2. ignore the rest of the line
         * 3. find the first char of the following line
         * 4. continue till all three headlines are read
         */
        char commentIdentifier = '#';
        size_t beginOfComment = dataOfImage.find(commentIdentifier);
        string firstHeadLine = dataOfImage.substr(0, beginOfComment);
        cout << firstHeadLine << endl;
        header.type = firstHeadLine; // 1st information found

        char nextLineIdentifier = '\n';
        size_t endOfComment = dataOfImage.find(nextLineIdentifier); // found the end of the current line
        int firstCharNextLine = (int) ( endOfComment + 1 );

        beginOfComment = dataOfImage.find(commentIdentifier);
        cout << beginOfComment << endl;
        string secondHeadline = dataOfImage.substr(firstCharNextLine, beginOfComment);
        cout << secondHeadline << endl;

    }

    void edgeDetection() {
        double filter[3][3] = {{-1, -1, -1},  // Faltung eines Graustufenbildes  kantengefiltertes Bild erzeugt
                               {-1, 8,  -1},
                               {-1, 1,  -1}};
    }
};

#endif //TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
