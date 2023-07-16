//-------------------------------------------------------------------------------------------------
//File Name: stackClassType.cpp
//Associated file:  stackClassType.h
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
//Header file inclusion
#include "stackClassType.h"

nodePtr stackClassType::GetANode(cardClassType dataCard)
//-------------------------------------------------------------------------------------------------
// GetANode - Returns a nodePtr object from the inputted cardClassType
//-------------------------------------------------------------------------------------------------
{
	//Create new node
	nodePtr ptr = new nodeStructType;

	//Set ptr data
	ptr->data.SetRank(dataCard.GetRank());
	ptr->data.SetSuit(dataCard.GetSuit());

	//Set the node link to NULL
	ptr->link = NULL;

	return ptr;
}

void stackClassType::Push(nodePtr newNode)
//-------------------------------------------------------------------------------------------------
// Push - Pushes a node onto the top of the stack
//-------------------------------------------------------------------------------------------------
{
	//Conditional to check if the stack is empty
	if (IsEmpty())
	{
		//Set the new node to the top
		top = newNode;
	}
	else
	{
		//Set newNode link to top
		newNode->link = top;

		//Set top to newNode
		top = newNode;
	}
}

nodePtr stackClassType::Pop(void)
//-------------------------------------------------------------------------------------------------
// Pop - Pops a node off of the top of the stack and returns it
//-------------------------------------------------------------------------------------------------
{
	//Declare local pointer
	nodePtr ptr;

	//Set ptr to the top of the stack
	ptr = top;

	//Conditional to check if the stack is empty
	if (IsEmpty())
	{
		//Print error message to the screen
		cout << "The stack is empty. There is no card to pop off." << endl;
	}
	else
	{
		//Set top to the next card in the stack
		top = top->link;

		//Set ptr's link to NULL
		ptr->link = NULL;
	}
	return ptr;
}

void stackClassType::DestroyStack(void)
//-------------------------------------------------------------------------------------------------
// DestroyStack - Destroys the stack node by node
//-------------------------------------------------------------------------------------------------
{
	//Create local node variable
	nodePtr aNode;

	//while loop while there are still values in the list
	while (!IsEmpty())
	{
		//Set aNode to start
		aNode = top;

		//Move the start of the list to the next node
		top = top->link;

		//Set aNode link to NULL
		aNode->link = NULL;

		//Free the memory
		delete aNode;
	}
}