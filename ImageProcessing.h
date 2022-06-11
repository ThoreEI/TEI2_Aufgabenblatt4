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
        char type[2]; //type of the given map (P1, P2, P3)
        int width;
        int height;  //information about the given map-image
        int brightness;
    } header;

    struct RGB {
        int red;
        int green;
        int blue;
    } rgbPixel;

    void convertToGray(const char *filename) {
        // check the presence of the file
        FILE * ppmImage = nullptr;
        ppmImage = fopen(filename, "r");
        if (ppmImage == nullptr) {
            cout << "An error occurred by trying to open the file";
            return;
        }
        // read the header
        fscanf(ppmImage, "%s", header.type);
        fscanf(ppmImage, "%d %d %d", &header.width, &header.height, &header.brightness);

    }


    void edgeDetection() {
        double filter[3][3] = {{-1, -1, -1},  // Faltung eines Graustufenbildes  kantengefiltertes Bild erzeugt
                               {-1, 8,  -1},
                               {-1, 1,  -1}};
    }
};

#endif //TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
