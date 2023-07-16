//-------------------------------------------------------------------------------------------------
//File Name: cardClassType.cpp
//Associated file:  cardClassType.h
//Members:          
//  2 Constructors  : Default and with integer arguments for rank and suit
//  Standard Methods:
//   Get  -  GetRank, GetSuit
//   Set   - SetRank, SetSuit
//   Print - none
// Other Methods: Operator overloads for <,>,== and <<
//   
//-------------------------------------------------------------------------------------------------
//Header file inclusion
#include "cardClassType.h"

ostream& operator<<(ostream& fout, cardClassType& card)
//-------------------------------------------------------------------------------------------------
// operator<< - Outputs a card with rank and suit 
//-------------------------------------------------------------------------------------------------
{
	//Declare local variables
	char printChar;
	int tempRank;

	//Set tempRank
	tempRank = card.GetRank();

	//Conditional to test tempRank
	if (tempRank >= 2 && tempRank <= 10)
	{
		//Print the card rank and suit
		fout << setw(5) << card.GetRank() << (char)card.GetSuit();
	}
	else
	{
		//Switch to set printChar
		switch (tempRank)
		{
		case 11:
			printChar = 'J';
			break;
		case 12:
			printChar = 'Q';
			break;
		case 13:
			printChar = 'K';
			break;
		default:
			printChar = 'A';
			break;
		}

		//Print the card rank and suit
		fout << setw(5) << printChar << (char)card.GetSuit();
	}
	return fout;
}