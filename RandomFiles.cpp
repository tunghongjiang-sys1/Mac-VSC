// Example 1: Print numbers from 1 to 100 with a star
#include <iostream>
using namespace std;

int main() 
{
    for (int i = 1; i <= 100; ++i) 
    {
        cout << "* - " << i << endl; // Print the value of i
    }

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Example 2: Function to reduce an integer by 10

#include <iostream>
using namespace std;

// Build a function that reduces an original integer by 10
int reduceBy10(int n)
{
    return n - 10;
}

int main()
{
    int number = 50;
    cout << "Original number: " << number << endl;
    number = reduceBy10(number);
    cout << "After reduceBy10: " << number << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Example 3: Using a function to modify age

#include <iostream>
using namespace std;

int potion(int age) 
{
    return age - 10;
}

int main() 
{
    int age = 100;
    age = potion(age);

    cout << age << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Example 4: Pass by reference for a string

#include <iostream>
#include <string>
using namespace std;

string item = "dirt";

// Function modifies the original string using reference
void magic(string &item) 
{
    item = "diamond";
}

int main()
{
    cout << "Before magic: " << item << endl;
    magic(item);
    cout << "After magic: " << item << endl;

    return 0;
}

/////////////////////////////////////////////////////////////////////////////
// Example 5: Pass by reference with arrays
#include <iostream>
#include <string>
using namespace std;

// Pass by Value vs Pass by reference
// Modify an array by reference
void Array_Multiplier(int (&someArray)[10])
{
    // when there's &
    // we mess with the original data
    for(int& i : someArray)
    {
        i = i * 2;
    }
}

int main() 
{
    // Initialize an integer array
    // Array size has to be declared in the first place
    // C++ array has fixed size
    int weight[10] = {1, 2, 3, 4, 5}; // remaining elements default to 0

    cout << "Original array: ";
    for (int i : weight)
    {
        cout << i << " ";
    }
    cout << endl;

    Array_Multiplier(weight);

    cout << "After multiplying by 2: ";
    for(int i : weight)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}