// Copyright srcmake.com 2017.
///////////////////////////////////////////////////////
////////// VECTOR ////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Pass by reference
void Print(vector< vector<int> > &inceptionvec)
    {
    cout << "Vector of vectors: " << endl;
    // Go through each row
    for(int i = 0; i < inceptionvec.size(); i++)
        {
        // Go through each column
        for(int j = 0; j < inceptionvec[i].size(); j++)
            {
            cout << inceptionvec[i][j] << " ";
            }
        cout << endl;
        }
    }

int main() 
    {
    cout << "\nC++ Vector Code," << endl;
    
    // Create a vector
    vector<int> myvec;
    
    // Add some numbers to the vector
    myvec.push_back(4);
    myvec.push_back(3);
    myvec.push_back(2);
    myvec.push_back(1);
    
	// Print the unsorted vector.
    cout << "Unsorted vector: " << endl;
    for(int i = 0; i < myvec.size(); i++) 
		{ 
		cout << myvec[i] << " "; 
		}
    cout << endl << endl;
	
    // Sort the vector using std's sort.
    std::sort(myvec.begin(), myvec.begin()+myvec.size());
    
    // Print the sorted vector.
    cout << "Sorted vector: " << endl;
    for(int i = 0; i < myvec.size(); i++) 
		{ 
		cout << myvec[i] << " "; 
		}
    cout << endl << endl;
    
    // Create a vector of vectors
    vector< vector<int> > inceptionvec;
    // Fill it up as a 3 by 3 table.
    int positionnumber = 0; // Fills our table up from 1 to 9.
    for(int i = 0; i < 3; i++) // Each row.
        {
        // Add a vector to our "vector that holds vectors". AKA, add a row to our "table".
        vector<int> row;
        inceptionvec.push_back(row);
		
		// For this new row, create + fill each "column" by adding to the row.
		// (The vector/row we just created is indexed at "i" in inceptionvec.)
        for(int j = 0; j < 3; j++) // Each column.
            {
            positionnumber += 1;
            
            // Add this particular spot in the table (which is [i][j] push the number we want.
            inceptionvec[i].push_back(positionnumber);
            }
        }
    
    // Print our vector of vectors (passed by reference to a function).
    Print(inceptionvec);
	
	return 0;
    }
