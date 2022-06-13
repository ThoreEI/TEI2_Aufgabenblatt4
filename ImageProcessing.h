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
        if (!isFilePresent(coloredPpmImage))
            return;

        readAndPrintHeaderOfPpmImage(coloredPpmImage, grayedOutPpmImage);

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
        fclose(coloredPpmImage);
        fclose(grayedOutPpmImage);
    }

    void edgeDetection(FILE * grayedOutPpmImage, FILE * edgeFilteredPpmImage) {
        if (!isFilePresent(grayedOutPpmImage))
            return;

        readAndPrintHeaderOfPpmImage(grayedOutPpmImage, edgeFilteredPpmImage);

        int pixelData[header.height][header.width*3];
        for (int height = 0; height < header.height; height++)
        {
            for (int width = 0; width < header.width * 3; width++)
            {
                int currentPixel;
                fscanf(grayedOutPpmImage, "%d", &currentPixel);
                pixelData[height][width] = currentPixel;
            }
        }

        int filter[3][3] = {{-1, -1, -1},
                            {-1, 8,  -1},
                            {-1, 1,  -1}};

        for (int height = 0; height < header.height; height++) {
            if (0 < height)
                fprintf(edgeFilteredPpmImage, "%c", '\n');
            for (int width = 0; width < header.width * 3; width++)
            {
                if (pixelData[height][width] > 0
                    && height > 1
                    && height < header.height
                    && width > 0
                    && width < header.width)
                {
                    int currentPixel = pixelData[height][width];
                    currentPixel *= filter[1][1]; // multiplied by 8
                    currentPixel += (filter[0][0] * pixelData[height - 1][width - 1]);
                    currentPixel += (filter[0][1] * pixelData[height - 1][width]);
                    currentPixel += (filter[0][2] * pixelData[height - 1][width + 1]);
                    currentPixel += (filter[1][0] * pixelData[height][width - 1]);
                    currentPixel += (filter[1][2] * pixelData[height][width + 1]);
                    currentPixel += (filter[2][0] * pixelData[height + 1][width - 1]);
                    currentPixel += (filter[2][1] * pixelData[height + 1][width]);
                    currentPixel += (filter[2][2] * pixelData[height - 1][width + 1]);
                    if (currentPixel > 0 && currentPixel < 10)
                        pixelData[height][width] = currentPixel;

                }
                fprintf(edgeFilteredPpmImage, "%d ", pixelData[height][width]);
            }
        }
        fclose(grayedOutPpmImage);
        fclose(edgeFilteredPpmImage);
    }

    bool isFilePresent(FILE * inputFile) {
        if (inputFile != nullptr)
            return true;
        cout << "An error occurred. Could not open the file.";
        return false;
    }

    void readAndPrintHeaderOfPpmImage(FILE * inputFile, FILE * outputFile) {
        // check the presence of the file
        if (inputFile == nullptr)
        {
            cout << "An error occurred. Could not open the file.";
            return;
        }
        // read the header
        fscanf(inputFile, "%s", header.type);
        fscanf(inputFile, "%d %d %d", &header.width, &header.height, &header.brightness);
        //write header
        fprintf(outputFile, "%s\n", header.type);
        fprintf(outputFile, "%d %d\n", header.width, header.height);
        fprintf(outputFile, "%d\n", header.brightness);
    }
};

#endif //TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
