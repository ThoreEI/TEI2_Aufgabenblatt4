#include "PPM.h"
#include "ImageProcessing.h"
int main()
{
    /*
     * Aufgabe 1
     */

    // reading part
   string fileReadingImage = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//smileyToRead.txt";
    string dataOfImage = PPM::readData(fileReadingImage);

    // writing part
    string fileWritingImage = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//writtenSmiley.ppm";
    PPM::writeData(dataOfImage, fileWritingImage);

    /*
     * Aufgabe 2
     */
    auto * imageProcessing = new ImageProcessing();
    imageProcessing->convertToGray("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//smileyToRead.txt");
    return 0;
}
