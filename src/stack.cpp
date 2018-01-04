// Copyright srcmake.com 2017.
///////////////////////////////////////////////////////
////////// STACK ////////////////////////////////////
#include <iostream>
#include <stack>
using namespace std;

int main() 
    {
    cout << "\nC++ Stack Code" << endl;
    
    /* Stacks are First-In/Last-Out. Like the last plate you wash goes on top of the plate stack, and is the first you use when you need to use a plate again. */
    
    // Create a stack that holds integers.
    stack<int> mystack;
    
    // Add some numbers to the stack.
    mystack.push(4);
    mystack.push(2);
    mystack.push(1);
    mystack.push(3);
    
    // The stack should be 3 > 1 > 2 > 4, with 3 on top, since that's the order we pushed them in.
    
    // Print each number and remove it from the stack.
    cout << "Printed stack: " << endl;
    while(mystack.empty() == false)
    	{
    	int topnum = mystack.top(); // Look at what the top of the stack is.
    	cout << topnum << " ";
    	mystack.pop(); // Remove the top item from the stack.
    	}
	cout << endl;
	
	// Let's look at a stack of nodes. 
	/* NOTICE: This is the same as priority queues, but there's no need for an operator, and the default stack creation (stack<Food*> foodstack;) is the only difference. */
	
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
	
	
	// Create our stack of foods.
	stack<Food*> foodstack;
	
	// Add some nodes to this stack.
	foodstack.push(new Food(false, 1, "Apple"));
	foodstack.push(new Food(true, 2, "Banana"));
	foodstack.push(new Food(true, 5, "Eclair"));
	foodstack.push(new Food(true, 3, "Chocolate"));
	foodstack.push(new Food(true, 4, "French Fries"));

	
	// Print each food in our stack. (It'll go in the order we placed them in the stack, regardless of content.)
	cout << endl << "Printed Food stack: " << endl;
	int counter = 0;
	while(foodstack.empty() == false)
		{
		counter += 1;
		Food* food = foodstack.top();
		foodstack.pop();
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
