//File:			Application.h
//Author:		Jeremy Eade
//Brief:		Application Header file
//				Program Logic & where the magic happens
//				Handles user input & general flow.

#pragma once
#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <string>
#include "Validator.h"
#include "Converter.h"

#include "BitWiseOperators.h"

class Application
{
public:
	Application();
	~Application();

	void Run();
	void Tests();

	//Handles validation of user input
	string Validate(string c_,const char* v_, int min_, int max_, int maxStringLength_, DATA_TYPE dataType_);

private:
	string userInput, firstNumber, secondNumber, binaryResult;
	int selection, decResult;

	unsigned int userSelectionMin;
	unsigned int userSelectionMax;
	unsigned int userSelectionLength;
	char* userSelectionValidChars;
	DATA_TYPE userDataType;

	unsigned int decUMin;
	unsigned int decUMax;
	unsigned int decULength;
	char* decUValidChars;
	DATA_TYPE decUDataType;

	signed int decSMin;
	signed int decSMax;
	unsigned int decSLength;
	char* decSValidChars;
	DATA_TYPE decSDataType;

	unsigned int binMin;
	unsigned int binMax;
	signed int binLength;
	char* binValidChars;
	DATA_TYPE binDataType;

	//int decimal;

	Validator* validator;
	Converter* converter;

	BitWiseOperators* bw;
};

#endif	//	APPLICATION_H