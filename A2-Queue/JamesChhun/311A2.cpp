
//INSTRUCTION
//Look for ** to complete this program 
//The string output should match my hw1queueDemo.out 
//except for the trace messages

//=========================================================
//HW#: HW1P1 queue
//Your name: James Chhun
//Complier:  MS Visual Studio Ultiamte 2012
//File type: client program
//===========================================================


#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;
#include "queue.h"

//Purpose of the program: **
//Algorithm: **
int _tmain(int argc, _TCHAR* argv[])
{
	queue postQueue;
	string expression = "";
	string removedElem = "";
	string frontElem = "";

	int x = 0; //variable to control while loop, use for testing delete later
	int y = 0; //variable to help control loop
	//Add A B and C to the queue

	postQueue.add("A");
	postQueue.add("B");
	postQueue.add("C");



	while(expression != "CCC") //loop until string expression displays 'CCC'
	{
		try
		{


			postQueue.remove(removedElem); //call remove functino, passed removedElem holder

			expression = removedElem;


			//******Single Letter Cases******//
			if(removedElem == "A")
			{
				postQueue.add("AA");
				postQueue.add("AB");
				postQueue.add("AC");
			}
			else if(removedElem == "B")
			{
				postQueue.add("BA");
				postQueue.add("BB");
				postQueue.add("BC");
			}
			else if(removedElem == "C")
			{
				postQueue.add("CA");
				postQueue.add("CB");
				postQueue.add("CC");
			}

			//*******CX CASES**************//

			else if(removedElem == "CA")
			{
				postQueue.add("AAA");
				postQueue.add("AAB");
				postQueue.add("AAC");

			}
			else if(removedElem == "CB")
			{
				postQueue.add("ABA");
				postQueue.add("ABB");
				postQueue.add("ABC");
			}
			else if(removedElem == "CC")
			{
				postQueue.add("ACA");
				postQueue.add("ACB");
				postQueue.add("ACC");
			}
			//*********BXX CASES**********/
			else if(removedElem == "AAC")
			{
				postQueue.add("BAA");
				postQueue.add("BAB");
				postQueue.add("BAC");
			}
			else if(removedElem == "ABC")
			{
				postQueue.add("BBA");
				postQueue.add("BBB");
				postQueue.add("BBC");
			}

			else if(removedElem == "ACC")
			{
				postQueue.add("BCA");
				postQueue.add("BCB");
				postQueue.add("BCC");
			}

			//************CXX CASES************//
			else if(removedElem == "BAC")
			{
				postQueue.add("CAA");
				postQueue.add("CAB");
				postQueue.add("CAC");
			}
			else if(removedElem == "BBC")
			{
				postQueue.add("CBA");
				postQueue.add("CBB");
				postQueue.add("CBC");
			}
			else if(removedElem == "BCC")
			{
				postQueue.add("CCA");
				postQueue.add("CCB");
				postQueue.add("CCC");
			}


			cout <<endl<<"Expression: "<<  expression<<endl; //display



			x++; //remove later, used for controlling displayed contents
		}
		catch(queue::Underflow())
		{
			cerr << "Error: You have caused the queue to underflow." << endl;
		}

		catch(queue::Overflow())
		{
			cerr << "Error: You have caused the queue to overflow." << endl;
		}

	}
	postQueue.displayAll(); //display new conte4nts of queue
	system("pause"); //pause program before ending
	return 0;
}




