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
        int height;
        int brightness;
    } header;

    struct RGB {
        int red;
        int green;
        int blue;
    } pixel;

    void convertToGray(FILE * coloredPpmImage, FILE * grayedOutPpmImage) {
        // check the presence of the file
        if (coloredPpmImage == nullptr)
        {
            cout << "An error occurred by trying to open the file";
            return;
        }
        // read the header
        fscanf(coloredPpmImage, "%s", header.type);
        fscanf(coloredPpmImage, "%d %d %d", &header.width, &header.height, &header.brightness);

        //write header
        fprintf(grayedOutPpmImage, "%s\n", header.type);
        fprintf(grayedOutPpmImage, "%d %d\n", header.width, header.height);
        fprintf(grayedOutPpmImage, "%d\n", header.brightness);

        // read the body
        int numberOfPixel = header.width * header.height;
        for (int countOfPixel = 0; countOfPixel < numberOfPixel; countOfPixel++)
        {
            fscanf(coloredPpmImage, "%d %d %d", &pixel.red, &pixel.green, &pixel.blue); //saving the read pixel information
            int grayedOutPixel = (pixel.red + pixel.green + pixel.green) / 3; // computing the gray pixel value
            // write the body
            if (0 < countOfPixel && countOfPixel % header.width == 0) // writing a new line if the current line ends
                fprintf (grayedOutPpmImage, "%c", '\n');
            fprintf(grayedOutPpmImage, "%d %d %d ", grayedOutPixel, grayedOutPixel, grayedOutPixel); // three times R,G,B -> Grey, Grey, Grey
        }
    }

    void edgeDetection() {
        double filter[3][3] = {{-1, -1, -1},  // Faltung eines Graustufenbildes  kantengefiltertes Bild erzeugt
                               {-1, 8,  -1},
                               {-1, 1,  -1}};
    }
};

#endif //TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
