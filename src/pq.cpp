// Copyright srcmake.com 2017.
///////////////////////////////////////////////////////
////////// PRIORITY QUEUE ////////////////////////////////////
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() 
    {
    cout << "\nC++ Priority Queue Code" << endl;
    
    /* Priority queues are good for inserting an item into a data structure when you need the DS to stay sorted.  */
    
    // Create a priority queue of integers. (Larger numbers go on top.)
    priority_queue<int> pq; 
	// One trick for getting smaller numbers to go on top (be prioritized first) is to make the numbers negative.
	// Otherwise, you can use the following to initialize such a priority queue:
	//priority_queue<int, vector<int>, greater<int> > pq
	
	// Add some numbers to our priority queue.
	pq.push(4);
	pq.push(2);
	pq.push(2);
	pq.push(6);
	pq.push(5);
	pq.push(3);
	pq.push(1);
	
	// pq = { 6, 5, 4, 3, 2, 2, 1 }
	
	// Print each number and remove it from the priority queue.
	cout << "Printed priority queue: " << endl;
	while(pq.empty() == false) // While it's false that our pq is empty.,,
		{
		int topnum = pq.top();
		cout << topnum << " ";
		pq.pop();
		}
	cout << endl;
	
	// Now let's create a priority queue of nodes, so that we can have many data types.
	
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
		};
	
	/* Node initialization is as such
	Food* myFood = new Food(true, 100, "chicken");
	cout << myFood->name << endl;
	*/
	
	// Create the comparison operator so that smaller quantities go on top
	struct SmallerQuant
		{
		bool operator()(const Food* a, const Food* b) const
			{
			// Returns true if a is bigger than b, meaning smaller numbers are prioritized
			return a->quantity > b->quantity;
			}
		};
	
	// Create our priority queue of foods.
	priority_queue<Food*, vector<Food*>, SmallerQuant> foodpq;
	
	// Add some nodes to this queue.
	
	foodpq.push(new Food(false, 1, "Apple"));
	foodpq.push(new Food(true, 2, "Banana"));
	foodpq.push(new Food(true, 5, "Eclair"));
	foodpq.push(new Food(true, 3, "Chocolate"));
	foodpq.push(new Food(true, 4, "French Fries"));
	
	// Print each food in our pq.
	cout << endl << "Printed Food priority queue: " << endl;
	int counter = 0;
	while(foodpq.empty() == false)
		{
		counter += 1;
		Food* food = foodpq.top();
		foodpq.pop();
		cout << "Food number " << counter << " has " << food->quantity << " of " << food->name << " and it ";
		if(food->tastesGood == true)
			{
			cout << "tastes good!" << endl;
			}
		else
			{
			cout << "tastes bad!" << endl;
			}
		}
	
	return 0;
    }
///////////////////////////////////////////////////////
