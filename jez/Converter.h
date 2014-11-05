//File:			Converter.h
//Author:		Jeremy Eade
//Brief:		Converter Header file
//				Handles all binary / decimal conversions
//				Addition & Subtraction of only unsigned binary / decimals required (Confirmed with JK 22/10/2014)

#pragma once
#ifndef CONVERTER_H
#define CONVERTER_H

#include <iostream>
#include "BitWiseOperators.h"
#include <deque>

using namespace std;

class Converter
{
public:
	Converter();
	~Converter();

	//Takes in a decimal number via validated string from user & converts to unsigned binary.
	string DecToBinUnsigned(string decimal);

	//Takes in a decimal number via validated string from user & converts to signed binary.
	string DecToBinSigned(string decimal_);

	//Takes in a binary formatted number via validated string from user & converts to unsigned decimal.
	int BinToDecUnsigned(string binary_);

	//Takes in a binary formatted number via validated string from user & converts to signed decimal.
	int BinToDecSigned(string binary_);

	//Receives 2 binary validated unsigned strings & performs addition within scope 0-255
	string addBinary(string binary1_, string binary2_);

	//Receives 2 binary validated unsigned strings & performs subtraction within scope 0-255
	string subBinary(string binary1_, string binary2_);

	//Receives 2 decimal validated unsigned strings & performs addition within scope 0-255
	int addDecimal(string a_, string b_);

	//Receives 2 decimal validated unsigned strings & performs subtraction within scope 0-255
	int subDecimal(string a_, string b_);

	//Predefined bitwise ops
	//unsigned int myAdd(unsigned int a, unsigned int b);
	//unsigned int mySub(int a, int b);

private:
	BitWiseOperators* bw;
	deque<int> result;
};

#endif	//	CONVERTER_H
