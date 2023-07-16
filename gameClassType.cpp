//-------------------------------------------------------------------------------------------------
//File Name: gameClassType.cpp
//Associated file:  gameClassType.h
//Members:          
//  1 Constructor  : Calls SetPlayerFirst, sets autoPlay to false and book counts to 0
//  Standard Methods:
//   Get  -  GetPlayerFirst
//   Set   - SetPlayerFirst
//   Print - 
// Other Methods: StackTheDeck, Deal, ShowPlayerHand, CpuTurn, PlayerTurn, DrawIfEmpty, 
// FindRankChoice, ChoiceInDeck, CheckForBooks Run, PromptAutoPlay,CountBooks
//-------------------------------------------------------------------------------------------------
//Header file inclusion
#include "gameClassType.h"


void gameClassType::SetPlayerFirst(void)
//-------------------------------------------------------------------------------------------------
// SetPlayerFirst - Randomly selects a player to go first
//-------------------------------------------------------------------------------------------------
{
	//Conditional to find out who goes first
	if (rand() % 2 == 1)
	{
		//Set playerFirst to true
		playerFirst = true;
	}
	else
	{
		//Set playerFirst to false
		playerFirst = false;
	}
}

void gameClassType::StackTheDeck(deckClassType startDeck)
//-------------------------------------------------------------------------------------------------
// StackTheDeck - Send the cards from a deck class to a central stack
//-------------------------------------------------------------------------------------------------
{
	//Loop to run to push each card in the deck to the stack
	for (int counter = 0; counter < startDeck.GetDeckTag(); counter++)
	{
		//Create a node from the card in the deck and push to the stack
		fishStack.Push(fishStack.GetANode(startDeck.GetCardInPosition(counter)));
	}
}

void gameClassType::Deal(void)
//-------------------------------------------------------------------------------------------------
// Deal - Deal 7 Cards from the center stack to the player and computers hands
//-------------------------------------------------------------------------------------------------
{
	//Create local pointer
	nodePtr cardPtr;

	//Loop to run for each pair of cards dealt
	for (int counter = 0; counter < 7; counter++)
	{
		//Deal card to player
		cardPtr = fishStack.Pop();
		playerHand.SetCardInPosition(playerHand.GetDeckTag(), cardPtr->data);
		playerHand.SetDeckTag(playerHand.GetDeckTag() + 1);

		//Deal card to computer
		cardPtr = fishStack.Pop();
		cpuHand.SetCardInPosition(cpuHand.GetDeckTag(), cardPtr->data);
		cpuHand.SetDeckTag(cpuHand.GetDeckTag() + 1);
	}

	delete cardPtr;
}

void gameClassType::ShowPlayerHand(void)
//-------------------------------------------------------------------------------------------------
// ShowPlayerHand - Prints the players hand with a heading 
//-------------------------------------------------------------------------------------------------
{
	//Print a divider
	PrintDivider(static_cast<ofstream&>(cout), '*', WIDTH);
	PrintCenteredMessage(static_cast<ofstream&>(cout), "Your Hand", WIDTH);
	PrintDivider(static_cast<ofstream&>(cout), '*', WIDTH);

	//Print the players deck
	playerHand.PrintTheDeck();

	//Print a divider
	PrintDivider(static_cast<ofstream&>(cout), '*', WIDTH);
}

void gameClassType::CpuTurn()
//-------------------------------------------------------------------------------------------------
// CpuTurn - The CPU takes its turn, choosing a rank, asking the user and repeating
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	string userInput;
	int rankChoice;
	bool cardFound;
	cardClassType currentCard;
	nodePtr fishedNode;

	//Do while loop to run once and loop if a card match in the players hand is found
	do{
		//Choose card to ask for RANDOM for now
		currentCard = cpuHand.GetCardInPosition(rand() % cpuHand.GetDeckTag());

		//Set rankChoice
		rankChoice = currentCard.GetRank();

		//Reset cardFound to false for the new search
		cardFound = false;

		//Print message to the screen 
		cout << "The CPU asks you for a(n) " << currentCard << endl;

		//Loop to run for each card in the players deck
		for (int counter = 0; counter < playerHand.GetDeckTag(); counter++)
		{
			//Set currentCard to players hand at counter
			currentCard = playerHand.GetCardInPosition(counter);

			//Conditional to check if the rank matches players card
			if (rankChoice == currentCard.GetRank())
			{
				//Print message
				cout << "You give the CPU your" << currentCard << "." << endl;

				//Add card to the CPUs hand
				cpuHand.AddCardToDeck(currentCard);

				//Remove the card from the players hand
				playerHand.RemoveCardFromDeck(counter);

				//Set cardFound to true
				cardFound = true;

				//Sort the players hand
				playerHand.Sort();
			}
		}

		//Conditional to fish if the rank wasn't found in the players hand 
		if (!cardFound)
		{
			//Print a message
			cout << "The card was not found, Go Fish!" << endl;

			//Conditional to check if the center stack is empty
			if (fishStack.IsEmpty())
			{
				//Print empty stack message
				cout << "The fish deck is empty. There are no more cards to draw" << endl;
			}
			else
			{
				//Pop a card from the center stack
				fishedNode = fishStack.Pop();

				//Add the popped card to the CPUs hand
				cpuHand.AddCardToDeck(fishedNode->data);

				//Conditional to check if the fished card is the same as the rankChoice
				if (fishedNode->data.GetRank() == rankChoice)
				{
					//Print message
					cout << "The fished card was the " << fishedNode->data
						<< ".\nComputer goes again." << endl;

					//Set cardFound to true
					cardFound = true;
				}
			}
		}

	} while (cardFound);
}

void gameClassType::PlayerTurn()
//-------------------------------------------------------------------------------------------------
// PlayerTurn - The player takes its turn, choosing a rank, asking the user and repeating
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	int rankChoice;
	bool cardFound;
	string userInput;
	cardClassType currentCard;
	nodePtr fishedNode;

	//Do while loop to run once and loop if a card match in the players hand is found
	do {

		//Conditional to check autoPlay
		if (!autoPlay)
		{
			//Choose card to ask for  
			cout << "What card do you want to ask the computer for? ";
			cin >> userInput;
			cout << endl;

			//Call method to get a rank from the user input
			rankChoice = FindRankChoice(true, userInput);

			//While loop to run until a valid rank has been taken
			while (!ChoiceInDeck(true, rankChoice))
			{
				//Print message stating card is not in your hand
				cout << "That card isn't in your hand. Please pick a card in your hand." << endl;
				cout << "What card do you want to ask the computer for? ";
				cin >> userInput;
				cout << endl;

				//Call method to get a valid rank from the user input
				rankChoice = FindRankChoice(true, userInput);
			}
		}
		else
		{
			//Set userInput to a blank value
			userInput = ' ';

			//Choose card to ask for RANDOM for now
			currentCard = playerHand.GetCardInPosition(rand() % playerHand.GetDeckTag());

			//Set rankChoice
			rankChoice = currentCard.GetRank();

			//Print message to the screen 
			cout << "You ask the CPU for any cards with the rank of the " << currentCard << endl;
		}

		//Set cardFound to false
		cardFound = false;

		//Loop to run for each card in the computers deck
		for (int counter = 0; counter < cpuHand.GetDeckTag(); counter++)
		{
			//Set currentCard to players hand at counter
			currentCard = cpuHand.GetCardInPosition(counter);

			//Conditional to check if the rank matches CPUs card
			if (rankChoice == currentCard.GetRank())
			{
				//Print message
				cout << "The CPU gives you it's " << currentCard << "." << endl;

				//Add card to the players hand
				playerHand.AddCardToDeck(currentCard);

				//Remove the card from the CPUs hand
				cpuHand.RemoveCardFromDeck(counter);

				//Set cardFound to true
				cardFound = true;
			}
		}

		//Condition to check if the rank was found in the CPUs hand
		if (!cardFound)
		{
			//Print a message
			cout << "The card was not found in the computers hand, Go Fish!" << endl;

			//Conditional to check if the center stack is empty
			if(fishStack.IsEmpty())
			{
				//Print empty stack message
				cout << "The fish deck is empty. There are no more cards to draw" << endl;
			}
			else
			{
				//Pop a card from the center stack
				fishedNode = fishStack.Pop();

				//Add the popped card to the players hand
				playerHand.AddCardToDeck(fishedNode->data);

				//Conditional to check if the fished card is the same as the rankChoice
				if (fishedNode->data.GetRank() == rankChoice)
				{
					//Print message
					cout << "The fished card was the " << fishedNode->data
						<< ".\nYou go again." << endl;

					//Set cardFound to true
					cardFound = true;
				}
				else
				{
					//Print message with the fished card
					cout << "You picked up the " << fishedNode->data << endl;
				}
			}
		}
	} while (cardFound);
}

void gameClassType::DrawIfEmpty(bool forPlayer)
//-------------------------------------------------------------------------------------------------
// DrawIfEmpty - Draws 7 cards to the specified players hand
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	nodePtr ptr;

	//Conditional to check forPlayer
	if (forPlayer)
	{
		//Conditional for the players hand deckTag
		if (playerHand.GetDeckTag() == 0)
		{
			//Print message 
			cout << "You're out of cards, you have to draw from the middle." << endl;

			//Draw 7 cards from the middle stack
			for (int counter = 0; counter < 7; counter++)
			{
				//Check if the middle stack is empty
				if (fishStack.IsEmpty())
				{
					//Print message 
					cout << "The center deck is empty. No cards to draw." << endl;
					break;
				}
				//Pop the card off the middle stack
				ptr = fishStack.Pop();

				//Add the card to the players deck
				playerHand.AddCardToDeck(ptr->data);
			}
		}
	}
	else
	{
		//Conditional for the CPU hand deckTag
		if (cpuHand.GetDeckTag() == 0)
		{
			//Print message
			cout << "Computer out of cards, drawing..." << endl;

			//Draw 7 cards from the middle stack
			for (int counter = 0; counter < 7; counter++)
			{
				//Check if the middle stack is empty
				if (fishStack.IsEmpty())
					break;

				//Pop the card off the middle stack
				ptr = fishStack.Pop();

				//Add the card to the players deck
				cpuHand.AddCardToDeck(ptr->data);
			}
		}
	}
}

int gameClassType::FindRankChoice(bool forPlayer, string userInput)
//-------------------------------------------------------------------------------------------------
// FindRankChoice - Takes the user input and finds a card rank choice from it
//-------------------------------------------------------------------------------------------------
{
	//Local variables
	int rankChoice = 0;

	//Conditional to check if the userInput is a valid card rank
	if (userInput == "J" || userInput == "Q" || userInput == "K" || userInput == "A"
		|| userInput == "2" || userInput == "3" || userInput == "4" || userInput == "5"
		|| userInput == "6" || userInput == "7" || userInput == "8" || userInput == "9"
		|| userInput == "10")
	{
		//Convert the string input to a rank integer with an if chain statement
		if (userInput == "J")
			rankChoice = 11;
		else if (userInput == "Q")
			rankChoice = 12;
		else if (userInput == "K")
			rankChoice = 13;
		else if (userInput == "A")
			rankChoice = 1;
		else
			rankChoice = stoi(userInput);
	}
	else
	{
		//Prompt user for new input
		cout << "Error: Please enter a number 2-10 or J, Q, K or A. \nEnter a new choice: ";
		cin >> userInput;
		cout << endl;

		//Call FindRankChoice again with the new input
		rankChoice = FindRankChoice(forPlayer, userInput);
	}

	return rankChoice;
}

bool gameClassType::ChoiceInDeck(bool forPlayer, int rankChoice)
//-------------------------------------------------------------------------------------------------
// ChoiceInDeck - Checks to see if the selected players choice is in their hand
//-------------------------------------------------------------------------------------------------
{
	//Local variable 
	bool inDeck = false;

	//Create hand deckClassType object based on who's turn it is
	deckClassType hand;
	forPlayer ? hand = playerHand : hand = cpuHand;

	//Loop to run for each card in the hand to check if the rankChoice is in the deck
	for (int counter = 0; counter < hand.GetDeckTag(); counter++)
	{
		//Conditional to check if the rank is in the players hand
		if (rankChoice == hand.GetCardInPosition(counter).GetRank())
		{
			//Set inDeck to true
			inDeck = true;
		}
	}

	return inDeck;
}

void gameClassType::CheckForBooks(bool forPlayer)
//-------------------------------------------------------------------------------------------------
// CheckForBooks - Checks to see if the selected player has any books and send to the book stack
//-------------------------------------------------------------------------------------------------
{
	//Create local variables
	int matchedCardIndexes[4];
	int numMatches = 0;
	int rankToMatch;
	cardClassType printCard;

	//Conditional to check forPlayer
	if (forPlayer)
	{
		//Sort the hand
		playerHand.Sort();

		//For loop to run through the hand
		for (int counter = 0; counter < playerHand.GetDeckTag(); counter++)
		{
			//Set matched cards to 0
			numMatches = 0;

			//Get the rank to match from the current card 
			rankToMatch = playerHand.GetCardInPosition(counter).GetRank();

			//For loop to run through the hand
			for (int index = 0; index < playerHand.GetDeckTag(); index++)
			{
				//Check if the card at index matches ranks with the rankToMatch
				if (playerHand.GetCardInPosition(index).GetRank() == rankToMatch)
				{
					//Add the index of the matching card to the index array
					matchedCardIndexes[numMatches] = index;

					//Increment number of matches
					numMatches++;
				}
			}

			//Check for a book of matched cards
			if (numMatches == 4)
			{
				//Set print card
				printCard = playerHand.GetCardInPosition(matchedCardIndexes[0]);

				//Print message
				cout << "You have gotten a book of cards with rank of: "
					<< printCard << endl;

				//Loop to access all 4 indexes of the matched cards
				for (int match = 0; match < 4; match++)
				{
					//Push the card onto the players book stack
					playerBook.Push(playerBook.GetANode(
						playerHand.GetCardInPosition(matchedCardIndexes[match])));

					//Remove the card from the deck
					playerHand.RemoveCardFromDeck(matchedCardIndexes[match]);
				}
			}
		}
	}
	else
	{
		//Sort the hand
		cpuHand.Sort();

		//For loop to run through the hand
		for (int counter = 0; counter < cpuHand.GetDeckTag(); counter++)
		{
			//Set matched cards to 0
			numMatches = 0;

			//Get the rank to match from the current card 
			rankToMatch = cpuHand.GetCardInPosition(counter).GetRank();

			//For loop to run through the hand
			for (int index = 0; index < cpuHand.GetDeckTag(); index++)
			{
				//Check if the card at index matches ranks with the rankToMatch
				if (cpuHand.GetCardInPosition(index).GetRank() == rankToMatch)
				{
					//Add the index of the matching card to the index array
					matchedCardIndexes[numMatches] = index;

					//Increment number of matches
					numMatches++;
				}
			}

			//Check for a book of matched cards
			if (numMatches == 4)
			{
				//Set print card
				printCard = cpuHand.GetCardInPosition(matchedCardIndexes[0]);

				//Print message
				cout << "Computer got a book of cards with rank of: " << printCard << endl;

				//Loop to access all 4 indexes of the matched cards
				for (int match = 0; match < 4; match++)
				{
					//Push the card onto the players book stack
					cpuBook.Push(cpuBook.GetANode(
						cpuHand.GetCardInPosition(matchedCardIndexes[match])));

					//Remove the card from the deck
					cpuHand.RemoveCardFromDeck(matchedCardIndexes[match]);
				}
			}
		}
	}
}

void gameClassType::Run(void)
//-------------------------------------------------------------------------------------------------
// Run - Calls the other game class methods and runs the game of Go Fish
//-------------------------------------------------------------------------------------------------
{
	//Declare local variable
	bool turnKeeper;

	//Set turnKeeper equal to playerFirst
	turnKeeper = playerFirst;

	cout << "Welcome to Go Fish! The cards have been dealt, here is your hand:" << endl;

	ShowPlayerHand();

	//Turn keeper true runs for the players turn, false for the CPU
	//while loop to run until one of the players decks is empty
	while (playerHand.GetDeckTag() != 0 && cpuHand.GetDeckTag() != 0)
	{
		
		//Conditional to check turnKeeper
		if (turnKeeper)
		{
			//Conditional to check if autoPlay is on
			if (!autoPlay)
			{
				//Prompt for autoPlay
				PromptAutoPlay();
			}

			//Show the players hand
			ShowPlayerHand();

			//Player takes their turn
			PlayerTurn();

			//Sort the players hand
			playerHand.Sort();
		}
		else
		{
			//CPU takes its turn
			CpuTurn();

			//Sort the CPUs hand
			cpuHand.Sort();
		}

		//Draw cards if the other players hand is now empty
		DrawIfEmpty(!turnKeeper);

		//Check hand for books
		CheckForBooks(turnKeeper);

		//Switch the value of turnKeeper to change turns
		turnKeeper = !turnKeeper;
	}

	//All moves have been made now we count the players books and declare a winner
	CountBooks();

	//Conditional to check the number of books for each player
	if (playerBookCount > cpuBookCount)
	{
		//Print win message
		cout << "You win. :)" << endl;
		cout << "User obtained " << playerBookCount << " books." << endl;
		cout << " Computer obtained: " << cpuBookCount << " books." << endl;
	}
	else
	{
		//Print loss message
		cout << "The user loses." << endl;
		cout << "User obtained " << playerBookCount << " books." << endl;
		cout << " Computer obtained: " << cpuBookCount << " books." << endl;
	}

}

void gameClassType::PromptAutoPlay(void)
//-------------------------------------------------------------------------------------------------
// PromptAutoPlay - Asks the player if they want to turn on AutoPlay and get their response
//-------------------------------------------------------------------------------------------------
{	
	//Create local variable
	char userResponse;
	bool validResponse = false;

	//Prompt for autoplay with dividers
	PrintDivider(static_cast<ofstream&>(cout), '.', WIDTH);
	cout << "AutoPlay is off. When turned on it will run through the whole game without" <<
		endl << "prompting you for selections. Would you like to turn it on?(Input (Y) or (N)"
		<< endl;
	PrintDivider(static_cast<ofstream&>(cout), '-', WIDTH);

	//Get the users response
	cin >> userResponse;

	//Make the userResponse character uppercase
	userResponse = toupper(userResponse);

	//While loop to run until a valid response has been given
	while (!validResponse)
	{
		//Check userResponse
		if (userResponse == 'Y')
		{
			//Turn autoPlay to true
			autoPlay = true;
			
			//Set validResponse to true
			validResponse = true;
		}
		else if (userResponse == 'N')
		{
			//Keep autoPlay false
			autoPlay = false;

			//Set validResponse to true
			validResponse = true;
		}
		else
		{
			//Print message stating bad input
			cout << "Error: Please input a 'Y' or 'N'." << endl;
			cin >> userResponse;

			//Make the userResponse character uppercase
			userResponse = toupper(userResponse);
		}
	}

	//Print a divider
	PrintDivider(static_cast<ofstream&>(cout), '\'', WIDTH);
}

void gameClassType::CountBooks()
//-------------------------------------------------------------------------------------------------
// CountBooks - Counts the users and CPUs books at the end of the game 
//-------------------------------------------------------------------------------------------------
{
	//Declare local pointer variable
	nodePtr ptr;
	int cardCount = 0;

	//Loop to run until the players book stack is empty
	while (!playerBook.IsEmpty())
	{
		//Pop a card off of the players book stack
		ptr = playerBook.Pop();

		//Free the memory of the pointer
		delete ptr;

		//Increment cardCount
		cardCount++;

		//Conditional to check cardCount
		if (cardCount == 4)
		{
			//Increment players number of books
			playerBookCount++;

			//Set cardCount to 1
			cardCount = 0;
		}
	}

	//Loop to run until the CPUs book stack is empty
	while (!cpuBook.IsEmpty())
	{
		//Pop a card off of the CPUs book stack
		ptr = cpuBook.Pop();

		//Free the memory of the pointer
		delete ptr;

		//Increment cardCount
		cardCount++;

		//Conditional to check cardCount
		if (cardCount == 4)
		{
			//Increment CPUs number of books
			cpuBookCount++;

			//Set cardCount to 1
			cardCount = 0;
		}
	}
}