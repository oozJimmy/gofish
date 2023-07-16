//-------------------------------------------------------------------------------------------------
//File Name: KinsleyJLab4.cpp
//Associated File: none
//Contains:
// Includes main function 
//-------------------------------------------------------------------------------------------------

//Header file inclusions
#include "gameClassType.h"

int main(void)
{
	//Print the course heading to the screen
	PrintDivider(static_cast<ofstream&>(cout), '-', WIDTH);
	PrintCourseHeading(static_cast<ofstream&>(cout), WIDTH);
	PrintDivider(static_cast<ofstream&>(cout), '-', WIDTH);

	//Declare deckClassType object
	deckClassType mainDeck;

	//Call for the random seed function
	srand((unsigned int)time(NULL));

	//Create the deck
	mainDeck.CreateDeck();

	//Print the deck
	mainDeck.PrintTheDeck();

	//Print a divider
	PrintDivider(static_cast<ofstream&>(cout), '-', WIDTH);

	//Shuffle the deck
	mainDeck.ShuffleTheDeck();

	//Print the deck
	mainDeck.PrintTheDeck();

	//Create game
	gameClassType goFish;

	goFish.StackTheDeck(mainDeck);

	goFish.Deal();

	//Start the game
	goFish.Run();

	return 0;
}
