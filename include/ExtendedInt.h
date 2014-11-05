#pragma once

#define EXTINT_NUMBYTES 1
#define BITS_IN_BYTE 8 
#define TOTAL_BITS BITS_IN_BYTE * EXTINT_NUMBYTES

#include <string>

class ExtInt 
{


public:
	ExtInt(bool signed_ = true);
	ExtInt(const ExtInt& copy_);
	ExtInt(const int& value_, bool signed_ = true);
	//assume 1 byte (32 bools in the array)
	ExtInt(bool* byte_, bool signed_ = true);
	~ExtInt();
	int ToInt();
	bool* ToBinaryRepresentation(int value_);
	std::string ToStringOfBinaryRepresentation();
	ExtInt operator &(ExtInt& val_);  //AND
	ExtInt operator |(ExtInt& val_);  //OR
	ExtInt operator ~();					//NOT
	ExtInt operator ^(ExtInt& val_);  //XOR
	ExtInt operator <<(ExtInt& val_); //left shift
	ExtInt operator >>(ExtInt& val_); //right shift
	ExtInt operator + (ExtInt& val_); //Addition
	ExtInt operator - (ExtInt& val_); //Subtraction

private:
	void InitBoolArray();
	//bool* binaryRepresentation;
	bool binaryRepresentation[TOTAL_BITS];
	bool isSigned;
	//int value; //unsigned ints will also be stored in this value as a negative

};