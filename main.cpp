#include "PPM.h"

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

    return 0;
}
