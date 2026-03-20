// =====================
// Browser Navigation using Stack
// =====================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Create 2 stacks to hold BACK and FORWARD browsing histories
stack<string> backStack;
stack<string> forwardStack;
string currentPage;

// Navigate to a new page
void Navigate(const string& newPageURL)
{
    // Save currentPage in backStack before navigating to another page
    if (!currentPage.empty())
    {
        backStack.push(currentPage);
        // Clear forward stack when navigating to a new page
        while (!forwardStack.empty()) forwardStack.pop();
    }

    currentPage = newPageURL;
    cout << "Visiting " << currentPage << endl;
}

// Go back to previous page
void back()
{
    if (backStack.empty())
    {
        cout << "No back pages available, back button disabled" << endl;
    }
    else
    {
        forwardStack.push(currentPage);
        currentPage = backStack.top();
        backStack.pop();
        cout << "Back to: " << currentPage << endl;
    }
}

// Go forward to next page
void forward()
{
    if (forwardStack.empty())
    {
        cout << "No forward pages available, forward button disabled" << endl;
    }
    else
    {
        backStack.push(currentPage);
        currentPage = forwardStack.top();
        forwardStack.pop();
        cout << "Forward to: " << currentPage << endl;
    }
}

// =====================
// Main function for browser simulation
// =====================

int main()
{
    currentPage = "https://homepage.com";
    cout << "Starting at: " << currentPage << endl;

    while (true)
    {
        cout << "Navigate(N), Back(B), Forward(F), Quit(Q)?" << endl;
        string command;
        cin >> command;

        string userInputURL;

        if (command == "N")
        {
            cout << "Enter a valid URL: ";
            cin >> userInputURL;
            Navigate(userInputURL);
        }
        else if (command == "B")
        {
            back();
        }
        else if (command == "F")
        {
            forward();
        }
        else if (command == "Q")
        {
            cout << "Exiting browser..." << endl;
            break;
        }
        else
        {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}

// =====================
// Baseball Game (Leetcode 682)
// =====================

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int calPoints(vector<string>& operations)
{
    stack<int> record;

    for (const string& op : operations)
    {
        if (op == "C")
        {
            if (!record.empty())
                record.pop();
        }
        else if (op == "D")
        {
            if (!record.empty())
                record.push(2 * record.top());
        }
        else if (op == "+")
        {
            if (record.size() >= 2)
            {
                int top1 = record.top(); record.pop();
                int top2 = record.top();
                record.push(top1);
                record.push(top1 + top2);
            }
        }
        else
        {
            record.push(stoi(op));
        }
    }

    int total = 0;
    while (!record.empty())
    {
        total += record.top();
        record.pop();
    }
    return total;
}

int main()
{
    vector<string> operations = {"5", "2", "C", "D", "+"};
    cout << "Total points: " << calPoints(operations) << endl;
    return 0;
}

// =====================
// Simplify Unix Path (Leetcode 71)
// =====================

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string simplifyPath(string rawPath)
{
    stack<string> s;
    string currentLocation;

    for (char c : rawPath)
    {
        if (c == '/')
        {
            if (currentLocation == "..")
            {
                if (!s.empty()) s.pop();
            }
            else if (!currentLocation.empty() && currentLocation != ".")
            {
                s.push(currentLocation);
            }
            currentLocation.clear();
        }
        else
        {
            currentLocation += c;
        }
    }

    // Handle the last segment
    if (currentLocation == "..")
    {
        if (!s.empty()) s.pop();
    }
    else if (!currentLocation.empty() && currentLocation != ".")
    {
        s.push(currentLocation);
    }

    // Build the simplified path
    string simplifiedPath;
    while (!s.empty())
    {
        simplifiedPath = "/" + s.top() + simplifiedPath;
        s.pop();
    }

    return simplifiedPath.empty() ? "/" : simplifiedPath;
}

int main()
{
    string path = "/.../a/../b/c/../d/.//";
    cout << "Simplified path: " << simplifyPath(path) << endl;
    return 0;
}

