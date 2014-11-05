#include "Validator.h"
#include <cctype>


Validator::Validator()
{
}

bool Validator::validatedInput(const char* input_, const char* acceptedChars_, int min_, int max_, int maxStringLength_, DATA_TYPE dataType_)
{
	//Display userinput to screen
	cout << "[INPUT] Validating User Input: ";
	for(int i = 0; i < strlen(input_); i++)
	{
		cout << input_[i];
	}
	cout << endl;

	//Validate if input contains only integers
	//Iterate through the length of the character array checking that each value is a digit
	//for(int i = 0; i < strlen(input_); i++)
	//{
	//	if(!isdigit(input_[i]))
	//	{
	//		cout << input_[i] << " is not accepted. Please try again." << endl;
	//		return false;
	//	}
	//}

	//Since we want to use this for accepting either binary or decimal we want more control over the input handling
	//This will allow us to validate specific characters
	for(int i = 0; i < strlen(input_); i++)
	{
		int invalid = 0;
		for(int j = 0; j < strlen(acceptedChars_); j++)
		{
			if(input_[i] != acceptedChars_[j])
			{
				invalid++;
				if(invalid >= strlen(acceptedChars_))
				{
					cout << "[INPUT VALIDATION] " << input_[i] << " is not acceptable input.  Accepted Chars: "<<
						acceptedChars_ << ".  Please try again!" << endl<< endl<< endl<< endl;
					return false;
				}
			}
		}
	}
	
	//Ensure string length is satisfactory - extra level of protection when working with 8 bits
	if(strlen(input_) > maxStringLength_)
	{
		cout << "[INPUT VALIDATION] Input out of bounds. " << min_ << "->" << max_ << ". Please try again." << endl<< endl<< endl;
		return false;
	}


	//If all numbers passed we need to allow for negative numbers but disallow if the negative is not preceeding everything else
	for(int i = 1; i < strlen(input_); i++)
	{
		if(input_[i] == '-')
		{
			cout << "[INPUT VALIDATION] Input out of bounds. " << min_ << "->" << max_ << ". Please try again." << endl<< endl<< endl;
			return false;
		}
	}
	
	//Once we've determined that user input only uses accepted characters we'll validate that the value is between min and max
	if(atoi(input_) < min_ || atoi(input_) > max_)
	{
		cout << "[INPUT VALIDATION] Input out of bounds. " << min_ << "->" << max_ << ". Please try again." << endl<< endl<< endl;
			return false;
	}

	//If all else passes we're in business
	cout << "[INPUT VALIDATION] ACCEPTED." << endl << endl << endl;
	return true;
}


Validator::~Validator()
{
}
