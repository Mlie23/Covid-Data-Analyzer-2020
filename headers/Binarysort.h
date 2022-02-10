#ifndef BINARYSORT_H
#define BINARYSORT_H
#include "../headers/Cases.h"

//Source: Scott Griffith Binarysort base
//Recursive, checks to see if the middle value of the array is the key
// Input: vectorarray - passing in the vector that we have created in int main
//			could be male could be female
//        Type key   - Value of an element to compare what to search.
//        start - Start index of the search
//        end   - End value of the search
// Start and end should always be less than the size of the array and greater than 0
// Returns: the insertion point if found
//          the negative insertion point if not found
template <typename T>
int binary_search(vector<T> &vectorarray, T key, int start, int end)
{
	//Initial Base Case, start is greater than end (done with search)
	if (start > end)
	{
		//return the negative insertion point
		return (start + 1) * -1;
	}

	//Calculate the mid value
	int mid = (start + end) / 2;
	//if key found at vector [mid], return value of mid
	if (key == vectorarray[mid])
	{
		return mid;
	}
	else if (key > vectorarray[mid])
	{
		// Key is greater than the Current value
		//search the upper half of the vecor
		return binary_search(vectorarray, key, mid + 1, end);
	}
	else if (key < vectorarray[mid])
	{
		//Key is less than the current value
		//search the lower half of the vecor
		return binary_search(vectorarray, key, start, mid - 1);
	}

	//If there is an error
	return -1;
}

//shuffles all elements of an array from a specific point
// Input: array - vector of Type to be shuffled / moved
//        vectorstring - vector of string to be shuffled / moved
//        aSize - max size of vector
//        index - location in array of the shuffle
// All elements from index to aSize are shuffled over to the right
template <typename T>
void shuffle(vector<T> &vectorarray, int aSize, int index)
{
	//Start at the end
	for (int i = aSize - 1; i > index; i--)
	{
		//Copy left neighbor into current element
		//we need to copy the words vectorarray and also the string vectorarray
		//to make them not going  out of track
		vectorarray[i] = vectorarray[i - 1];
	}
}

//Adds element to the middle of an array
//shuffle the array to the right to make space for insertion
// Input: array - collection of vector data
//        aSize - max size of vector Type
//        item  - item to be inserted
//        index - location in array of insertion
// Insertion point can be negative
// All elements from index to aSize are shuffled over to the right
// Item is added to index point
template <typename T>
void insert(vector<T> &vectorarray, int aSize, T item, int index)
{
	//Remove negative offset
	if (index < 0)
	{
		index = (index * -1) - 1;
	}
	//Make space for new value
	shuffle(vectorarray, aSize, index);
	//Add new value
	vectorarray[index] = item;
}

// Binary Search Based Sort
// Input: vectorarray - vector to be sorted
//        vectorarray_size - size of the vector (could be words / counts they all could fit)
// array will be re-created in a sorted form
template <typename T>
void binarysort(vector<T> &vectorarray, int vectorarray_size)
{
	//Set up working vectorarray for string
	vector<T> workingvector(vectorarray_size);
	//First value is already sorted/placed
	workingvector[0] = vectorarray[0];

	//For each index of vector,
	// find the insertion point in working vector
	// then insert value in working
	for (int i = 1; i < vectorarray_size; i++)
	{
		int iPoint = binary_search(workingvector, vectorarray[i], 0, i - 1);
		insert(workingvector, i + 1, vectorarray[i], iPoint);
	}

	//Copy over all the elements from working to input vector
	for (int i = 0; i < vectorarray_size; i++)
	{
		//keep the string and int together to keep them in the same order and track
		vectorarray[i] = workingvector[i];
	}
}



#endif