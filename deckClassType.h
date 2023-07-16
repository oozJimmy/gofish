//-------------------------------------------------------------------------------------------------
//File Name: deckClassType.h
//Associated file:  deckClassType.cpp
//Members:          
//  1 Constructor: Default
//  Standard Methods:
//   Get  -  GetDeckTag, GetCardInPosition
//   Set   - SetDeckTag
//   Print - PrintTheDeck
// Other Methods: CreateDeck, ShuffleTheDeck, Swap, Sort, FindIndexOfLowestRank, 
//                AddCardToDeck, RemoveCardFromDeck
//-------------------------------------------------------------------------------------------------
#ifndef deckClassType_h
#define deckClassType_h

//#Header file inclusion
#include "cardClassType.h"

//Constant variable declaration
const int DECK_SIZE = 52;

class deckClassType
{
private:
	//Private member data
	cardClassType deck[52];
	int deckTag;

public:
	//Constructor
	deckClassType(void) { deckTag = 0; }

	//Public methods
	int GetDeckTag(void) { return deckTag; }
	cardClassType GetCardInPosition(int position) { return deck[position]; }
	void SetDeckTag(int newTag) { deckTag = newTag; }
	void SetCardInPosition(int position, cardClassType newCard) { deck[position] = newCard; }
	void CreateDeck(void);
	void ShuffleTheDeck(void);
	void Swap(cardClassType& first, cardClassType& second);
	void PrintTheDeck(void);
	void Sort(void);
	int FindIndexOfLowestRank(int position);
	void AddCardToDeck(cardClassType addCard);
	void RemoveCardFromDeck(int position);
	
};
#endif
