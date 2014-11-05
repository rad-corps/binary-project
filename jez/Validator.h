//File:			Validator.h
//Author:		Jeremy Eade
//Brief:		Validator Header file
//				Iterates over user input validating input conditions returning true or false

#pragma once
#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <iostream>
#include <string>

//Included for later use for more control over input
enum DATA_TYPE
{
	uDec,
	sDec,
	binary,
};

using namespace std;

class Validator
{
public:
	Validator();
	~Validator();

	//const char* input_:			User input
	//const char* acceptedChars_:	Pass accepted keystrokes only ie '1234' will only allow characters 1234
	//int min_:						Minimum value accepted
	//int max_:						Maximum value accepted
	//int maxSTringLength_:			Controls length of acceptable input
	//DATA_TYPE dataType_:			To be implemented at a later date for further user input control (ie switch between decimal/binary/general_numerical/text)
	bool validatedInput(const char* input_, const char* acceptedChars_, int min_, int max_, int maxStringLength_, DATA_TYPE dataType_);

private:
};

#endif //	VALIDATOR_H