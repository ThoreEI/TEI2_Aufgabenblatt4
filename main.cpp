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
    string filenameOfPpm = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//smileyToRead.txt";
    string dataOfImage = PPM::readData(filenameOfPpm);
    // writing part
     string filenameOfNewPpm = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//writtenSmiley.ppm";
    PPM::writeData(dataOfImage, filenameOfNewPpm);

    /*
     * Aufgabe 2
     */
    const char * filenameOfGrayedOutPpm = "C://Users//UnknownUser//CLionProjects//TEI2_Aufgabenblatt4//files//smileyToRead.txt";
    auto * imageProcessing = new ImageProcessing();
    imageProcessing->convertToGray(filenameOfGrayedOutPpm);
    return 0;
}
