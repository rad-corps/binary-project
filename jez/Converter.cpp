#include "Converter.h"


Converter::Converter()
{
	bw = new BitWiseOperators();
}


Converter::~Converter()
{
}

string Converter::DecToBinUnsigned(string decimal_)
{
	////We take an unsigned char between 0-255
	//unsigned char a = decimal_;
	////We need to store its bits individually so we use a container
	//char binaryOutputArray[8];
	////i < 8  as we have 8 positions or 8 bits in a byte
	//for(int i = 0; i < 8 ; i++)
	//{
	//	binaryOutputArray[7-i] = (bw->rightShift(a.)) & 0x01;
	//}
	//cout << "Number: " << (int)a << ". Binary: ";
	//for(int i = 0; i < 8; i++)
	//{
	//	cout << (int)binaryOutputArray[i];
	//}
	//cout << endl;

	//TO calculate binary we divide the decimal by 2
	//The remainder is recorded & we rinse repeat
	//Once our decimal is reduced to 1 or 0
	//We read the number backwards and that is our binary product
	int temp = atoi(decimal_.c_str());
	int remainder;
	while(temp > 0)
	{
		remainder = temp%2;
		temp /= 2;
		result.push_front(remainder);
	}

	while(result.size() < 8)
	{
		result.push_front(0);
	}

	//Convert int back to string for output
	string resultStr = "00000000";
	for(int i = 0; i < 8; i++)
	{
		if(result[i] == 0)
		{
			resultStr[i] = '0';
		}else
		{
			resultStr[i] = '1';
		}
	}

	return resultStr;
}


string Converter::DecToBinSigned(string decimal_)
{
	//signed char a = decimal_;
	////We need to store its bits individually so we use a container
	//char binaryOutputArray[8];
	////i < 8  as we have 8 positions or 8 bits in a byte
	//for(int i = 0; i < 8 ; i++)
	//{
	//	binaryOutputArray[7-i] = (a >> i) & 0x01;				//Bit-wise operators:	right shift (>>) & AND(&)
	//}
	//cout << "Number: " << (int)a << ". Binary: ";
	//for(int i = 0; i < 8; i++)
	//{
	//	cout << (int)binaryOutputArray[i];
	//}
	//cout << endl;

	//To calculate a signed number to binary we use Two complement if number is negative - we work out the binary
	//invert & +1

	string binTemp;

	//Check number is negative
	if(decimal_[0] == '-')
	{
		//Convert to number & make positive
		int temp = atoi(decimal_.c_str()) * -1;

		//If we subtract 1 from the number now this is like adding one one at the binary stage so all we need to do is now flip the number
		//We subtract 1 because we +1 when number is a negative
		temp--;

		//Convert back to string
		binTemp = to_string(temp);
		//Convert to binary
		binTemp = DecToBinUnsigned(binTemp);
		//Since our number is negative we now invert
		binTemp = bw->NOT(binTemp);
	}else{
		binTemp = DecToBinUnsigned(decimal_);
	}

	return binTemp;
}

int Converter::BinToDecUnsigned(string binary_)
{
	//int originalNum = num_;
	//unsigned char number = 0;									//use char as only working with 8 bit number
	//for(int i = 0; num_ > 0; i++)
	//{
	//	if(num_ % 10 == 1)
	//	{
	//		number += (1 << i);									//bit-wise operator:	left shift
	//	}
	//	num_ /= 10;
	//}
	//cout << "[UNSIGNED MODE] binary: " << originalNum << ". decimal: " << (int)number << endl;

	//Since we have a string lets pass that to an int array
	deque<int> binaryArray;
	for(int i = 0; i < binary_.length(); i++)
	{
		int asciiValueZero = 48;
		binaryArray.push_back(binary_[i]-asciiValueZero);
		//cout << binaryArray[i] << endl;
	}

	while(binaryArray.size() < 8)
	{
		binaryArray.push_front(0);
	}

	/*for(int i = 0; i < 8; i++)
	{
	cout << binaryArray[i];
	}*/
	//cout << binaryArray.size();

	int num = 0;
	for(int i = 0; i < binaryArray.size(); i++)
	{
		if(i < binaryArray.size() - 1)
		{
			//cout << "2*" << binaryArray[i] << "," << binaryArray.size() -i-1 <<  endl;
			num += pow(2*binaryArray[i],binaryArray.size()-1-i);
		}else if(i == binaryArray.size() - 1 && binaryArray[binaryArray.size() -1] == 1){
			num++;
		}
	}

	return num;
}


//We pass an unsigned int as binary can not be entered as negative
int Converter::BinToDecSigned(string binary_)
{
	//int originalNum = num_;
	//signed char number = 0;									//Use char as only working with 8 bit number
	//for(int i = 0; num_ > 0; i++)
	//{
	//	if(num_ % 10 == 1)
	//	{
	//		number += (1 << i);								//Bit-wise operator:	left shift
	//	}
	//	num_ /= 10;
	//}
	//~number;												//Bit-wise operator:	NOT
	//cout << "[SIGNED MODE] Binary: " << originalNum << ". Decimal: " << (int)number << endl;

	int num = 0;

	//Make sure string has 8 bits
	while(binary_.length() < 8)
	{
		binary_ = "0" + binary_;
	}

	//Get Sign
	char sign = binary_[0];

	if(sign == '0')
	{
		return BinToDecUnsigned(binary_);
	}else	{
		string binTemp = bw->NOT(binary_);

		//cout << "S" <<binTemp << endl;

		//Pass string into an int deque
		deque<int> binaryArray;
		for(int i = 0; i < binTemp.length(); i++)
		{
			int asciiValueZero = 48;
			binaryArray.push_back(binTemp[i]-asciiValueZero);
			//cout << "b:" << binaryArray[i] << endl;
		}


		//Let's add 1 prior to conversion
		int oneToAdd = 1;
		for(int i = binaryArray.size() - 1; i >= 0; i--)		//Do not include 0 as this defines the sign
		{
			if(i == binaryArray.size()-1 && binaryArray[i] == 0 && oneToAdd > 0)
			{
				binaryArray[i] = 1;
				oneToAdd = 0;
			}else if (binaryArray[i] == 1 && oneToAdd > 0)
			{
				binaryArray[i] = 0;
			}else if(binaryArray[i] == 0 && oneToAdd > 0)
			{
				binaryArray[i] = 1;
				oneToAdd = 0;
			}
		}

		//Calculate decimal ignoring position 0
		for(int i = 0; i < binaryArray.size(); i++)
		{
			if(i < binaryArray.size() - 1)
			{
				//cout << "2*" << binaryArray[i] << "," << binaryArray.size() -i-1 <<  endl;
				num += pow(2*binaryArray[i],binaryArray.size()-1-i);
			}else if (i == binaryArray.size() - 1 && binaryArray[binaryArray.size() -1] == 1){
				num++;
			}
		}

		if(sign == '1')
		{
			num *= -1;
		}
	}

	return num;
}

string Converter::addBinary(string binary1_, string binary2_)
{
	string carry = bw->AND(binary1_, binary2_);
	string result = bw->XOR(binary1_, binary2_);

	//cout << carry << endl;
	//cout << result << endl;

	int tempNum = BinToDecUnsigned(carry);

	//cout << tempNum << endl;

	while(tempNum != 0)
	{
		string shiftedCarry = bw->leftShift(carry,1);
		carry = bw->AND(result, shiftedCarry);
		tempNum = BinToDecUnsigned(carry);

		result = bw->XOR(result, shiftedCarry);
	}
	return result;
}

string Converter::subBinary(string binary1_, string binary2_)
{
	return addBinary(binary1_, addBinary(bw->NOT(binary2_), "00000001"));
}

int Converter::addDecimal(string a_, string b_)
{
	return atoi(a_.c_str()) + atoi(b_.c_str());
}

int Converter::subDecimal(string a_, string b_)
{
	return atoi(a_.c_str()) - atoi(b_.c_str());
}

//Using pre-defined bitwise operators.
//unsigned int Converter::myAdd(unsigned int a, unsigned int b)
//{
//	unsigned int carry = a & b;
//	//cout << "Carry: " << carry << endl;
//	unsigned int result = a ^ b;							//BITWISE operator XOR
//	//cout << "Result: " << result << endl;
//	while(carry != 0)
//	{
//		unsigned int shiftedcarry = carry << 1;
//		//cout << "Shifted Carry: " << shiftedcarry << endl;
//		carry = result & shiftedcarry;
//		//cout << "Carry: " << carry << endl;
//		result ^= shiftedcarry;
//		//cout << "Result: " << result << endl;
//	}
//	return result;
//}
//
//unsigned int Converter::mySub(int a, int b)
//{
//	return myAdd(a, myAdd(~b, 1));
//}