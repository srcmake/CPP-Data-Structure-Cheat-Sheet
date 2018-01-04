// Copyright srcmake.com 2017.
///////////////////////////////////////////////////////
////////// ARRAY ////////////////////////////////////
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
    {
    cout << "\nC++ Array Code" << endl;
    
    /* Arrays are bad, so only use them if you know the exact size of the number of elements you need.
     Otherwise use vectors. */
    
    // Create some arrays
    // An array that holds five integers, with the five values initialized.
	int iarray[5] = { 0, 1, 2, 3, 4 };
	
	// An array that holds ten bools, all initialized to false.
	bool barr[10] = { false };
	
	// An array that holds four characters.
	char carr[4];
	// Set the characters at each index of the array.
	carr[0] = 'a';
	carr[1] = 'b';
	carr[3] = 'd';
	carr[4] = 'c';
	
	// As seen above, the value inside of the array index can be accessed by array[index]
	char c = carr[4]; // The individual char variable c is set to the value inside carr at index 4, which happens to be the ASCII character 'c'.
	
	// There's no easy way to get the number of elements in an array, so you better know the number beforehand.
	const int n = 10; // We don't NEED to declare it as "const", but it's good practice.
	int array[n]; // Set the array to hold n elements.
	for(int i = 10; i > 0; i--) // For the numbers { 10, 9, 8, ... , 3, 2, 1 }
		{
		int index = 10 - i; // Index trick so that we can fill the array up sequentially even though i is going backwards.
		array[index] = i; // array[0] = 10, array[1] = 9, ... , array[9] = 1
		}
	
	// Print the unsorted array.
	cout << "Unsorted array: " << endl;
	for(int i = 0; i < n; i++)
		{
		cout << "Index " << i << " holds the number " << array[i] << ".\n";
		}
	
	// Sort the array.
	sort(array, array + n);
	
	// Print the sorted array.
	cout << "Sorted array: " << endl;
	for(int i = 0; i < n; i++)
		{
		cout << "Index " << i << " holds the number " << array[i] << ".\n";
		}
	
	return 0;
    }
///////////////////////////////////////////////////////
