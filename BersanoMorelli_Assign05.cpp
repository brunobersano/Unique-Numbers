//BersanoMorelli_Assign05.cpp
//Prompts user to enter 20 numbers
//Within a certain range and displays them
//Author: Bruno Bersano Morelli
//June 1st, 2018

#include <iostream>
#include <array>
using namespace std;

//Function Prototype

// pass stl array of length "size" to validate if the input number is unique
template<size_t size>
bool isUnique(const std::array<int, size> & myArray, int input); 

int main()
{
	const size_t SIZE = 20; //Maximum size of the array
	const int MIN_NUM = 10; //Input must be between 10
	const int MAX_NUM = 100;//And a 100
	const int LINE_BREAK = 5;//Numbers displayed per line

	std::array<int, SIZE> myArray; //Declare STL Array to store input
	int count = 1; //Count valid numbers entered
	int pos = 0; //next position to add values in the array
	int num = 0; //Sotres input number

	//Get the input from the user for 20 numbers
	while (count <= SIZE)
	{
		cout << "\nEnter # " << count << " : "; //Prompt user to enter numbers
		cin >> num; //Store input to num

		//Validate if input is within range
		if (num < MIN_NUM || num > MAX_NUM)
		{
			//Display error message in case it isn't
			cerr << "The number entered is not in the valid range of " 
				<< MIN_NUM << " to " << MAX_NUM << "\n";
		}
		else
		{
			//If withing range, test if it is unique
			if (isUnique(myArray, num))
			{
				//Inform user
				cout << "The number: " << num << " is unique \n";
				myArray[pos] = num; //Add to the array
				pos++; //increment to nex position
			}
			count++; //increment counter;
		} //End if else

	} //End while loop
	
	//Once the user is done, display the numbers (implement separatelyy
	cout << "\n\nThe unique numbers are: \n\n";

	//Loop the array to get the values to display
	for (int i = 0; i < pos; i++)
	{
		cout << "    " << myArray[i]; //print number

		if ((i+1) % LINE_BREAK == 0) //If reached the max number in a line
		{
			cout << '\n'; //go to the next line
		}
		
	} //End while loop
	cout << "\n";
	return 0; //End program
} //End main 

// Pass STL array to tmeplate function
template <size_t size>
bool isUnique(const std::array<int, size> & myArray, int input)
{
	int currentNum = input; //User current inpur
	bool unique = true; //Flag is it's an unique number

	//Loop array to find duplicate
	for (auto value : myArray) {
		if (value == currentNum)
		{
			unique = false; //If duplicate, flag it to non-unique
		}
	}
	
	return unique;  //return if unique is true or false
}

