//INSTRUCTION
//Look for **. (do control-S)
//Update the comments using the HOW TO COMMENT file, 
//  complete exception handling and 
//  finish ClearIt to make this complete - Yoshii (CS311)
// When done, compile stack.cpp to make sure there are no syntax errors.

//=========================================================
//HW#: HW1P1 stack
//Your name: **
//Complier:  **
//File type: stack implementation file
//=========================================================
#include "stdafx.h"

#include <iostream>
using namespace std;  
#include "vstack.h"

//PURPOSE:  Constructor must initialize top to be -1 to begin with.
stack::stack()
{  } // indicate an empty stack 

//PURPOSE:  Destructor does not have to do anything since this is a static array.
stack::~stack()
{ }// nothing to do }

//PURPOSE:  checks top and returns true if empty, false otherwise.
// ** In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{
	if(el.size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//PURPOSE: checks top and returns true if full, false otherwise.
//** In the comment, make sure you define "full" in terms of top.
bool stack::isFull()
{ 
	return false; // always return false
}

//PURPOSE: calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
//PARAMETER: pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
	if(isFull())
	{
		throw Overflow();
	}
	else
	{
		cout <<"Pushing" <<endl;
		el.push_back(elem); //push back elem into the vector stack
		cout <<"Vector size " << el.size() <<endl;
	}

}
//PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
//PARAMETER: provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
	if (isEmpty())
	{
		throw Underflow();
	}	
	else 
	{

		elem = el[el.size()-1];  //elem is equal to the last of the stack
		el.pop_back(); //remove the last element in the stack or the top

	}
}

// PURPOSE: calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
//PARAMETER: provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ 
	if (isEmpty()) 
	{
		throw Underflow();
	}
	else 
	{ 
		elem = el[el.size()];
	} 
}

//PURPOSE: dislayAll calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
void stack::displayAll()
{  
	int i = 0;
	if (isEmpty()) 
	{
		cout << ".[ empty ]. "<< endl;
	}
	else for(int i = 0; i < el.size(); i++)
	{ 
		cout << el[i ] << endl; 
	}
	cout << "--------------" << endl;
}


//PURPOSE: pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
	int z = 0;

	for(int i = 0; i < el.size(); i++)
	{
		z= el[i];
		z = NULL;
	}
}


