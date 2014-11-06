//Author: Adam Hulbert
//Game Math and Open GL - Binary Operator Program
//Class: ExtInt
//Desc:
// This class handles all of the required binary calculations and conversions by providing overloaded operators
// and helper functions to do the work. 
// Examples of use can be found in the main.cpp bundled with this project


#pragma once

#define EXTINT_NUMBYTES 1
#define BITS_IN_BYTE 8 
#define TOTAL_BITS BITS_IN_BYTE * EXTINT_NUMBYTES

#include <string>

class InvalidInputException
{

};

class ExtInt 
{

public:
	ExtInt(bool signed_ = true);
	ExtInt(const ExtInt& copy_);
	ExtInt(const int& value_, bool signed_ = true);
	//assume 1 byte (32 bools in the array)
	ExtInt(bool* byte_, bool signed_ = true);
	
	//throws InvalidInputException if not in format 00000000
	ExtInt(const char* array_, bool signed_ = true);
	~ExtInt();
	int ToInt();
	bool* ToBinaryRepresentation(int value_);
	std::string ToStringOfBinaryRepresentation();
	ExtInt operator &(ExtInt& val_);  //AND
	ExtInt operator |(ExtInt& val_);  //OR
	ExtInt operator ~();			  //NOT
	ExtInt operator ^(ExtInt& val_);  //XOR
	ExtInt operator <<(ExtInt& val_); //left shift
	ExtInt operator >>(ExtInt& val_); //right shift
	ExtInt operator + (ExtInt& val_); //Addition
	ExtInt operator - (ExtInt& val_); //Subtraction

private:
	void InitBoolArray();

	//this class is only storing the binary byte data and wether it is signed.
	bool binaryRepresentation[TOTAL_BITS];
	bool isSigned;

};