/*

Backtracking is systematically trying all possibilities, and undoing choices when they don’t work.

Think of it as:
Choose → Explore → Undo
It’s usually implemented using recursion.

Standard structure:
void backtrack(parameters) {
    if (base_case) {
        // process solution
        return;
    }

    for (each choice) {
        // choose
        make_choice();

        // explore
        backtrack(updated_parameters);

        // undo (backtrack)
        undo_choice();
    }
}

When To Recognize Backtracking Problems - Look for:
“Generate all…”
“Find all possible…”
“Count ways…”
“Place items under constraints…”
Small input size (n ≤ 20)

*/

/*
Decision Tree for Leetcode 78: Subsets

[]
|____ [1]
|      |____[1, 2]
|      |       |____[1, 2, 3]
|      |
|      |____[1, 3]
|    
|_____ [2]    
|       |____[2, 3]
|       
|______[3]

Here's how the algorithm explores the decision tree:
[]
-> [1]
-> [1, 2]
-> [1, 2, 3]
backtrack
-> [1, 3]
backtrack
-> [2]
-> [2, 3]
backtrack
-> [3]
*/

// Solve by DFS Recursion (Backtracking)

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> current;
    vector<vector<int>> result;

    void explore(vector<int> nums, int index)
    {
       result.push_back(current);

        // explore all paths with a for loop
        for(int i = index; i < nums.size(); i++)
        {
            // step1: pick a path
            current.push_back(nums[i]);

            // step2: explore deeper into the path byrecursively getting the function to call itself with the next ndex (index +1)
            explore(nums, i + 1);

            // step3: backtrack if the path hits a dead end

            current.pop_back();
        }
    }
};

