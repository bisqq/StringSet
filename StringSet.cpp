#include <iostream>
#include "StringSet.h"

//Default Constructor
//init variables and allocates memory for the string array
StringSet::StringSet() 
{
	maxSize = 2;
	currentSize = 0;

	arrPtr = new string[maxSize];
}

//Copy Constructor
StringSet::StringSet(const StringSet& copyConsParam)
{
	copyHelper(copyConsParam);
}

//Destructor
//deletes array pointer 
StringSet::~StringSet() 
{
	delete[] arrPtr;
}

//helper method for copy constructor and assignment operator
//Makes a deep copy
void StringSet::copyHelper(const StringSet& copyParam)
{
	//Deep Copy
	maxSize = copyParam.maxSize;
	currentSize = copyParam.currentSize;

	arrPtr = new string[maxSize];
	for (int i = 0; i < currentSize; i++)
	{
		arrPtr[i] = copyParam.arrPtr[i];
		
	}
}

//operator overload
//deletes array and calls the copyStringSet function
StringSet& StringSet::operator=(const StringSet& operatorParam) {

	if (this != &operatorParam)
	{
		delete[] arrPtr;
		copyHelper(operatorParam);
	}
	
	return *this;
}

//insert
bool StringSet::insert(std::string insertParam)
{
	//tests if string is in the array, if it is return false
	if (find(insertParam) != -1)
	{
		return false;
	}
	else
	{	//tests if the current size of the array has reached the array max size allocated in memory
		if (currentSize == maxSize)
		{	
			//double max size
			maxSize *= 2;

			//creates a temp array
			string* dynamicArrTwo = new string[maxSize];

			//copy old array to new temp array
			for (int i = 0; i < currentSize; i++)
			{
				dynamicArrTwo[i] = arrPtr[i];
			}

			//delete allocated memory
			delete[] arrPtr;

			//assign the temp dynamic array to the objects pointer
			this->arrPtr = dynamicArrTwo;
		}

		
		//if the current size doesn't meet the max size it moves on and it gets the
		//current size int and assigns the parameter to the next available index in the array

		//if it current size does equals the max size it performs that operation
		//then continues to assign the next parameter to the next available index in the array

		arrPtr[currentSize] = insertParam;

		//increments currentSize
		++currentSize;

		return true;
	}
}

//remove
void StringSet::remove(std::string removeParam)
{
	int i = 0;

	//when called it tests if the parameter is in the array
	if (find(removeParam) != -1)
	{	
		//create an external loop just to increment the i variable 
		//and not cause anything to be overwritten such as a for loop
		while (arrPtr[i] != removeParam) i++;

		//assigns the currents index value to the last value in the array
		//and decrements
		arrPtr[i] = arrPtr[currentSize - 1];
		--currentSize;
	}
	
}

//size
int StringSet::size() const 
{
	//returns the current size
	return currentSize;
}

//find
int StringSet::find(std::string findParam) const
{
	//loops through the current size and checks if the parameter is in the current array
	//if it does exist it returns the index otherwise it returns -1
	for (int i = 0; i < currentSize; i++)
	{
		if (findParam == arrPtr[i])
		{
			return i;
		}
	}
	
	return -1;
}

//unions
StringSet StringSet::unions(const StringSet& unionsParam) const
{
	//copies the set from the ref parameter
	StringSet arrUnion = StringSet(unionsParam);
	
	//loops through the current size and inserts the current array into the 
	// the other creating the union of two sets
	for (int i = 0; i < currentSize; i++)
	{
		arrUnion.insert(arrPtr[i]);
	}

	return arrUnion;

}

//intersection
StringSet StringSet::intersection(const StringSet& intersectionParam) const
{
	// calls the operator overload method which deletes the old array and creats a deep copy
	StringSet arrInter;
	StringSet set = arrInter.operator=(intersectionParam);

	//loops through the current size and tests if there is a common element
	//if so it inserts it into the array
	for (int i = 0; i < currentSize; i++)
	{
		if (set.find(arrPtr[i]) != -1)
		{
			set.insert(arrPtr[i]);
		}
	}

	return set;

}

//difference
StringSet StringSet::difference(const StringSet& differenceParam) const
{
	// calls the operator overload method which deletes the old array and creats a deep copy
	StringSet arrDiff;
	StringSet set = arrDiff.operator=(differenceParam);

	//loops through the current size and tests if that element does not exist in the the other array
	//if so it inserts it into the array
	for (int i = 0; i < currentSize; i++)
	{
		if (set.find(arrPtr[i]) == -1)
		{
			set.insert(arrPtr[i]);
		}
	}

	return set;

}