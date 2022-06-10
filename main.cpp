#include "PPM.h"
#include "ImageProcessing.h"
#include <libgen.h>
using std::cout; using std::cin;
using std::endl; using std::string;

int main(int argc, char* argv[])
{
    /*
     * Aufgabe 1
     */

    // reading part
    string fileReadingImage ="C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//smileyToRead.txt";
    string dataOfImage = PPM::readData(fileReadingImage);

    // writing part
    string fileWritingImage = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//writtenSmiley.ppm";
    PPM::writeData(dataOfImage, fileWritingImage);

    /*
     * Aufgabe 2
     */
    auto * imageProcessing = new ImageProcessing();
    imageProcessing->convertToGray("C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//smileyToRead.txt");
    return 0;
}
