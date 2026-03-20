

////////////////////////////////////////////////////////////////////////////////////////////

/* Leetcode 387 - First Unique Character in a String

Problem Statement
Given a string s, find the first non-repeating character 
and return its index. If it does not exist, return -1.

Example:
"aabbc" - 4

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;


int FirstUnqiChar(string s)
{
    // Create an unordered map (cahr key + int vlaue) map and queue
    unordered_map<char, int> count_map;
    queue<char> q;

    // Traverse / Iterate styring s with a fro each loop
    for(char ch : s)
    {
        count_map[ch]++;

    }

    // Print each Key-value pair in the map
    for(const auto& pair : count_map)
    {
        cout << pair.first << " -> " << pair.second << endl;

    }

    // Check the queue for the first non-repeating character
    while(!q.empty())
    {
        char front = q.front();
        if(count_map[front] == 1)
        {
            // Return its index
            return s.find(front);
        }
        q.pop();

    }


    return -1;



}


int mian()
{
    string s = "exercise";

    cout << FirstUnqiChar(s) << endl;

    return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////

/*
Given a string, sort the characters in descending order 
based on their frequency (characters with higher frequency should come first). 
If two characters have the same frequency, 
order them according to their lexicographical order.

Example:
"russia" -> ssairu
"banana" -> aaannb
Real Life example where frequency sorting algorithm is useful
1. Search Engines (Google, Safari)
2. Social media post (sorted by likes and shares)

Data Structure;
priority queue

*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;


string frequencySort(string s)
{
    // Create an unordered map to record the ouccurrance 
    unordered_map<char, int> CountMap;


    // create empty priority queue
    priority_queue<pair<char, int>> pq;

    // iterate string s with a for-each loop
    for(char ch : s)
    {
        CountMap[ch]++;
    }

    // transfer all key value pairs in the map to the pq
    for(auto& pair:CountMap)
    {
        pq.push({pair.first, pair.second});
    }

    // build a sorted string from pq's content
    string sortedString = "";

    while(!pq.empty())
    {
        int count = pq.top().second;

        char ch = pq.top().first;

        sortedString.append(count, ch);

        pq.pop();
    }

    return sortedString;

    
}

int main()
{
    cout << frequencySort("banana") << endl;

    return 0;
}

//////////////////////////////////////////////////////////////////

/*
Problem statement:

Read an integer value and calculate the minimum number of banknotes 
in which the value may be decomposed. 
The possible banknotes are 100, 50, 20, 10, 5, 2 and 1. 
Print the read value and the list of banknotes. 

Input: The input file contains an integer value N (0 < N < 1000000).
Output: Print the read number and the minimum quantity of each necessary banknotes
*/

#include <iostream>
using namespace std;

int main()
{
    int amt;
    cout << "Enter the amount: ";
    cin >> amt;

    // sort banknotes in descending order
    // in order ot prioritize larger banknotes
    // create an integer array with 7 slots
    int banknotes[7] = {100, 50, 20, 10, 5, 2, 1};

    int total_notes = 0;

    for (int i = 0; i < 7; i++) 
    {
        int quant = amt / banknotes[i];
        if(quant > 0)
        {
            cout << quant << "pcs of $" << banknotes[i] << "notes" << endl;
        }
        amt = amt - (quant * banknotes[i]);

        total_notes += quant;
    }

    cout << "minimum number of notes reuiqred: " << total_notes << endl;


    return 0;
}































































































































































































































