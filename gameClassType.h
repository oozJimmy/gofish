//-------------------------------------------------------------------------------------------------
//File Name: gameClassType.h
//Associated file:  gameClassType.cpp
//Members:          
//  1 Constructor  : Calls SetPlayerFirst, sets autoPlay to false and book counts to 0
//  Standard Methods:
//   Get  -  GetPlayerFirst
//   Set   - SetPlayerFirst
//   Print - 
// Other Methods: StackTheDeck, Deal, ShowPlayerHand, CpuTurn, PlayerTurn, DrawIfEmpty, 
// FindRankChoice, ChoiceInDeck, CheckForBooks Run, PromptAutoPlay,CountBooks
//-------------------------------------------------------------------------------------------------
#ifndef gameClassType_h
#define gameClassType_h
//Header file inclusion
#include "stackClassType.h"
#include "deckClassType.h"
#include "cardClassType.h"

class gameClassType
{
private:
	//Private member variables
	deckClassType playerHand;
	deckClassType cpuHand;
	
	stackClassType fishStack;
	stackClassType playerBook;
	stackClassType cpuBook;

	bool playerFirst;
	bool autoPlay;

	int playerBookCount;
	int cpuBookCount;

	//Private methods
	bool GetPlayerFirst() { return playerFirst; }
	void SetPlayerFirst(void);
	void ShowPlayerHand(void);
	void CpuTurn(void);
	void PlayerTurn(void);
	void DrawIfEmpty(bool forPlayer);
	int FindRankChoice(bool forPlayer, string userInput);
	bool ChoiceInDeck(bool forPlayer, int rankChoice);
	void CheckForBooks(bool forPlayer);
	void PromptAutoPlay(void);
	void CountBooks(void);

public:
	//Constructor
	gameClassType() { SetPlayerFirst(); autoPlay = false; playerBookCount = 0; cpuBookCount = 0; }

	//Public methods
	void StackTheDeck(deckClassType startDeck);
	void Deal(void);
	void Run(void);
	
};
#endif
