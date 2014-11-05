#include "Application.h"

Application::Application()
{
	userSelectionMin = 1;
	userSelectionMax = 9;
	userSelectionLength = 1;
	userSelectionValidChars = "123456789";
	userDataType = DATA_TYPE::uDec;

	decUMin = 0;					
	decUMax = 255;
	decULength = 3;
	decUValidChars = "0123456789";
	decUDataType = DATA_TYPE::uDec;

	decSMin = -128;
	decSMax = 127;
	decSLength = 4;
	decSValidChars = "-1234567890";
	decSDataType = DATA_TYPE::sDec;

	binMin = 0;
	binMax = 11111111;
	binLength = 8;
	binValidChars = "01";
	binDataType = DATA_TYPE::binary;

	//User choice
	selection = 0;
}

void Application::Tests()
{
	//bw = new BitWiseOperators();
	//cout << bw->leftShift("10", 1) << endl;
	converter = new Converter();
	cout << converter->subBinary("101", "011") << endl;

	//cout << converter->addDecimal("5", "10");
	//cout << converter->subDecimal("5", "10");

}

void Application::Run()
{
	Tests();


	while(selection != userSelectionMax)
	{
		cout << 
			"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl <<
			"+++++++++++++++++++++++++++++++   Bitwise Operator Program   +++++++++++++++++++++++++++++++" << endl <<
			"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl <<
			endl <<
			"1. Convert DECIMAL TO BINARY (unsigned mode) - Enter your own number 0 -> 255." << endl <<
			"2. Convert DECIMAL TO BINARY (signed mode) - Enter your own number -128 -> 127." << endl <<
			"3. Convert BINARY TO DECIMAL (unsigned mode) - Enter your own binary number with 0's & 1's." << endl <<
			"4. Convert BINARY TO DECIMAL (signed mode)  - Enter your own binary number with 0's & 1's." << endl <<
			"5. DECIMAL TO BINARY (unsigned mode) - Cycle through all 8 bit numbers." << endl <<
			"6. DECIMAL TO BINARY (signed mode) - Cycle through all 8 bit numbers." << endl <<
			"7. ADD TWO BINARY NUMBERS TOGETHER (unsigned mode)." << endl <<
			"8. SUBTRACT TWO BINARY NUMBERS (unsigned mode) - First # must be greater than second." << endl <<
			"9. EXIT PROGRAM" << endl <<
			"Enter your selection followed by the [ENTER] key." << endl <<
			endl;
		cout << "Selection > ";

		////Take in any string from user
		cin >> userInput;

		//Validate input
		Validate(userInput, userSelectionValidChars, userSelectionMin, userSelectionMax, userSelectionLength, userDataType);

		selection = atoi(userInput.c_str());

		switch(selection)
		{
		case 1:
			converter = new Converter();
			cout << "[DECIMAL TO BINARY UNSIGNED MODE] Enter a decimal number between " << decUMin << " -> " << decUMax << endl;
			cout << "Selection > ";
			cin >> userInput;
			Validate(userInput, decUValidChars, decUMin, decUMax, decULength, decUDataType);
			///decimal = atoi(userInput.c_str());
			cout << "Decimal Entered: " << userInput << ". Binary: " << converter->DecToBinUnsigned(userInput) << endl;
			delete converter;
			break;
		case 2:
			converter = new Converter();
			cout << "[DECIMAL TO BINARY SIGNED MODE] Enter a decimal number between " << decSMin << " -> " << decSMax << endl;
			cout << "Selection > ";
			cin >> userInput;
			Validate(userInput, decSValidChars, decSMin, decSMax, decSLength, decSDataType);
			//decimal = atoi(userInput.c_str());
			cout << "Decimal Entered: " << userInput << ". Binary: " << converter->DecToBinSigned(userInput) << endl;
			delete converter;
			break;
		case 3:
			converter = new Converter();
			cout << "[BINARY TO DECIMAL UNSIGNED MODE] Enter an 8 bit binary number" << endl;
			cout << "Selection > ";
			cin >> userInput;
			Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			cout << "Binary Entered: " << userInput << ". Decimal: " << converter->BinToDecUnsigned(userInput) << endl;
			delete converter;
			break;
		case 4:
			converter = new Converter();
			cout << "[BINARY TO DECIMAL SIGNED MODE] Enter an 8 bit binary number" << endl;
			cout << "Selection > ";
			cin >> userInput;
			Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			cout << "Binary Entered: " << userInput << ". Decimal: " << converter->BinToDecSigned(userInput) << endl;
			delete converter;
			break;
		case 5:
			///Use to cycle through Dec to Bin -> unsigned mode 0-255. All correct.
			for(int i = 0; i <= decUMax; i++)
			{
				converter = new Converter();
				string temp = to_string(i);
				cout << "Decimal Entered: " << temp << ". Binary: " << converter->DecToBinUnsigned(temp) << endl;
				delete converter;
			}
			break;
		case 6:
			///Use to cycle through Dec to Bin -> signed mode -128 -> 127. All correct.
			for(int i = decSMin; i <= decSMax; i++)
			{
				converter = new Converter();
				string temp = to_string(i);
				cout << "Decimal Entered: " << temp << ". Binary: " << converter->DecToBinSigned(temp) << endl;
				delete converter;
			}
			break;
		case 7:
			//Add 2 unsigned binary numbers together
			converter = new Converter();
			cout << "[ADD TWO BINARY NUMBERS] Enter an 8 bit binary number" << endl;
			cout << "First Binary Number > ";
			cin >> userInput;
			Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			firstNumber = userInput;

			cout << "Second Binary Number > ";
			cin >> userInput;
			Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			secondNumber = userInput;

			//Check if addition of binaries exceed 8 bit scope
			if(converter->BinToDecUnsigned(firstNumber) + converter->BinToDecUnsigned(secondNumber) > 255)
			{
				cout << "Result exceeds 8 bit scope of this program!" << endl;
			}else{
				//Use bitshifting to add values
				binaryResult = converter->addBinary(firstNumber, secondNumber);
				decResult = converter->BinToDecUnsigned(binaryResult);
				cout << "[INPUT]: " << firstNumber << " (" << converter->BinToDecUnsigned(firstNumber) << ")" <<
					" + " << secondNumber << " (" << converter->BinToDecUnsigned(secondNumber) << ")" << " = " << binaryResult << " : (" << decResult << ")." << endl;

				//Implementation of Addition of decimal numbers to complete rubric - int a + int b = int c;
				cout << "[DEC+DEC CONFIRMED] " << converter->addDecimal(to_string(converter->BinToDecUnsigned(firstNumber)), to_string(converter->BinToDecUnsigned(secondNumber))) << endl;
			}
			
			delete converter;
			break;
		case 8:
			//Subtract 2 unsigned binary numbers - as we are dealing with unsigned numbers the first number must be the greater #.
			converter = new Converter();
			cout << "[SUBTRACT TWO BINARY NUMBERS] FIRST BINARY MUST BE THE GREATER OF THE TWO." << endl;
			cout << "First Binary Number > ";
			cin >> userInput;
			Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			firstNumber = userInput;

			cout << "Second Binary Number > ";
			cin >> userInput;
			
			//Validate first
			Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			//Confirm second number is smaller of inputs. if not query input
			while((converter->BinToDecUnsigned(firstNumber)) < (converter->BinToDecUnsigned(userInput)))
			{
				cout << "The second number must be the smaller number as we are working with unsigned data." << endl;
				cout << "Second Binary Number > ";
				cin >> userInput;
				Validate(userInput, binValidChars, binMin, binMax, binLength, binDataType);
			}
			secondNumber = userInput;

			if(converter->BinToDecUnsigned(firstNumber) - converter->BinToDecUnsigned(secondNumber) < 0)
			{
				cout << "Result below 0.  Result exceeds 8 bit scope of this program!" << endl;
			}else{
				//Use bitshifting to add values
				binaryResult = converter->subBinary(firstNumber, secondNumber);
				decResult = converter->BinToDecUnsigned(binaryResult);
				cout << "[INPUT]: " << firstNumber << " (" << converter->BinToDecUnsigned(firstNumber) << ")" <<
					" - " << secondNumber << " (" << converter->BinToDecUnsigned(secondNumber) << ")" << " = " << binaryResult << " : (" << decResult << ")." << endl;

				//Implementation of Addition of decimal numbers to complete rubric. int a - int b = int c;
				cout << "[DEC-DEC CONFIRMED] " << converter->subDecimal(to_string(converter->BinToDecUnsigned(firstNumber)), to_string(converter->BinToDecUnsigned(secondNumber))) << endl;
			}

			break;
		default:
			break;
		}

		system("pause");


		cout << endl << endl;

	}
}

string Application::Validate(string c_, const char* v_, int min_, int max_, int maxStringLength_, DATA_TYPE dataType_)
{
	validator = new Validator();
	const char* c = userInput.c_str();
	while(!validator->validatedInput(c, v_, min_, max_, maxStringLength_, dataType_))
	{
		cout << " >  ";
		cin >> userInput;
	}
	delete validator;
	return userInput;
}

Application::~Application()
{
}
