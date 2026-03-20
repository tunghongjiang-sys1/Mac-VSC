#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string place = "Place";
    cout << &place << endl;

    // create a new reference for place variable
    string& city = place;  

    // Modify the referrence
    // If we change the referrencec, we change the variable itself

    city = "Sengkang";

    cout << place << endl;


    int height = 180;
    int& height2 = height;
    height2 = 200;
    cout << height << endl;

    return 0;
}
