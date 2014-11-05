#include "../include/ExtendedInt.h"
#include <string>


//assumes signed int for default ctor
ExtInt::ExtInt(bool signed_)
{
	InitBoolArray();	
	isSigned = signed_;
}

ExtInt::ExtInt(const ExtInt& copy_)
{	
	InitBoolArray();		
	this->isSigned = copy_.isSigned;
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		binaryRepresentation[i] = copy_.binaryRepresentation[i];
	}
}
ExtInt::ExtInt(const int& value_, bool signed_ = true)
{
	int tempVal;
	value_ < 0 ? tempVal = -value_: tempVal = value_;

	InitBoolArray();	
	ToBinaryRepresentation(tempVal);
	
	//if negative, minus 1 then invert
	if ( value_ < 0 ) 
	{
		(*this) = (*this) - ExtInt(1);
		(*this) = ~(*this);
	}

	isSigned = signed_;
}

//
ExtInt::ExtInt(bool* byte_, bool signed_ = true)
{
	InitBoolArray();
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		binaryRepresentation[i] = byte_[i];
	}
	isSigned = signed_;
}

int ExtInt::ToInt()
{
	int value = 0;
	int reverse_iter = TOTAL_BITS - 1;
	for ( int bit = 0; bit < TOTAL_BITS; ++bit )
	{
		//if the bool element has been turned on
		if ( binaryRepresentation[bit] )
		{
			value += 1 << reverse_iter;
		}
		--reverse_iter;
	}
	isSigned = true;
	return value;
}

ExtInt::~ExtInt()
{
//	delete binaryRepresentation;
}
	
bool* ExtInt::ToBinaryRepresentation(int value_)
{
	int reverse_iter = TOTAL_BITS - 1;
	while ( value_ > 0 )
	{
		if ( value_ % 2 == 1 )
			binaryRepresentation[reverse_iter] = true;
		--reverse_iter;
		value_ /= 2;
	}
	return binaryRepresentation;
}

void ExtInt::InitBoolArray()
{
//	binaryRepresentation = new bool[TOTAL_BITS];
	for ( int i = 0; i < TOTAL_BITS; ++i ) 
	{
		binaryRepresentation[i] = false;
	}
	//binaryRepresentation[TOTAL_BITS] = '\0';
}

std::string ExtInt::ToStringOfBinaryRepresentation()
{
	std::string ret = "";
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		binaryRepresentation[i] ? ret += '1' : ret += '0';
	}
	return ret;
}


ExtInt ExtInt::operator &(ExtInt& val_) 
{
	//get binary rep of both ExtInts
	bool* bin1 = binaryRepresentation;
	bool* bin2 = val_.binaryRepresentation;
	
	bool res[TOTAL_BITS];
	//do the & comparison
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		if ( bin1[i] == true && bin2[i] == true )
		{
			res[i] = true;
		}
		else
		{
			res[i] = false;
		}
	}
	
	//return the result
	ExtInt resObj(res);
	return resObj;
}
ExtInt ExtInt::operator |( ExtInt& val_) 
{
	//get binary rep of both ExtInts
	bool* bin1 = binaryRepresentation;
	bool* bin2 = val_.binaryRepresentation;
	
	bool res[TOTAL_BITS];
	//do the | 
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		if ( bin1[i] == true || bin2[i] == true )
		{
			res[i] = true;
		}
		else
		{
			res[i] = false;
		}
	}
	
	//return the result
	ExtInt resObj(res);
	return resObj;
}
ExtInt ExtInt::operator ~()
{
	//get binary rep of this ExtInt
	bool* bin1 = binaryRepresentation;
	
	bool res[TOTAL_BITS];
	//do the ~
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		bin1[i] ? res[i] = false : res[i] = true;
	}
	
	//return the result
	ExtInt resObj(res);
	return resObj;
}				


ExtInt ExtInt::operator ^(ExtInt& val_) 
{
	//get binary rep of both ExtInts
	bool* bin1 = binaryRepresentation;
	bool* bin2 = val_.binaryRepresentation;
	
	bool res[TOTAL_BITS];
	//do the | 
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		if ( bin1[i] != bin2[i] )
		{
			res[i] = true;
		}
		else
		{
			res[i] = false;
		}
	}
	
	//return the result
	ExtInt resObj(res);
	return resObj;
}
ExtInt ExtInt::operator <<(ExtInt& val_)
{
	//get binary rep of both ExtInts
	bool* bin1 = binaryRepresentation;
	int shift = val_.ToInt();
	
	bool res[TOTAL_BITS];
	//do the <<
	for ( int i = 0; i < TOTAL_BITS; ++i )
	{
		if ( i + shift < TOTAL_BITS )
		{
			res[i] = bin1[i+shift];
		}
		else
		{
			res[i] = false;
		}
	}
	
	//return the result
	ExtInt resObj(res);
	return resObj;
}
ExtInt ExtInt::operator >>(ExtInt& val_)
{
	//get binary rep of both ExtInts
	bool* bin1 = binaryRepresentation;
	int shift = val_.ToInt();
	
	bool res[TOTAL_BITS];
	//do the <<
	for ( int i = TOTAL_BITS-1; i >= 0; --i )
	{
		if ( i - shift >= 0 )
		{
			res[i] = bin1[i-shift];
		}
		else
		{
			res[i] = false;
		}
	}
	
	//return the result
	ExtInt resObj(res);
	return resObj;
}

ExtInt ExtInt::operator + (ExtInt& val_)
{
	ExtInt ret;
	bool carry = false;

	//iterate backwards over the array
	for (int i = TOTAL_BITS - 1; i >=0; --i )
	{
		//both on: set to 0 - set carry to true
		if ( binaryRepresentation[i] && val_.binaryRepresentation[i] )
		{
			if ( carry )
			{
				ret.binaryRepresentation[i] = true;				
			}
			else
			{
				ret.binaryRepresentation[i] = false;
			}
			carry = true;
		}
		else if ( !binaryRepresentation[i] && !val_.binaryRepresentation[i] )
		{
			if ( carry )
			{
				ret.binaryRepresentation[i] = true;
			}
			else
			{
				ret.binaryRepresentation[i] = false;
			}
			carry = false;
		}
		else //only one is switched on
		{
			if ( carry ) 
			{
				ret.binaryRepresentation[i] = false;
				carry = true;
			}
			else
			{
				ret.binaryRepresentation[i] = true;
				carry = false;
			}
		}
	}

	return ret;
}

ExtInt ExtInt::operator - (ExtInt& val_)
{
	ExtInt ret = (*this) + ((~val_) + ExtInt(1));	
	return ret;
}