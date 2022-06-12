#include "PPM.h"
#include "ImageProcessing.h"
using std::cout; using std::cin;
using std::endl; using std::string;

int main()
{
    /*
     * Aufgabe 1
     */

    // reading part
    string filenameOfPpmImage = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//coloredSmiley.ppm";
    string dataOfImage = PPM::readData(filenameOfPpmImage);
    // writing part
     string filenameOfNewPpm = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//grayedOutSmiley.ppm";
    PPM::writeData(dataOfImage, filenameOfNewPpm);

    /*
     * Aufgabe 2
     */
    FILE * coloredPpmImage = fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//coloredSmiley.ppm", "r");
    FILE * grayedOutPpmImage = fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//grayedOutSmiley.ppm", "w");
    auto imageProcessing = new ImageProcessing();
    imageProcessing->convertToGray(coloredPpmImage,grayedOutPpmImage);
    imageProcessing->edgeDetection();
    return 0;
}
