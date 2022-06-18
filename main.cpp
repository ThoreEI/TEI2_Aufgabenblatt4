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
    string filenameOfPpmImage = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//coloredPicture.ppm";   // How can I get the path to the project?
    string dataOfImage = PPM::readData(filenameOfPpmImage);
    // writing part
    string filenameOfNewPpm = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//grayedOutPicture.ppm";
    PPM::writeData(dataOfImage, filenameOfNewPpm);
    /*
     * Aufgabe 2
     */
    auto imageProcessing = new ImageProcessing();
    FILE * coloredPpmImage = fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//coloredPicture.ppm", "r");
    FILE * grayedOutPpmImage = fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//grayedOutPicture.ppm", "w");
    imageProcessing->convertToGray(coloredPpmImage,grayedOutPpmImage);

    //reopening the file --> resetting pointer & changing mode
    grayedOutPpmImage = fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//grayedOutPicture.ppm", "r");

    FILE * edgeFilteredPpmImage = fopen("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//edgeFilteredPicture.ppm", "w");
    imageProcessing->edgeDetection(grayedOutPpmImage, edgeFilteredPpmImage);
    return 0;
}
