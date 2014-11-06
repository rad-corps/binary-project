////////////////////////////////////////////////////////////
// File: main.cpp
// Author: Adam Hulbert
// Date Created: 19/07/2014
// Brief:	Bitwise Operator Program - Term 3 - 2014 
//		
//	You are to create a program that can convert between 
//	decimal and binary numbers as well as perform operations 
//	on binary numbers.
//	The user must be able to enter a number in either binary or 
//	decimal. Your program must allow them to convert from 
//	decimal to binary AND from binary to decimal. The program 
//	must have a signed and unsigned mode (use two’s 
//	complement in the unsigned mode).
//	You must be able to perform the following operations on 
//	binary and decimal numbers: addition, subtraction, bitwise 
//	AND, bitwise OR, bitwise NOT, bitwise XOR, left bit-shift, 
//	right bit-shift.	
////////////////////////////////////////////////////////////
 
#include <string>
#include <iostream>
#include <vector>
#include "../include/ExtendedInt.h"

using namespace std;

enum EXTINT_OPERATOR
{
	ADD			=1,
	SUBTRACT	=2,
	AND			=3,
	OR			=4,
	XOR			=5,
	NOT			=6,
	LEFT_SHIFT	=7,
	RIGHT_SHIFT	=8,
};

EXTINT_OPERATOR
HandleOperatorSelection()
{
	int selection;
	//EXTINT_OPERATOR selection;
	cout << endl << "Which operation would you like to perform?: " << endl;
	cout << "1. Add" << endl;
	cout << "2. Subtract" << endl;
	cout << "3. AND" << endl;
	cout << "4. OR" << endl;
	cout << "5. XOR" << endl;
	cout << "6. NOT" << endl;
	cout << "7. Left Shift" << endl;
	cout << "8. Right Shift" << endl;

	cin >> selection;

	if ( selection >= EXTINT_OPERATOR::ADD && selection <= RIGHT_SHIFT )
	{
		return (EXTINT_OPERATOR)selection;
	}
	else
	{
		cout << endl << "Sorry the program will only accept numbers 1 to 8" << endl;
		system("pause");
		return HandleOperatorSelection();
	}
}

ExtInt
HandleBinaryUserEntry(bool signed_)
{
	string binary = "";
	cout << endl << "Please enter a binary number in the following format 10101010" << endl;
	cin >> binary;
	cout << endl << "Attempting to parse: " << binary << endl;
			
	ExtInt binInt;
	try 
	{
		binInt = ExtInt(binary.c_str(), signed_);
		cout << "The integer representation of " << binary << " is " << binInt.ToInt() << endl;
	}
	catch ( InvalidInputException e_ ) 
	{
		cout << "Sorry, the binary conversion program could not parse your input '" << binary << "'" << endl << 
			"Please make sure you only use 1 and 0 characters " << endl <<
			"and that the entry is exactly 8 characters long." << endl;	
		system("pause");
		return HandleBinaryUserEntry(signed_);
	}
	return binInt;
}

ExtInt
HandleIntUserEntry(bool signed_)
{
	string strNum = "";
	cout << endl << "Please enter an integer number: " << endl;
	cin >> strNum;
	int result;
			
	try
	{
		result = std::stoi(strNum);
	}
	catch ( std::invalid_argument e_ )
	{
		cout << endl << "Please enter a valid integer (no letters, spaces, or special characters" << endl;
		return HandleIntUserEntry(signed_);
	}
	ExtInt binInt;
	binInt = ExtInt(result, signed_);
	cout << endl << "The binary representation of " << result << " is " << binInt.ToStringOfBinaryRepresentation() << endl;
	return binInt;
}

void ShowBothNumbersAndResult(ExtInt num1_, ExtInt num2_, ExtInt res_)
{
	cout << endl << "bin num1: " << num1_.ToStringOfBinaryRepresentation() << "\tint num1: " << num1_.ToInt() << endl;
	cout << "bin num2: " << num2_.ToStringOfBinaryRepresentation() << "\tint num2: " << num2_.ToInt() << endl;
	cout << "bin res:  " << res_.ToStringOfBinaryRepresentation() << "\tint res:  " << res_.ToInt() << endl;
	system("pause");
}

void ShowResult(ExtInt result_)
{
	cout << endl << "bin res:  " << result_.ToStringOfBinaryRepresentation() << "\tint res:  " << result_.ToInt() << endl;
	system("pause");
}


int main()
{
	int selection;
	bool signedMode = true;
	do
	{
		//main user interface
		system("cls");
		if ( signedMode )
		{
			cout << "The binary conversion program is currently in signed mode." << endl;
			cout << "1. Swap to unsigned mode" << endl;
		}
		else
		{
			cout << "The binary conversion program is currently in unsigned mode." << endl;
			cout << "1. Swap to signed mode" << endl;
		}		
		cout << "2. Enter a binary number (1 byte, or 8 bits)" << endl;
		cout << "3. Enter an integer number" << endl;
		
		//The user entered Extended Int objects will be stored in these 
		ExtInt int1(signedMode);
		ExtInt int2(signedMode);
		
		//The result of the user entered variables will be stored here
		ExtInt res(signedMode);

		//The user chosen operator
		EXTINT_OPERATOR myOp;
		
		//user makes a program selection
		cin >> selection;

		//swap modes
		if ( selection == 1 )
		{
			signedMode = !signedMode;
		}
		//user to enter binary values
		else if ( selection == 2 ) 
		{
			int1 = HandleBinaryUserEntry(signedMode);
			myOp = HandleOperatorSelection();	
			
			//we need a second value if we did not choose NOT
			if ( myOp != EXTINT_OPERATOR::NOT )
				int2 = HandleBinaryUserEntry(signedMode);
		}
		//user to enter int values
		else if ( selection == 3 ) //integer entry
		{
			int1 = HandleIntUserEntry(signedMode);
			myOp = HandleOperatorSelection();
			
			//we need a second value if we did not choose NOT
			if ( myOp != EXTINT_OPERATOR::NOT )
				int2 = HandleIntUserEntry(signedMode);
		}

		//perform the calculation
		if ( selection == 2 || selection == 3 )
		{
			if ( myOp == EXTINT_OPERATOR::ADD )
			{
				res = int1 + int2;
			}
			if ( myOp == EXTINT_OPERATOR::AND )
			{
				res = int1 & int2;
			}
			if ( myOp == EXTINT_OPERATOR::LEFT_SHIFT )
			{
				res = int1 << int2;
			}
			if ( myOp == EXTINT_OPERATOR::RIGHT_SHIFT )
			{
				res = int1 >> int2;
			}
			if ( myOp == EXTINT_OPERATOR::SUBTRACT )
			{
				res = int1 - int2;
			}
			if ( myOp == EXTINT_OPERATOR::NOT )
			{
				res = ~int1;
			}
			if ( myOp == EXTINT_OPERATOR::OR )
			{
				res = int1 | int2;
			}
			if ( myOp == EXTINT_OPERATOR::XOR )
			{
				res = int1 ^ int2;
			}

			//show the results
			if ( myOp != EXTINT_OPERATOR::NOT )
				ShowBothNumbersAndResult(int1, int2, res);
			else
				ShowResult(res);

		}

	}while ( selection != 0 );

	return 0;
}