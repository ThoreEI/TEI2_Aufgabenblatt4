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
            fprintf(grayedOutPpmImage, "%d ", grayedOutPixel); // three times R,G,B -> Grey, Grey, Grey
        }
        fclose(coloredPpmImage);
        fclose(grayedOutPpmImage);
    }

    void edgeDetection(FILE * grayedOutPpmImage, FILE * edgeFilteredPpmImage) {
        if (!isFilePresent(grayedOutPpmImage))
            return;

        readAndPrintHeaderOfPpmImage(grayedOutPpmImage, edgeFilteredPpmImage);

        // fill 2D Array with read body-information
        int pixelData[header.height][header.width];
        for (int height = 0; height < header.height; height++) {
            for (int width = 0; width < header.width; width++) {
                int currentPixel;
                fscanf(grayedOutPpmImage, "%d", &currentPixel);
                pixelData[height][width] = currentPixel;
            }
        }

        for (int height = 0; height < header.height; height++)
        {
            if (0 < height)
                fprintf(edgeFilteredPpmImage, "%c", '\n');
            for (int width = 0; width < header.width; width++)
            {

                int currentPixel = pixelData[height][width];

                if (currentPixel > 0 && width > 0 && width < header.width && height > 0 && height < header.height) {

                    int up = height - 1;
                    int down = height + 1;
                    int left = width - 1;
                    int right = width + 1;

                    currentPixel *= 8;
                    currentPixel += (pixelData[up][left] * -1 + pixelData[up][width] *-1 + pixelData[up][right] * -1 + pixelData[height][left] *-1
                                     + pixelData[height][right] *-1 + pixelData[down][left] * -1 + pixelData[down][width] *-1 + pixelData[down][right] *-1);
                    if (currentPixel < 0)
                        currentPixel = 0;


                    /*

                         int calculationValues[9];
                    for (int i = 0; i < sizeof(calculationValues) / sizeof(calculationValues[0]); i++) {
                        calculationValues[i] = 0;
                    }
                    bool validUp, validLeft, validRight, validDown;

                    validUp = height > 0;
                    validDown = height != header.height;
                    validLeft = width > 0;
                    validRight = width != header.width;

                    calculationValues[0] = pixelData[height][width] * 8;

                    int newPixelValue = 0;

                    if (calculationValues[0] != 0) {

                        if (validUp) {
                            calculationValues[1] = pixelData[up][width] * -1;

                            if (validLeft) {
                                calculationValues[2] = pixelData[up][left] * -1;
                            }

                            if (validRight) {
                                calculationValues[3] = pixelData[up][right] * -1;
                            }
                        }

                        if (validDown) {
                            calculationValues[4] = pixelData[down][width] * -1;

                            if (validLeft) {
                                calculationValues[5] = pixelData[down][left] * -1;
                            }

                            if (validRight) {
                                calculationValues[6] = pixelData[down][right] * -1;
                            }
                        }

                        if (validLeft) {
                            calculationValues[7] = pixelData[height][left] * -1;
                        }

                        if (validRight) {
                            calculationValues[8] = pixelData[height][right] * -1;
                        }

                        for (int pixelValue: calculationValues) {
                            newPixelValue += pixelValue;
                        }
                    } else {
                        newPixelValue = 0;
                    }
                     if (newPixelValue / 9 < 0)
                        newPixelValue = 0;
                    fprintf(edgeFilteredPpmImage, "%d ", (newPixelValue / 9));
                    */

                    fprintf(edgeFilteredPpmImage, "%d ", currentPixel);
                } else {
                    fprintf(edgeFilteredPpmImage,"%d ", currentPixel);
                }


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
        // read the header
        fscanf(inputFile, "%s", header.type);
        fscanf(inputFile, "%d %d %d", &header.width, &header.height, &header.brightness);
        //write header
        fprintf(outputFile, "%s\n", "P2");
        fprintf(outputFile, "%d %d\n", header.width, header.height);
        fprintf(outputFile, "%d\n", header.brightness);
    }
};

#endif //TEI2_AUFGABENBLATT4_IMAGEPROCESSING_H
