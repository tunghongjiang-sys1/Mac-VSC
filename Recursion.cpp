// Example 1: Sum from 0 to n using iterative and recursive approaches
#include <iostream>
using namespace std;

// Iterative approach
int sum(int n)
{
    int result = 0;
    for(int i = 0; i <= n; i++)
    {
        result += i;
    }
    return result;
}

// Recursive approach
int sum_recur(int n)
{
    if (n == 0) return 0; // Base case
    return n + sum_recur(n - 1);
}

int main() 
{
    cout << "Sum (recursive) of 100: " << sum_recur(100) << endl;
    return 0;
}

// Example 2: Walking steps forward and backward using recursion
#include <iostream>
using namespace std;

void walk_backward(int n)
{
    if (n == 0) 
    {
        cout << "You take step #" << n << endl;
        return;
    }
    
    cout << "You take step #" << n << endl;
    walk_backward(n - 1);
}

void walk_forward(int n)
{
    if(n == 0) return;

    walk_forward(n - 1);
    cout << "You take step #" << n << endl;
}

int main() 
{
    walk_backward(10);
    walk_forward(10);

    return 0;
}

// Example 3: Fibonacci number calculation (recursive and bottom-up)
#include <iostream>
using namespace std;

// Recursive Fibonacci
unsigned long long fib(int n)
{
    if (n <= 1) return n;
    return fib(n - 2) + fib(n - 1);
}

// Bottom-Up recursion to print Fibonacci sequence
unsigned long long fib_bottom_up(int n, int a = 0, int b = 1, int current = 0)
{
    if(current < n)
    {
        cout << a << " ";
        fib_bottom_up(n, b, a + b, current + 1);
    }
}

int main() 
{
    cout << "First 10 Fibonacci numbers (bottom-up): ";
    fib_bottom_up(10);
    cout << endl;
    
    return 0;
}

// Example 4: Reverse a string in-place using recursion
#include <iostream>
#include <string>
using namespace std;

void reverseInPlace(string& anyString, int left, int right)
{
    if (left >= right) return;
    swap(anyString[left], anyString[right]);
    reverseInPlace(anyString, left + 1, right - 1);
}

int main() 
{
    string name = "Labubu";
    reverseInPlace(name, 0, name.size() - 1);
    cout << name << endl;
    
    return 0;
}

// Example 5: Binary Search using recursion
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Recursive binary search
int binary_search(vector<int> v, int target, int left, int right)
{
    if(left > right) return -1; // Base case: not found
    int mid = (left + right) / 2;

    if(v[mid] == target) return mid;
    else if(v[mid] > target) return binary_search(v, target, left, mid - 1);
    else return binary_search(v, target, mid + 1, right);
}

int main()
{
    vector<int> scores = {80, 95, 45, 20, 50, 100, 98, 87, 66, 0};
    sort(scores.begin(), scores.end());

    cout << "Index of 95: " << binary_search(scores, 95, 0, scores.size() - 1) << endl;

    return 0;
}

// Example 6: Tower of Hanoi using recursion
#include <iostream>
using namespace std;

void towerOfHanoi(int N, char Source, char helper, char destination)
{
    if(N == 1)
    {
        cout << "Move disc 1 from " << Source << " to " << destination << endl;
        return;
    }

    towerOfHanoi(N - 1, Source, destination, helper);
    cout << "Move disc " << N << " from " << Source << " to " << destination << endl;
    towerOfHanoi(N - 1, helper, Source, destination);
}

int main()
{
    int N;
    cout << "Enter the number of discs: ";
    cin >> N; 

    towerOfHanoi(N, 'A', 'B', 'C');

    return 0;
}