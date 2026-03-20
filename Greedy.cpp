// Two common approaches to solving an optimization problem
// 1. Dynamic Programming
// 2. Greedy Method

/*
The Greedy method, focuses on making the best choice at each step.

In every single decision you make, you pick the most rewarding option (that best choice you can choose from right now), 
with a faith that this bast choice that you now make will eventually add up to the best overall outcome. 
*/

// Leetcode 435: Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/description/
/*
Why This is Greedy

Greedy choice property:
By picking the interval that ends earliest, you leave the maximum possible room for future intervals.
*/

// step1: sort all intervals by their end time in ascending order
// step2: protize tasks that end eairliest


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// build a custom data structure for the time interval
struct Interval
{
    int start, end;
};

// helper comparator function (sort by end time)
bool compare(Interval a, Interval b)
{
    return a.end < b.end;
}

int MaxNonOverlappingIntervals(vector<Interval>& intervals)
{
    // base case
    if (intervals.empty()) return 0;

    // sort intervals by end time
    sort(intervals.begin(), intervals.end(), compare);

    int count = 0;
    int lastEndTime = -1;   // end time of last selected interval

    // greedy selection
    for (Interval i : intervals)
    {
        // select interval if it does not overlap
        if (i.start >= lastEndTime)
        {
            count++;
            lastEndTime = i.end;
        }
    }

    return count;
}


/////////////////////////////////////

/*
Problem:
Given the arrival and departure times of trains at a station, 
find the minimum number of platforms required so that no train waits.

Approach:
The idea is to check at any point in time how many trains are at the station. 
A platform is needed when a train arrives and overlaps with a train that has not yet departed.

Greedy Solution:
1. Sort the arrival and departure times.

2. Use two pointers (one for arrivals and one for departures)
   to track the number of platforms needed at any given time.

3. Every time a train arrives, check if a platform is available 
   (i.e., a previous train has departed). If not, increase the number of platforms.
*/

/*
Example Walkthrough

Arrivals: {900, 930, 940, 950, 1100}
Departures: {910, 1200, 1120, 1130, 1205}

Step by step:

| Time | Event     | `platform_needed` | `max_platforms` |
| ---- | --------- | ----------------- | --------------- |
| 900  | Arrival   | 1                 | 1               |
| 910  | Departure | 0                 | 1               |
| 930  | Arrival   | 1                 | 1               |
| 940  | Arrival   | 2                 | 2               |
| 950  | Arrival   | 3                 | 3 ✅ peak        |
| 1100 | Arrival   | 4                 | 4 ✅ peak        |
| 1120 | Departure | 3                 | 4               |
| 1130 | Departure | 2                 | 4               |
| 1200 | Departure | 1                 | 4               |
| 1205 | Departure | 0                 | 4               |

platform_needed = how many trains are parked right now.
max_platforms = the maximum trains parked simultaneously during the whole day

The greedy choice is:
Always process the earliest of the next arrival or the next departure (the most urgent event)
If the next earliest event is an arrival, increment platform_needed.
If it’s a departure, decrement platform_needed.

Local Decision: At each step, we choose whichever comes earlier in time — arrival or departure.
→ That’s the greedy choice: “serve the earliest event first.”
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinPlatform(vector<int>& arrivals, vector<int>&  departures)
{

    // identify the number of arrival and departure events
    int a = arrivals.size();
    int d = departures.size();
    int platform_needed = 0, max_platforms = 0;

    // sort both arrivals and departures in chronological order
    // which makes it priortise earlier events when we traverse the vectors

    sort(arrivals.begin(), arrivals.end());
    sort(departures.begin(), departures.end());

    // traverse both arrivals and departures vectors concurrently
    // using the TWO-POINTERS approach
    // i - used to iterate arrivals vector
    // j - used to iterate departures vector

    // Two-pointer approach is used when we want to access different elements in 2 seperate vectors


    int i = 0; 
    int j = 0; 

    // traverse through all arrival and departure times
    while (i < a && j < d)
    {
        // when a train arrives before an idling train departs, a new platform is needed
        if (arrivals[i] <= departures[j])
        {
            platform_needed += 1;
            // to mvoe on to the next arrival event
            i += 1;
        }
        else {
            // when a train departs before a new train arrives, a platform will free  up
            platform_needed -= 1;
            // to move on to the next departure event
            j += 1;
        }

        // Whenever platform_needed breaks its previous records
        // Set max_platform to platform_needed
        max_platforms = max(max_platforms, platform_needed);
    }

    return max_platforms;
}

int main() {
    // Example input: Train arrival and departure times
    vector<int> arrivals = {900, 930, 940, 950, 1100};
    vector<int> departures = {910, 1200, 1120, 1130, 1205};
 
    int result = findMinPlatform(arrivals, departures);
    cout << "Minimum number of platforms required: " << result << endl;
 
    return 0;
 }


 ///////////////////////////////////////

 // LeetCode 1710 – Maximum Units on a Truck.
// https://leetcode.com/problems/maximum-units-on-a-truck/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Strategy:
The best strategy here is Greedy, 
where we try to load the boxes with the highest units first. 
This will help maximize the total number of units.

Steps:
1. Sort the box types by the number of units per box in descending order.

2. Iterate through the sorted list and load as many boxes as possible until 
the truck reaches its capacity.

3. If we can't load all boxes of a type (because the truck is nearing capacity), 
we load only as many as the truck can still carry.

boxTypes = {{1, 3}, {2, 2}, {3, 1}};. truckSize = 4

since boxTypes comes with 3 baby vectors, it means it has 3 different types of boxes to work with

Type 1 box comes with baby vector [1, 3]:
1 says we have just one Type 1 box
3 days each Type 1 box carries 3 units of items inside

Type 2 box comes with baby vector [2, 2]:
2 says we have 2 Type 2 boxes
2 days each Type 2 box carries 2 units of items inside

Type 3 box comes with baby vector [3, 1]:
3 says we have 3 Type 3 boxes
1 days each Type 3 box carries 1 unit of items inside

*/

int maxUnits(vector<vector<int>>& boxTypes, int truckSize) {
    // Sort boxTypes by number of units per box in descending order
    sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[1] > b[1];
    });

    int totalUnits = 0;

    // Iterate through the sorted box types
    for (vector<int>& box : boxTypes) {
        int BoxCount = box[0];
        int unitsPerBox = box[1];

        // How many boxes of such type of box do we load?
        int boxToLoad = min(truckSize, BoxCount);

        truckSize -= boxToLoad;

        totalUnits += boxToLoad * unitsPerBox;

        // Stop loading when the truck is full
        if (truckSize == 0) break;
    }

    return totalUnits;
}

int main() {
    vector<vector<int>> boxTypes = {{1, 3}, {2, 2}, {3, 1}};
    int truckSize = 4;

    cout << "Maximum units that canbe loaded onto the truck " << maxUnits(boxTypes, truckSize) << endl;

    return 0;
}


//////////////////////////////

// Fractional Knapsack Problem

/*
The fractional knapsack problem is a variation of the 
classic 0/1 knapsack problem where you are allowed to 
take fractional parts of the items. 

In the 0/1 knapsack problem, you can either take the
whole item or leave it, but in the fractional version, 
you can take fractions of the item if needed.


Explanation:

Input:
1. W: Total weight capacity of the knapsack.
2. weights[]: Array containing the weights of the items.
3. values[]: Array containing the values of the items.
4. n: Number of items.


Process: GREEDY APPROACH
1. We calculate the value-to-weight ratio for each item.

2. We sort the items based on this ratio in descending order.

3. We start filling the knapsack by adding as much 
highest value-to-weight ratio item as possible.

4. If an item cannot fully fit into the knapsack, 
we add as much as possible (fractional part) to maximize the value.


Output: 
The maximum value that can be obtained by optimally filling the knapsack.
*/



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 


double fractionalKnapsack(int capcity, vector<int> weights, vector<int> values, int N)
{
    // declare the value-weight ratio vector
    vector<pair<double, int>> ratio(N);

    // calculate value-weight ratio for 
    for(int i = 0; i < N; i++)
    {
        ratio[i] =  { (double) values[i] / weights[i], i};
    }

    // sort ratio vector by ration values in descending order
    sort(ratio.begin(), ratio.end(), [](pair<double, int> a, pair<double, int> b) {
        return a.first > b.first;
    });

    int currentWeight = 0;
    double currentValue = 0.0;

    // hoes does ratio vector look like
    // { (6.0, 0), (5.0, 1), (4.0, 2) }

    // iterate the sorted ratio vector
    for(int i = 0; i < N; i++)
    {
        int item_number = ratio[i].second;

        // start with the most precious item (highest v-w ratio)
        // if the whole item can fit in the knapsack, take it all
        if(currentWeight + weights[item_number] <= capcity)
        {
            currentWeight += weights[item_number];
            currentValue += values[item_number];
        }
        else
        {
            // take the fraction of an item if it cannot fit entirely into the knapsack
            int remain = capcity - currentWeight;

            // the value of a fractional part of an item
            int fractionalValue = ((double) remain / weights[item_number]) * values[item_number];

            currentValue += fractionalValue;

            // since the knapsakc is already fully filled, quit the loop
            break;
        }
    }

    return currentValue;

}

int main() {

    int N = 3;
    int capacity = 50;

    vector<int> weights = {10, 20, 30};
    vector<int> values = {60, 100, 120};

    cout << fractionalKnapsack(capacity, weights, values, N) << endl;
    
    return 0;
}