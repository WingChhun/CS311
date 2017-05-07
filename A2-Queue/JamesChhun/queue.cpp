//INSTRUCTION
//Look for **
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

// =====================================================
// HW#: HW1P1 queue
// Your name: James Chhun
// Compiler:  MS Visual Studio 2012 Ultimate
// File type: queue header file 
//=====================================================


#include "stdafx.h"
#include <iostream>
using namespace std;
#include "queue.h"  

// constructor 
queue::queue()
{
	//initialize front to 0 and rear to -1
	front = 0;
	rear  = -1;
	count = 0; // initialize count to 0
}

//destructor 
queue::~queue()
{
	//do nothing
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
	if(count ==0 ) //if front is still 0 and rear is still -1, no changes to size have been done, empty
	{
		return true;
	}
	else
	{
		return false;
	}
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
	if(count == MAX_SIZE)  //If front has reached max size
	{
		return true;
	}
	else
	{
		return false;
	}
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
	if(isFull())
	{
		throw Overflow(); 
	}
	else
	{
		if(count==0)
		{ //No previous element in queue

			el[front] = newElem;
			rear = 0;
			el[rear] = el[front];

		}
		else
		{

			rear = (rear +1) % MAX_SIZE; //rear is the remainder of rear after being incremented and then divided by the max size
			el[rear] = newElem;
		}
		count++; //increment count size

	}
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removedElem)
{
	if(isEmpty())
	{
		throw Underflow();
	}
	else
	{


		removedElem = el[front];
		front = (front+1)%MAX_SIZE; //change position of front
		count--; //decrement count
	}
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
	if(isEmpty())
	{
		throw Underflow();	
	}
	else
	{
		theElem = el[front]; 
		//give back front of the queue without removing
	
	}

}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
	return count; //return count to caller, indicates the size of the queue
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
	if (isEmpty())
	{
		cout << "[ empty ]." << endl;
	}
	else
	{
		cout <<"----------------" <<endl;
		for (int i = front; i <=count; i++) //Dis0lay Queue from Top to bottom beginning at the front and ending at the rear
		{ 
			cout << el[i] << endl; 
		}
		cout << "--------------" << endl <<endl;
	}
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
	if(isEmpty())
	{
		throw Underflow();
	}
	else if(count ==1 )
	{
		//Do nothing, queue has just 1 element
	}
	else
	{
		string expression = el[front];

		remove(el[front]);
		add(expression); 
	}
}




