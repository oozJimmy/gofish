//-------------------------------------------------------------------------------------------------
//File Name: courseRequired.cpp
//Associated File: courseRequired.h
//Contains:
// Includes function definitions for associated file, courseRequired.h
//-------------------------------------------------------------------------------------------------

//Header file inclusion
#include "standards.h"

void PrintCourseHeading(ofstream& fout, int width)
//-------------------------------------------------------------------------------------------------
// PrintHeading - Prints the standard heading to the screen
//-------------------------------------------------------------------------------------------------
{
	//Outputs heading to the screen
	fout << setw((width + COLLEGE_NAME.length()) / 2) << COLLEGE_NAME << endl;
	fout << setw((width + NAME.length()) / 2) << NAME << endl;
	fout << setw((width + CLASS_NAME.length()) / 2) << CLASS_NAME << endl;
}

void PrintDivider(ofstream& fout, char symbol, int length)
//-------------------------------------------------------------------------------------------------
// PrintDivider - Prints a divider of specified length and character to the output file
//-------------------------------------------------------------------------------------------------
{
	//Outputs a divider to the output file
	fout << setfill(symbol) << setw(length) << symbol << setfill(' ') << endl;
}

void PrintCenteredMessage(ofstream& fout, string message, int width)
//-------------------------------------------------------------------------------------------------
// PrintCenteredMessage - Gets passed in a message and a width
// Prints the message centered on the width to the designated file
//-------------------------------------------------------------------------------------------------
{
	//Outputs the message centered on the width to the output file
	fout << right << setw((width + message.length()) / 2) << message << endl;
}

void PrintFileName(ofstream& fout, string fileType, string fileName)
//-------------------------------------------------------------------------------------------------
// PrintFileName - Prints the file name and file type in a message to the output file             
//-------------------------------------------------------------------------------------------------
{
	//Print the file type and file name in a message 
	fout << "The " << fileType << " file can be found in the file, " << fileName << endl;
}