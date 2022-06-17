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
    string filenameOfPpmImage = "C:\\Users\\School\\git\\gthub\\files\\black.ppm";
    //string filenameOfPpmImage = "/home/user/CLionProjects/TEI2_Aufgabenblatt4/files/coloredSmiley.ppm";
    string dataOfImage = PPM::readData(filenameOfPpmImage);
    // writing part
    string filenameOfNewPpm = "C:\\Users\\School\\git\\gthub\\files\\grayedOutPicture.ppm";
    //string filenameOfNewPpm = "/home/user/CLionProjects/TEI2_Aufgabenblatt4/files/grayedOutSmiley.ppm";
    PPM::writeData(dataOfImage, filenameOfNewPpm);

    /*
     * Aufgabe 2
     */

    auto imageProcessing = new ImageProcessing();

    FILE * coloredPpmImage = fopen("C:\\Users\\School\\git\\gthub\\files\\black.ppm", "r");
    //FILE * coloredPpmImage = fopen("/home/user/CLionProjects/TEI2_Aufgabenblatt4/files/coloredSmiley.ppm", "r");
    FILE * grayedOutPpmImage = fopen("C:\\Users\\School\\git\\gthub\\files\\grayedOutPicture.ppm", "w");
    //FILE * grayedOutPpmImage = fopen("/home/user/CLionProjects/TEI2_Aufgabenblatt4/files/grayedOutSmiley.ppm", "w");

    imageProcessing->convertToGray(coloredPpmImage,grayedOutPpmImage);

    //reopening the file --> resetting pointer & changing mode
    grayedOutPpmImage = fopen("C:\\Users\\School\\git\\gthub\\files\\grayedOutPicture.ppm", "r");
    //grayedOutPpmImage = fopen("/home/user/CLionProjects/TEI2_Aufgabenblatt4/files/grayedOutSmiley.ppm", "r");

    FILE * edgeFilteredPpmImage = fopen("C:\\Users\\School\\git\\gthub\\files\\edgeFilteredPicture.ppm", "w");
    // FILE * edgeFilteredPpmImage = fopen("/home/user/CLionProjects/TEI2_Aufgabenblatt4/files/edgeFilteredSmiley.ppm", "w");

    imageProcessing->edgeDetection(grayedOutPpmImage, edgeFilteredPpmImage);
    return 0;
}
