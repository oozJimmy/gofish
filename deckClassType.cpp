//-------------------------------------------------------------------------------------------------
//File Name: deckClassType.cpp
//Associated file:  deckClassType.h
//Members:          
//  1 Constructor: Default
//  Standard Methods:
//   Get  -  GetDeckTag, GetCardInPosition
//   Set   - SetDeckTag
//   Print - PrintTheDeck
// Other Methods: CreateDeck, ShuffleTheDeck, Swap, Sort, FindIndexOfLowestRank, 
//                AddCardToDeck, RemoveCardFromDeck
//-------------------------------------------------------------------------------------------------
//Header file inclusion
#include "deckClassType.h"

void deckClassType::CreateDeck(void)
//-------------------------------------------------------------------------------------------------
// CreateDeck - Creates an ordered standard deck of 52 cards
//-------------------------------------------------------------------------------------------------
{
	//Declare local variables
	int rank = 1;
	int suit = heart;

	//Loop to run until each card has been set
	for (int index = 0; index < DECK_SIZE; index++)
	{
		//Set the rank and suit of the card in the deck
		deck[index].SetRank(rank);
		deck[index].SetSuit(suit);

		//Increment rank
		rank++;

		//Conditional to increment suit and reset rank
		if (rank == 14)
		{
			rank = 1;
			suit++;
		}
	}
	
	//Set deck tag to constant deck size
	deckTag = DECK_SIZE;
}

void deckClassType::ShuffleTheDeck(void)
//-------------------------------------------------------------------------------------------------
// ShuffleTheDeck - Shuffles the indexes of the deck of cards
//-------------------------------------------------------------------------------------------------
{
	//Declare local variables
	int randSpot;
	int index;

	//Loop to run for each card in the deck
	for (index = 0; index < DECK_SIZE; index++)
	{
		//Get a random number between 0 and 51
		randSpot = rand() % DECK_SIZE;

		/// We then swap the card sport we are on (index) with the random spot
		swap(deck[index], deck[randSpot]);

	}
}

void deckClassType::Swap(cardClassType& first, cardClassType& second)
//-------------------------------------------------------------------------------------------------
// Swap - Swaps two cardClassType objects with a temporary variable
//-------------------------------------------------------------------------------------------------
{
	//Declare temp class 
	cardClassType tempCard;

	//Use temp variable to swap the two objects
	tempCard = first;
	first = second;
	second = tempCard;
}

void deckClassType::PrintTheDeck()
//-------------------------------------------------------------------------------------------------
// PrintTheDeck - Prints all the cards in the deck with rank and suit in rows and columns
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	int index;
	int card = 1;
	int suitChange = 1;

	//Loop to run for each card in the deck
	for (index = 0; index < deckTag; index++)
	{
		//Print the card
		cout << deck[index];

		//Increment the line/suit change counter
		suitChange++;

		//Conditional to check for high bound of suitChange
		if (suitChange == 14)
		{
			//Reset suitChange to 1
			suitChange = 1;

			//Set the output cursor to the next line
			cout << endl;
		}
	}

	//Move the output cursor down a line
	cout << endl;
}

void deckClassType::Sort(void)
//-------------------------------------------------------------------------------------------------
// Sort - Sorts the cards in the deck by rank
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	int indexOfLowestRank;

	//For loop to run through the deck
	for (int counter = 0; counter < deckTag; counter++)
	{
		//Call method to find the index with the smallest rank
		indexOfLowestRank = FindIndexOfLowestRank(counter);

		//Swap the index with the lowest rank to the current index
		Swap(deck[counter], deck[indexOfLowestRank]);
	}
}

int deckClassType::FindIndexOfLowestRank(int position)
//-------------------------------------------------------------------------------------------------
// FindIndexOfLowestRank - Returns the index of the lowest rank in the array
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	int lowestIndex;

	//Set lowestIndex to position
	lowestIndex = position;

	//Loop to run from position to the end of the deck
	for (int counter = position+1; counter < deckTag; counter++)
	{
		//Conditional to check the rank of the current index vs the lowest index
		if (deck[counter] < deck[lowestIndex])
		{
			//Set the current index to the lowest index
			lowestIndex = counter;
		}
	}

	return lowestIndex;
}

void deckClassType::AddCardToDeck(cardClassType addCard)
//-------------------------------------------------------------------------------------------------
// AddCardToDeck - Adds a card to the end of the deck
//-------------------------------------------------------------------------------------------------
{
	//Adds the card to the end of the players deck
	deck[deckTag] = addCard;

	//Increment the tag field for the players hand
	deckTag++;
}
void deckClassType::RemoveCardFromDeck(int position)
//-------------------------------------------------------------------------------------------------
// RemoveCardFromDeck - Removes the card at position from the deck
//-------------------------------------------------------------------------------------------------
{
	//Set the last card in the players deck to the index of position
	deck[position] = deck[deckTag - 1];

	//Decrement the deck tag
	deckTag--;
}