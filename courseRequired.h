//-------------------------------------------------------------------------------------------------
//File Name: courseRequired.h
//Associated File: courseRequired.cpp
//Contains:
// Header file inclusion and function prototypes for associated file courseRequired.h
//-------------------------------------------------------------------------------------------------
#ifndef courseRequired_h
#define courseRequired_h

//Header file inclusion
#include "standards.h"

//Function Prototypes
void PrintCourseHeading(ofstream& fout, int width);

void PrintDivider(ofstream& fout, char symbol, int length);

void PrintCenteredMessage(ofstream& fout, string message, int width);

void PrintFileName(ofstream& fout, string fileType, string fileName);

#endif
