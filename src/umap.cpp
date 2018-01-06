///////////////////////////////////////////////////////
////////// Unordered_Map ////////////////////////////////////
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() 
    {
    cout << "C++ Unordered Map Code" << endl;
    
    /* An unordered_map is a hash map/table implementation in C++ for key-value pairs. */
    
    // Create an unordered_map that maps a string key to an int value
    unordered_map<string, int> m;
    
    // Add a few pairs to the map.
    m["Apple"] = 1;
    m["Banana"] = 100;
    m["Chocolate"] = 1000;
    m["Donut"] = 295;
    
    // Iterate through the map using iterators.
    cout << "\nPrinting map using iterators: " << endl;
    unordered_map<string, int>::iterator it = m.begin();
    while(it != m.end())
        {
        cout << it->first << ": " << it->second << endl;
        it++;
        }
    cout << endl;
    

    // Check if a key exists.
    if(m.find("Taylor Swift") == m.end()) 
        {
        cout << "Did not find Taylor Swift in our map." << endl;
        }
    
    cout << m["Eclair"] << endl; // Initializes the value for key="Eclair" to 0, by calling it.
    
    // To use a Node instead of a primitive data type as the value, just replace int with the Node. 

	struct Food
		{
		// The three variables we care about.
		bool tastesGood;
		int quantity;
		
		// Constructor for this node.
		Food(bool taste, int quant)
			{
			tastesGood = taste;
			quantity = quant;
			}
			
		// Default constructor if no info is given.
		Food(): tastesGood(false), quantity(0) {}
		};
    
    unordered_map<string, Food> foodmap;
    
    foodmap["Lemons"] = Food(false, 20);
    foodmap["Mango"] = Food(true, 3);
    foodmap["Nachos"] = Food(true, 100);
    
    /* Notice: We don't use the new keyword. */
    
    
    // Iterate through our food map.
    unordered_map<string, Food>::iterator fit = foodmap.begin();
    while(fit != foodmap.end())
    	{
    	string foodname = fit->first;
 	    Food food = fit->second;
    	
		cout << "We have " << food.quantity << " " << foodname << " and it tastes ";
		if(food.tastesGood == true)
			{ cout << "good." << endl; }
		else
			{ cout << "bad." << endl; }
    	
    	// Increment our iterator to move on to the next food.
    	fit++;
    	}
    
    return 0;
    }
///////////////////////////////////////////////////////
