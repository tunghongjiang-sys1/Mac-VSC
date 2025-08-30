// DP Problems needs a DP table

// 0-1 Knapsack Problem

#include <iostream>
#include <vector>
using namespace std;

// C - Capacity
// N - Number of items
int knapsack(int C, const vector<int>& weights, const vector<int>& values, int N)
{
    // make a DP table (2D vectors) with (N+1) rows and (C+1) columns
    vector<vector<int>> DP(N+1, vector<int>(C+1, 0));

    // Iterate all rows
    for(int i = 1; i < N+1; i++)
    {
        for(int j = 1; j < C+1; j++)
        {
          // if current gem i can fit into the current knapsack with capcity  
          if(weights[i-1] <= j)
          {
            int pwgi = values[i-1] + DP[i-1][j-weights[i-1]j-weight[i-1]];
            int pwogi = DP[i-1][j];
            DP[i][j]= max(pwgi, pwogi);
          } else
          {
            DP[i][j] = DP[i-1][j];
          }
        }
    }
  return DP[N][C];
    }

int main()
{
    int C = 5;
    vector<int> weights = {5, 3, 4, 2};
    vector<int> values = {60, 50, 70, 30};
    int N = weights.size();

    cout << "Maximum achievable value in the knapsack: " <<  knapsack(C, weights, values, N) << endl;


  /////////////////////////////////////////////////

  /*
Question: Climbing Stairs

Problem Statement:
You are climbing a staircase.
It takes n steps to reach the top.

Each time you can either climb 1 step or 2 steps.

In how many distinct ways can you climb to the top?
*/

#include <iostream>                    
#include <vector>                       
using namespace std;                 

long long climbStairs(int n) {
    // creates a dp table with 1 row and n+1 columns
    vector<long long> dp(n+1, 0); 

    // there's exactly 1 way to get to step 0 and step 1   
    dp[0] = 1;
    dp[1] = 1;

    // from solt 2 onwards
    // fill each slot with a value = sum of previous tow slots
    for (int i = 2; i <= n; i++)
    {
      dp[i] = dp[i-1] + dp[i-2];
      
    }
  
    return dp[n];
    
}

int main() {
    int n;
    cout << "Enter number of stairs: ";
    cin >> n;
    cout << "Number of ways to climb: " << climbStairs(n) << endl;
    return 0;
}


////////////////////////////////////

/*
Question: Unique Paths (Robot in Grid) Porblem Statment
A robot is located at the top-left corner of an m x n grid. It can only move down or right at any point
Find the number of unique paths from the top-left corner to the bottom-right corner 
*/


#include <iostream>
#include <vector>
using namespace std;

// m - number of rows
// n - number of columms 
long long uniquePaths(int m , int n)
{
    vector<vector<long>> dp(m, vector<long long>(n-1)); //Initialize all with 1s

    
    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            
            // fill each slot with the sum f its top and left cell's value
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
}


int main()
{
    int m = 3, n = 7;
    cout << "Number of unique paths: " << uniquePaths(m, n) << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate number of unique paths
long long uniquePaths(int m, int n)
{
    vector<vector<long long>> dp(m, vector<long long>(n, 1));  // Initialize first row & column with 1

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            // Fill each cell with the sum of its top and left cell's value
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];  // Return the bottom-right cell
}

int main()
{
    int m, n;
    cout << "Enter number of rows (m): ";
    cin >> m;

    cout << "Enter number of columns (n): ";
    cin >> n;

    if (m <= 0 || n <= 0) {
        cout << "Please enter positive integers for both m and n." << endl;
        return 1;
    }

    cout << "Number of unique paths: " << uniquePaths(m, n) << endl;
    return 0;
}

////////////////////////////////////


// Total unique ways to make change

#include <iostream>
#include <vector>

using namespace std;

int countWaysToMakeChange(vector<int>& coins, int m, int n) {

    // create a 2D (m + 1) x (n + 1) DP table
    // m - the number of denominations
    // n - amount
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // fill the first column with zeros
    // because there's just one way to make change for amount 0
    // that is to take no coins at all

    for(int i = 0; i <= m; i++)
    {
        // iterate all columns
        for(int j = 1; j <= n; j++)   
        {
            // total ways to make change is the sum of the following:
            // 1. total ways to make change when current coin is NOT included
            // 2. total ways to make change when current coin is allowed to be included

            // calculate point 1
            dp[i][j] = dp[i-1][j];

            // calculate point 2:
            // if the coin value is less then the amount j, then we're allowed to take it
            // i - row number
            // j - column number
            if(coins[i-1] <= j)
            {
                dp[i][j] = dp[i][j] + dp[i][j-coins[i-1]];
            }
        }
        
    }

    return dp[m][n]

    // fill the dp table from slot (1, 1) onwards with a dp relation
}

int main() {
    vector<int> coins = {1, 2, 5};
    int m = coins.size();
    int n = 5;
    cout << "Total unique ways to make change for " << n << " is: " << countWaysToMakeChange(coins, m, n) << endl;
    return 0;
}




/////////////////////////////////


// LeetCode 198. House Robber
// https://leetcode.com/problems/house-robber/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rob(vector<int>& nums)
{
    // calculate the total number of houses
    int N = nums.size();

    if(N == 0) return 0;
    if(N == 1) return nums[0];

    // create a 1d dp table with N slots
    // it has to keep a record of the max profit when you rob up to house i
    vector<int> dp(N, 0);

    // base cases
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    // for each house from house i = 2 onwards, there're two options to consider:
    // 1. to skip it?
    // 2. to rob it?

    for(int i = 2; i < N; i++)
    {   
        // if you skip the current house i, then you can rob up to the previous house i - 1
        int skip_profit = dp[i - 1];

        // if you rob the current house i, then you can rob up to the previous two house i - 2 
        int rob_profit = nums[i] + dp[i - 2];
        dp[i] = max(skip_profit, rob_profit);
    }

    return dp[N - 1];    
}


int main()
{
    vector<int> nums = {1, 9, 1, 1, 9, 1};

    cout << "Max money we can rob: " << rob(nums) << endl;

    return 0;
}

//////////////////////////////////

// https://leetcode.com/problems/house-robber-iii/description/

#include <iostream>
#include <utility>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 


// Define a helper function that returns a pair of values [a, b] for each subtree
// a - max money from a subtree if the current root node is robbed
// a: root value + previous value b
// b: max value of previous a and b
// b - max money from a subtree if its root node is NOT robbed
pair<int, int> robSubtree(TreeNode* node) {
    // if it hits a null node, stop recursion
    if (!node)
        return {0, 0};
    
    // do recursion to fidn the max profit in the left subtree
    // calculate the max profit that can be generated from a left subtree
    
    // left - a set of [a, b] from the previous left subtree
    pair<int, int> left = robSubtree(node->left);
    
    // right - a set of [a, b] from the previos right subtree
    pair<int, int> right = robSubtree(node->right);
    
    // profit of a subtree when its root node is robbed
    int a = node->val + left.second + right.second;
    
    // profit of a subtree when its root node is NOT robbed
    int b = max(left.first, left.second) + max(right.first, right.second);
    
    return {a, b};
}


// max profit when we consider the entire tree
int rob(TreeNode* node) {
    // final - the [a, b] of the entire tree
    pair<int, int> final = robSubtree(node);
    
    return max(final.first, final.second);
}



int main() {

    // Example usage
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(20);
    root -> right = new TreeNode(4);
    root -> left -> left = new TreeNode(100);
    root -> right -> right = new TreeNode(1);


    return 0;
}



//////////////////

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
// Leetcode 121. Best Time to Buy and Sell Stock
// Only 1 transaction can be made
// in analogy to a long term investor

#include <vector>
#include <iostream>
using namespace std;

int maxProfit(vector<int>& prices)
{
    // total nunber of trading days
    int N = prices.size();

    // Ultimate Question: Over a period of N days, what the max profit you can make

    //create a 1d DP table
    // which has to keep a record of max profit that can be made up to day i
    // i - day number

    vector<int> dp(N, 0);

    // no profit can be made if there's jsut 1 day to trade up to
    // we are only allowed to sell teh stock on a different day in the future
    dp[0] = 0

    // first assume that the stock was bought on day 0
    int BuyPrice = prices[0]

    for(int i = 1; i < N; i++)
    {
        // on each day, we can choose:
        // 1. to hold the stock
        // if you hold the stock, the max profit that you can make up to day i is just the same as the max profit that you can make up to day i-1
        int holdprofit = ;
        // 2. to sell it for a profit
        int sellprofit = prices[i] - BuyPrice;

    }
    
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
}


////////////////////////////////////////

// LeetCode 122 — Unlimited Transactions
// Real-world analogy - Active daily trader
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/description/

/*
    What Does the DP Table Store?
    We're using a 2D DP table dp[i][j], where:

    i = day index (0 to n - 1)

    j = 0 means we do not hold a stock on day i

    j = 1 means we do hold a stock on day i
*/

#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    // total number of trading days
    int N = prices.size()

    // define an Nx2 dp table
    // ultimate question: what's the max profit that can be made from a total of N
    // DP breaks it into smaller sub problems
    // 1. whats the max profit that can be made on day 0?
    // 2. whats the max profit that can be made on day 1?
    // 3. whats the max profit that can be made on day 2? 
    // ...

    // the table has to track teh best profit up to a certain day i with / without the stock
    vector<vector<int>> dp(N, vector<int>(2, 0));

    // prefill the table with initial values
    dp[0][0] = 0;
    dp[0][1] = -pricses[0] v// spending = negative profit

    // interate and fill the dp table wiuth a loop (i - row number)
    for(int i = 1; i < N; i++)
    {
        // we will have to make a desicions each day 
        // 1. to hold the stock until the end of day i
        // There's 2 scenarios that can lead to holding the stock until teh edn of day i
        // Scenario 1: REPURCHASE the stcok on day1
        // Scenario 2: continue holding the stock we previously bought

        // 2. to NOT hold the stock until the end of day i
        
    }
    // The profit that can be made up to day 0 without holding the stock by the end of day 0
    // The max profit that can be made up to day 0 while holding the stock by the end of day 0
    // if (0, 0) = 0, cos of: 1. DO NOT TRADE AT ALL; 2. BUY AND SELL ON THE SAME DAY 
    
    
    
}

/*
dp[0][0]:
What's the profit that can be made up to day 0, 
without holding the stock by the end of of day 0

What are two scenarios that can lead to
Not having the stock by the end of day 0?

1. DO NOT TRADE AT ALL (profit 0)
2. BUY AND SELL on the same day 0 (profit 0)

dp[0][1]:
max profit that can be made up to day 0,
WITH the stock in the account by the end of day 0

What's the scenario that can lead to having
the stock in the account by the end of day 0?
1. BUY THE STOCK and HOLD IT
*/

int main() {
    vector<int> prices = {7,1,5,3,6,4};
}




