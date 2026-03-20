// A pointer is a variable that stores the memory address of another variable

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // Create an integer variable a
    int a = 100;

    // to identify its memory address
    cout << &a << endl;

    // Create an integer pointer p1
    int * p1;

    // Set p1 to point to the memory address of variable a
    p1 = &a;

    // get p1 to extract the data that is stored in the memory address of a
    // for that, we have to dereference p1
    cout << *p1 << endl;

    // print the memory address stored in the pointer
    cout << p1 << endl;

    return 0;
}

//////////////////////////////////

// A pointer is a variable that stores the memory address of another variable

#include <iostream>
#include <string>
using namespace std;

int main()
{
    // A pointer is reusable
    // A pointer can also be used to modify the value of a variable

    int firstValue, secondValue;

    // create an integer pointer called p1
    int * p1;

    // set p1 to point towards firstValue
    p1 = &firstValue;

    // push an integer data into firstValue with the pointer
    *p1 = 100;
    cout << "firstValue: " << firstValue << endl;

    // reuse p1 to point towards the memory address of secondValue variable
    p1 = &secondValue;
    *p1 = 200;
    cout << "secondValue: " << secondValue << endl;

    return 0;
}