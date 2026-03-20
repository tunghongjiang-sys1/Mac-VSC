#include <iostream>
#include <string>
using namespace std;

// Pass by Value vs Pass by referrence
// It has to do with functions

void UpdateNum_PassByValue(int& n)
{
    n += 100;
    cout << "After mod: " << n << endl;
}

int main() 
{
    int robux = 1000;
    cout << "Before mod: " << robux << endl;

    UpdateNum_PassByValue(robux);
    cout << robux << endl;

    return 0;
}

//////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

// Pass by Value vs Pass by referrence
// It has to do with functions

// Modify an array by reference
void Array_Multiplayer(int (&someArray)[10])
{
    // when there's &
    // we mess with teh original data
    for(int& i : someArray)
    {
        i = i * 2;
    }
}

int main() 
{
    // Initilize an interger array
    // Array size has to be declared in the` first place
    // c++ array has fixed size
    int weight[10] = {1, 2, 3, 4, 5};

    for (int i : weight)
    {
        cout << i << " ";
    }

    cout << endl;

    Array_Multiplayer(weight);

    for(int i : weight)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
