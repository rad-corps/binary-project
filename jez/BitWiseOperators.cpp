///////////////////BitWiseOperators.cpp /////////////////

#include "BitWiseOperators.h"
#include <string>
#include <iostream>

using namespace std;

BitWiseOperators::BitWiseOperators()
{
}


BitWiseOperators::~BitWiseOperators()
{
}

string BitWiseOperators::padArray(string string_)
{
	while(string_.length() < 8)
	{
		string_ = "0" + string_;
	}
	return string_;
}

string BitWiseOperators::leftShift(string array_, int numToShift_)
{
	array_ = padArray(array_);

	for(int i = 0; i < array_.length(); i++)
	{
		if(i + numToShift_ < array_.length())
		{
			array_[i] = array_[i+numToShift_];
		}else{
			array_[i] = '0';
		}
	}
	return array_;
}

string BitWiseOperators::rightShift(string array_, int numToShift_)
{
	array_ = padArray(array_);

	for(int i = array_.length(); i >= 0; i--)
	{
		if(i - numToShift_ >= 0)
		{
			array_[i] = array_[i - numToShift_];
		}else{
			array_[i] = '0';
		}
	}
	return array_;
}

string BitWiseOperators::AND(string array1_, string array2_)
{
	array1_ = padArray(array1_);
	array2_ = padArray(array2_);

	//String lengths are always equal as we pass through validator
	string resArray = "00000000";
	for(int i = 0; i < resArray.length(); i++)
	{
		if(array1_[i] == '1' && array2_[i] == '1')
		{
			resArray[i] = '1';
		}else{
			resArray[i] = '0';
		}
	}
	
	return resArray;
}

string BitWiseOperators::OR(string array1_, string array2_)
{
	array1_ = padArray(array1_);
	array2_ = padArray(array2_);

	//String lengths are always equal as we pass through validator
	string resArray = "00000000";
	for(int i = 0; i < resArray.length(); i++)
	{
		if(array1_[i] == '1' || array2_[i] == '1')
		{
			resArray[i] = '1';
		}else{
			resArray[i] = '0';
		}
	}
	
	return resArray;
}

string BitWiseOperators::XOR(string array1_, string array2_)
{
	array1_ = padArray(array1_);
	array2_ = padArray(array2_);

	//String lengths are always equal as we pass through validator
	string resArray = "00000000";
	for(int i = 0; i < resArray.length(); i++)
	{
		if(array1_[i] != array2_[i])
		{
			resArray[i] = '1';
		}else{
			resArray[i] = '0';
		}
	}
	
	return resArray;
}

string BitWiseOperators::NOT(string array1_)
{
	array1_ = padArray(array1_);
	
	string resArray = "00000000";

	for(int i = 0; i < resArray.length(); i++)
	{
		if(array1_[i] == '0')
		{
			resArray[i] = '1';
		}else{
			resArray[i] = '0';
		}
	}

	return resArray;
}