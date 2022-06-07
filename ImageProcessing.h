#include <iostream>
#include "fstream"
#include "string"
#include <stdlib.h>
#include <string.h>
using namespace std;

#ifndef TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
#define TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H

class ImageProcessing {
public:
    ImageProcessing()= default;

    struct Header {
        char type[2]; //type of the given map (P1, P2, P3)
        int width;
        int height;  //information about the given map-image
        int brightness;
    };

    struct RGB {
        int red;
        int green;
        int blue;
    };

    void convertToGray(const char *filename) {

        // read header
        FILE * file = nullptr;
        file =  fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//smileyToRead.txt", "r");
        if (file == nullptr) {
            cout << "An error occurred.";
            return;
        }

        char header[3];
        fscanf(file, "%s", header);
        char information[3];
        fscanf(file, "%d", information);
        cout << header[0] << header[1]  << endl;

        cout << (int) information[0] << (int) information[1];

        FILE *file2;
        file2 = fopen("test2.ppm", "w");
    }

    void edgeDetection() {
        double filter[3][3] = {{-1, -1,-1},  // Faltung eines Graustufenbildes  kantengefiltertes Bild erzeugt
                               {-1, 8, -1},
                               {-1, 1, -1} };
    }
};

#endif //TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
