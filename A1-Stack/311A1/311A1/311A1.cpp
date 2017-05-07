//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: James Chhun
//Complier:  MS Visual Studio Ultimate 2012
//File type: client program
//===========================================================


#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
#include "stack.h" //include the stack header file

//Purpose of the program: The purpose of this program is too wriet a stack application to evaluate post-fix expression and output the result to the user

//Algorithm: **
int  _tmain(int argc, _TCHAR* argv[])
{
	stack postfixstack;  // integer stack
	string expression = "";   // user entered expression

	int i = 0;  // character position within expression
	char item;  // one char out of the expression

	int box1 = 0;  // receive things from pop
	int box2 = 0;  // receive things from pop
	int result = 0; //hold result from post-fix operation
	int error = 0; //additional variable to control exiting the while loop

	postfixstack.clearIt(); //clear stack before we begin program

	cout << "type a postfix expression: " ;
	cin >> expression;

	cout <<"You entered  " << expression << endl <<endl; //Display the postfix expressino the user entered


	if(expression.length() >12) //Assuming that the expression is not longer than 12 characters
	{
		cout <<"Expression too long! ( More than 12 characters ) Program now ending." <<endl <<endl; //Inform user expression too long
	}
	else
	{
		while (expression[i] != '\0') 
		{
			try
			{
				item = expression[i];  // current char

				//2.  if it is an operand (number) using the isdigit functino
				if(isdigit(item))
				{
					item = item - '0'; //item is still a character, will subtract 48 to get int value
					postfixstack.push(item); //push into the stack, may receive overflow exception
				}
				//    push it (you might get Overflow exception)

				//3.  else if it is an operator,
				//    pop the two operands (you might get Underflow exception), and
				//	apply the operator to the two operands, and
				//    push the result.
				else if ( (item == '+') || (item == '-') || (item == '*'))
				{
					postfixstack.pop(box1);
					postfixstack.pop(box2);
					//cases for different operators follow:
					if (item == '-') //if item is substraction -
					{
						result = box2-box1;
					}
					else if (item == '+') //if item is addition +
					{
						result = box2+box1;
					}
					else if (item == '*') //if item is multiplication *
					{
						result = box2 * box1;
					}
					// ** also do the + and * cases 
					// ** Finally push the result
					postfixstack.push(result); //push result back into stack
				}

				else
				{
					throw "invalid item";

				}
				//Display invalid item to compiler if the character is neither a digit nor one of the three operators above.
				i++; //increment I to go through the infix expression
			} // this closes try

			// Catch exceptions and report problems and quit the program now. 
			// Error messages describe what is wrong with the expression.
			catch(stack::Overflow()) 
			{

				cout <<"Expression too long, stack is full" <<endl<<endl;
				expression[i] = '\0'; //end while loop
				break; //use break to break out of while loop and go to end of main
			}
			catch(stack::Underflow()) // for too few operands
			{ 

				cout <<"Too few operands, stack is empty" <<endl <<endl;
				expression[i] = '\0';
				break;
			}
			catch(char const* errorcode) // for invalid item
			{ 

				cout <<"You have entered an invalid item for your postfix expression!" <<endl<<endl;
				expression[i] = '\0';
				break;

			}
			// go back to the loop after incrementing i

		}// end of while


		// After the loop successfully completes: 
		// The result will be at the top of the stack. Pop it and show it.

		if(error != -1)
		{
			postfixstack.pop(result);

			// If anything is left on the stack, an incomplete expression was found.
			if(postfixstack.isEmpty())
			{//check if Stack is empty, if it is, program success, inform user the final result of expression.
				cout <<"The final result from the post fix expression is: " << result << endl<<endl;
			}
			else
			{//Stack is not empty, incomplete expressino found
				cout <<"Incomplete expression was found." <<endl <<endl;

				cout <<"Displaying the remaining stack " <<endl; //Test, display the remains of the stack
				postfixstack.displayAll();
				postfixstack.clearIt(); //clear stack after displaying contents to user
			}
		}
	} //end of else

	system("pause"); //pause program, signals end.
	return 0; 
}// end of the program

