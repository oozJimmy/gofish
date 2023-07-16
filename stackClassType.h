//-------------------------------------------------------------------------------------------------
//File Name: stackClassType.h
//Associated file:  stackClassType.cpp
//Members:          
//  1 Constructor  : Calls create a stack
//  Standard Methods:
//   Get  -  GetTop
//   Set   - SetRank, SetSuit
//   Print - none
// IsEmpty, GetANode, Push, Pop, CreateAStack, DestroyStack
//   
// Destructor: Calls DestroyStack
//-------------------------------------------------------------------------------------------------
#ifndef stackClassType_h
#define stackClasstype_h

//Header file inclusion
#include "cardClassType.h"

//Create node
struct nodeStructType
{
	cardClassType data;
	nodeStructType* link;
};

//Node pointer type definition
typedef nodeStructType* nodePtr;

class stackClassType
{
private:
	//Private member data
	nodePtr top;

public:
	//Constructor
	stackClassType() { CreateAStack(); }

	//Public methods
	bool IsEmpty(void) { return top == NULL; }
	nodePtr GetANode(cardClassType dataCard);
	nodePtr GetTop(void) { return top; }
	void Push(nodePtr newNode);
	nodePtr Pop(void);
	void CreateAStack(void) { top = NULL; }
	void DestroyStack(void);

	//Destructor
	~stackClassType(void) { DestroyStack(); }
};
#endif
