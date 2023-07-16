//-------------------------------------------------------------------------------------------------
//File Name: cardClassType.h
//Associated file:  cardClassType.cpp
//Members:          
//  2 Constructors  : Default and with integer arguments for rank and suit
//  Standard Methods:
//   Get  -  GetRank, GetSuit
//   Set   - SetRank, SetSuit
//   Print - none
// Other Methods: Operator overloads for <,>,== and <<
//   
//-------------------------------------------------------------------------------------------------
#ifndef cardClassType_h
#define cardClassType_h

//Header file inclusions
#include "courseRequired.h"

//Enumerated type for suits
enum suits { heart = 3, diamond, club, spade };

class cardClassType
{
private:
	//Private member variables
	int rank;
	int suit;

public:
	//Constructor
	cardClassType(void) { rank = 0; suit = 0; }
	cardClassType(int startRank, int startSuit) { rank = startRank; suit = startSuit; }

	//Public methods
	int GetRank(void) { return rank; }
	int GetSuit(void) { return suit; }
	void SetRank(int newRank) { rank = newRank; }
	void SetSuit(int newSuit) { suit = newSuit; }


	//Operator overloads
	bool operator==(cardClassType card) { return this->rank == card.rank; }
	bool operator<(cardClassType card) { return this->rank < card.rank; }
	bool operator>(cardClassType card) { return this->rank > card.rank; }
	

};

 //<< overload
ostream& operator<<(ostream& fout, cardClassType& card);
#endif
