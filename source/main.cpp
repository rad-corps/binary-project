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

//string DecimalToBinaryUnsigned(unsigned int decimal_)
//{
//	vector<int> bits;
//	string ret = "";
//	while ( decimal_ > 0 )
//	{
//		bits.push_back(decimal_ % 2);
//		decimal_ /= 2;
//	}
//
//	for ( int i = bits.size() - 1; i >= 0; --i )
//	{
//		ret += to_string(bits[i]);
//	}
//	return ret;
//}
//
//string DecimalToBinarySigned(int decimal_)
//{
//	vector<int> bits;
//	string ret = "";
//	while ( decimal_ > 0 )
//	{
//		bits.push_back(decimal_ % 2);
//		decimal_ /= 2;
//	}
//
//	for ( int i = bits.size() - 1; i >= 0; --i )
//	{
//		ret += to_string(bits[i]);
//	}
//	return "Not Yet Implemented";
//}

int main()
{
	//cout << "Adam Hulbert - Bitwise Operator Program" << endl;
	//cout << "---------------------------------------" << endl;
	//cout << "Enter your selection: " << endl;
	//cout << "1. Perform " << endl;
	//cout << DecimalToBinaryUnsigned(6546544) << endl;

	vector<ExtInt> testData;

	
	//for ( int i = 0; i < 50; ++i )
	//{
	//	testData.push_back(i);
	//	cout << "ValueAsInt             - " << testData[i].ToInt() << endl;
	//	cout << "ToBinaryRepresentation - " << testData[i].ToStringOfBinaryRepresentation() << endl;
	//	
	//	if ( i > 0 )
	//	{
	//		cout << i << " & " << i - 1 << " - " << (testData[i] & testData[i-1]).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " | " << i - 1 << " - " << (testData[i] | testData[i-1]).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " ~ - " << (~testData[i]).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " ^ " << i - 1 << " - " << (testData[i] ^ testData[i-1]).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " << " << 1 << " - " << (testData[i] << ExtInt(1)).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " << " << 2 << " - " << (testData[i] << ExtInt(2)).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " << " << 3 << " - " << (testData[i] << ExtInt(3)).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " >> " << 1 << " - " << (testData[i] >> ExtInt(1)).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " >> " << 2 << " - " << (testData[i] >> ExtInt(2)).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " >> " << 3 << " - " << (testData[i] >> ExtInt(3)).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " + " << i - 1 << " - " << (testData[i] + testData[i-1]).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " + " << i - 1 << " - " << (testData[i] + testData[i-1]).ToInt() << endl;
	//		cout << i << " - " << i - 1 << " - " << (testData[i] - testData[i-1]).ToStringOfBinaryRepresentation() << endl;
	//		cout << i << " - " << i - 1 << " - " << (testData[i] - testData[i-1]).ToInt() << endl;
	//	}
	//}
	
	ExtInt test = -5;
	cout << test.ToStringOfBinaryRepresentation() << endl;


	system("pause");
	return 0;
}