#pragma once
#include <string>

using std::string;

class StringSet
{
public:

	//Default Constructor
	//create an array of size 2 and init vars
	StringSet();

	//Copy Constructor
	//creates a deep copy
	StringSet(const StringSet& copyConsParam);

	//Destructor
	//deallocates dynamic memory
	~StringSet();

	//overloaded opperator
	//deletes dynamic array and performs a deep copy
	StringSet& operator=(const StringSet& operatorParam);
	
	//insert
	//inserts into the dynamic array
	//it increases the size of the array if it reaches its max size
	bool insert(string insertParam);

	//remove
	//if a string is in the array replace it with the last string and decremets the size of the array
	void remove(string removeParam);

	//size
	//returns the current size of the array
	int size() const;

	//find
	//finds a string in the array that matches the string parameter
	//otherwise it returns -1 for not found
	int find(string findParam) const;

	//Union
	//unionize the 2 sets
	StringSet unions(const StringSet& unionsParam) const;

	//Intersection
	//intersection of two sets
	StringSet intersection(const StringSet& intersectionParam) const;

	//Difference
	//set difference of two sets
	StringSet difference(const StringSet& differenceParam) const;

private:
	//copy constructor and operator overload helper
	//preventing code duplication
	void copyHelper(const StringSet& copyParam);

	//string array pointer
	string* arrPtr;

	//vars for array size
	int currentSize;
	int maxSize;

};
