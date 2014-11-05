//File:			BitWiseOperators.h
//Author:		Jeremy Eade
//Brief:		BitWiseOperators Header file
//				Manual implementation of bitwise functions

#pragma once
#ifndef BITWISEOPERATORS_H
#define BITWISEOPERATORS_H

#include <string>
#include <iostream>

using namespace std;

class BitWiseOperators
{
public:
	BitWiseOperators();
	~BitWiseOperators();

	string leftShift(string array_, int numToShift_);
	string rightShift(string array_, int numToShift_);
	string AND(string array1_, string array2_);
	string OR(string array1_, string array2_);
	string XOR(string array1_, string array2_);
	string NOT(string array1_);

	//quick and dirty to pad out array to 8 bits if user enters less than 8
	//Refactor at a later daye to make sure bitwise operators could be used with any input (not just strings)
	string padArray(string string_);

private:
};

#endif	//	BITWISEOPERATORS_H