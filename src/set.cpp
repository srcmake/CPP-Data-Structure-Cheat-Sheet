// Copyright srcmake.com 2017.
///////////////////////////////////////////////////////
////////// SET ////////////////////////////////////
#include <iostream>
#include <set>
using namespace std;

void DoSetOfNodes();

int main() 
    {
    cout << "\nC++ Set Code" << endl;
    
    /* Sets are data structures that don't contain duplicates.
    It's implemented as a red-black BST (according to what I quickly looked up),
    which means that insert and find are O(log n) */
    
    // Create a set
    set<int> myset;
    
    // Insert some numbers into the set. 
    myset.insert(3);
    myset.insert(2);
    myset.insert(2);
    myset.insert(4);
    myset.insert(1);
    
    // The set contains: 3 2 4 1 in a tree format
    
    // Print each number in the set.
    cout << "Printing the numbers in the set: " << endl;
    set<int>::iterator it = myset.begin();
    while(it != myset.end())
        {
        int num = *it;
        cout << num << " ";
        it++;
        }
    cout << endl;
    
    // Remove something from the set.
    myset.erase(2);
    
    // Check if a specific number is in the set
    if(myset.find(2) == myset.end())
        {
        cout << "2 is no longer in the set." << endl;
        }
        
	
	// Create a set of nodes.
	DoSetOfNodes();
	
	return 0;
    }

// The node.
struct Food
	{
	// The three variables we care about.
	bool tastesGood;
	int quantity;
	string name;
	
	// Constructor for this node.
	Food(bool taste, int quant, string n)
		{
		tastesGood = taste;
		quantity = quant;
		name = n;
		}
		
	// Default constructor if no info is given.
	Food(): tastesGood(false), quantity(0), name("Air") {}
	
	// The operator for our set, which lets the set know which Food item determines the BST order (and duplicates).
	bool operator<(const Food &a) const
		{
		return quantity < a.quantity;
		}
	};
		
// Wrap our comparison operator (which we need to pass to the set when we initialize it) in a struct
struct comparison
	{
	// The operator for our set, which lets the set know which Food item determines the BST order (and duplicates).
	inline bool operator()(const Food &a, const Food &b)
		{
		return a.quantity < b.quantity;
		}
	};
		    
void DoSetOfNodes()
	{
	// The set.
	set<Food> foodset;
	
	// Insert some food into the set.
	foodset.insert(Food(true, 4, "Donut"));
	foodset.insert(Food(false, 1, "Apple"));
	foodset.insert(Food(true, 2, "Banana"));
	foodset.insert(Food(true, 3, "Banana"));
	foodset.insert(Food(true, 2, "Chocolate"));
	
	/* NOTICE That we don't use the new keyword for the food, when inserting. */
	// Notice that the "Chocolate" will not be inserted because there is already a quantity of 2 from the Bananas.
	
	// Print our set.
	cout << "\nPrinting the Food in the food set: " << endl;
    set<Food>::iterator it = foodset.begin();
    int counter = 0;
    while(it != foodset.end())
        {
        counter += 1; 
        
        // Get the food item that our iterator is currently on. Print it.
        Food food = *it;
        cout << "Food number " << counter << " has " << food.quantity << " of " << food.name << " and it ";
        if(food.tastesGood == true)
			{
			cout << "tastes good!" << endl;
			}
		else
			{
			cout << "tastes bad!" << endl;
			}
			
		// Increment our iterator to the next food item.
        it++;
        }
    
    // The food will be printed in order of smallest quantity to largest, since it's a BST.
	}
///////////////////////////////////////////////////////
