#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set> // Include unordered set to track visited nodes, a set doesn't allow duplicates.
using namespace std;

// Build a graph with adjacency matrix representation 
// The adjacency matrix is just a 2D vector with 0s and 1s

class Graph {
private:

// the total number of vertices
int vertices;

// a 2d vector for a gaphs adjacency matrix
vector<vector<int>> adjMatrix;
    

public:
    // constructor function
    // the constrcutor will be propvided with an integer v, then set vertices to v
    // initialize adjMatric (prefill it with all zeros)
    Graph(int v) : vertices(v), adjMatrix(v, vector<int>(v, 0)) {}
        
    
        
    
    
    
     void printAdjMatrix()
    {
        
    }

    // Breadth First Search
    // A graph traversal function
    void BFS(int start)
    {
        
    }
};


// The Graph's helper function
Graph buildGraph(int v, vector<pair<int, int>> edges, bool isDirected)
{
    
}



int main()
{
    vector<pair<int, int>> edges = { {0,3}, {0,4}, {1,2}, {1,4}, {2,3} };
    int v = 5;
    bool isDirected = false;

    

    return 0;
}


/////////////////////////////

/*

Leetcode 200: Number of Islands
https://leetcode.com/problems/number-of-islands/description/

Strategy:
We model the map with Graph data structure.
Then, traverse the graph with BFS
We count how many connected groups of '1' cells (land) there are in a 2D grid.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int numIslands(vector<vector<char>>& grid)
{
    if(grid.empty()) return 0;

    int rows = grid.size();
    int cols = grid[0].size();
    int numIslands = 0;

    // define direction vector on this order: {up, down, left, right}
    // dr = change in row number (make it moves up and down)
    // dc = change in col number (make it moves left and right)
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    // r = row number, c = col number
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(grid[r][c] == '1')
            {
                numIslands+= 1;

                // conduct BFS from this cell
                // to evaluate he extent of this island
                queue<pair<int, int>> q;

                // push current cell coordinates to the queue
                q.push({r, c});

                // mark current cell as visited
                grid[r][c] = '0';

                //branch out to explore further from current cell
                while(!q.empty())
                {
                    auto [cr, cc] = q.front();
                    q.pop();

                    // try moving in all 4 directions from current cell
                    for(int k = 0; k < 4; k++)
                    {
                        // identify new cooridinates after moving 1 step
                        // nr = new row, nc = new col
                        int nr = cr + dr[k];
                        int nc = cc + dc[k];

                        // each time when we arrive at a new cell 
                        // check whether it is a plot of land within the map


                        // check bounds and if it's land
                        if(grid[nr][nc] == '1' && nr >= 0 && nr < rows && nc >= 0 && nc < cols)
                        {
                            grid[nr][nc] = '0'; // mark new cell visited

                            // enqueue new cell
                            // because it has to branch out to explore further from the new cell later on
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
}



/////////////////////////////////////////////////////////////////////

// Leetcode 733: Flood Fill
// https://leetcode.com/problems/flood-fill/description/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)
{
    // identify the number of rows and cols
    int rows = image.size();
    int cols = image[0].size();

    int oldColor = image[sr][sc];
    if(oldColor == newColor) return image;

    // decalre a queue that stores pixal coords
    queue<pair<int, int>> q;
    q.push({sr, sc});
    image[sr][sc] = newColor;

    // define direction vectors in this order: {UP, DOWN, LEFT, RIGHT}
    // dr = change in row number (make it moves UP and DOWN)
    // dc = change in col number (make it moves LEFT and RIGHT)
    int dr[4] = { -1, 1, 0, 0 };
    int dc[4] = { 0, 0, -1, 1 };

    // BFS search starts
    while(!q.empty())
    {
        // retrieve starting pixel coords from the queue 
        auto[cr, cc] = q.front();
        q.pop();

        // explore in all 4 directions: UP, DOWN, LEFT, RIGHT
        for(int k = 0; k < 4; k++)
        {
            // figure out new coords
            int nr = cr + dr[k];
            int nc = cc + dc[k];

            // every time when we arrive at a new pixel
            // check if it is within the image
            if(nr >= 0 && nr < rows && nc >= 0 && nc < cols)
            {
                // check if the new pixal has the old colour
                if(image[nr][nc] == oldColor)
                {
                    image[nr][nc] = newColor;

                    // enqueue new pixel
                    // because this new pixel has to be explored next
                    q.push({nr, nc});
                }
            }
        }
    }
    return image;
    
}

/////////////////////////////


/*
LeetCode 752 – Open the Lock
https://leetcode.com/problems/open-the-lock/description/

This problem is a classic shortest path in an implicit graph:

1. Each 4-digit lock code = a node
2. Changing one digit up or down = an edge
3. Deadends = blocked nodes
4. BFS finds the minimum number of moves
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

int openLock(vector<string>& deadends, string target)
{
    // store all deadend combinations in a SET to avoid duplicated elements
    unordered_set<string> deadSet(deadends.begin(), deadends.end());

    // if "0000" is found in deadSet
    if(deadSet.count("0000")) return -1;

    // BFS starts here

    // define a queue that stores {4-digit combination, number of moves}
    // a node in the queue is a node that is awaiting to be explored
    queue<pair<string, int>> q;

    // define a SET to keep track of visited combinations
    unordered_set<string> visited;

    q.push({"0000", 0});
    visited.insert("0000");

    while(!q.empty())
    {
        // cc - current combination
        auto[cc, moves] = q.front();
        q.pop();

        if(cc == target) return moves;

        // if cc is not the passcode, then try all 8 other combinations
        // by turning each wheel up or down
        for(int i = 0; i < 4; i++)
        {
            // for each wheel, try turning up and down
        
            string up = cc;
            string down = cc;

            
            // dial upward 1 step
            if(cc[i] == '9')
            {
                up[i] = '0';
            } else 
            {
                up[i] = cc[i] + 1;
            }


            // dial downward 1 step
            if(cc[i] == '0')
            {
                down[i] = '9';
            } else 
            {
                down[i] = cc[i] - 1;
            }

            // check if the new combination is a deadend
            if(!deadSet.count(up) && !visited.count(up))
            {
                visited.insert(up);
                q.push({up, moves + 1});
            }

            if(!deadSet.count(down) && !visited.count(down))
            {
                visited.insert(down);
                q.push({down, moves + 1});
            }
        }
    }

    // if BFS comes to an end without reaching the target
    return -1;
}




int main() {
    // Sample test
    vector<string> deadends = {"0201", "0101", "0102", "1212", "2002"};
    string target = "9999";


    cout << "Minimum moves to unlock: " << openLock(deadends, target) << endl;

    return 0;
}

/////////////////////

// Leetcode 994: Rotting Oranges
// https://leetcode.com/problems/rotting-oranges/description/

// Classic Multi-Source BFS problem
// conduct BFS from multiple nodes at the same time instead of just one

/*
Step by Step Guide
Multi-Source BFS = BFS starting from multiple initial nodes together.

1.  Put all starting positions in queue
2.  Process BFS in layers to correctly simulates parallel expansion
3.  Each layer represents one unit of time/distance
4.  Perfect for simultaneous spreading problems
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int orangeRotting(vector<vector<int>>& grid)
{
    // evaluate grid dimension
    int rows = grid.size();
    int cols = grid[0].size();


    // engage a queu to store all the rotten orange positions
    queue<pair<int, int>> q;

    int freshCount = 0;

    // step 1: locate all rotten oranges
    // and to save their locations in the queue
    for(int r = 0; r < rows; r++)
    {
        for(int c = 0; c < cols; c++)
        {
            if(grid[r][c] == 2)
            {
                q.push({r, c});
            } else if(grid[r][c] == 1)
            {
                freshCount += 1;
            }
        }

        // if it doesnt have a fresh orange
        if(freshCount == 0) return 0;

        // directional vectoes for 4-directional movement
        int dr[4] = { -1, 1, 0, 0 };
        int dc[4] = { 0, 0, -1, 1 };
        int minutes = 0;

        // step2: engage BFA to spread for from all sources simultaneously
        while(!q.empty())
        {
            minutes++;
            int numSources = q.size();

            // this while loop repeats numSources times
            while(numSources--)
            {
                // cr - current row, cc - current col
                auto[cr, cc] = q.front();
                q.pop();

                // a rotten orange spreads rot in all 4 directions
                for(int k = 0; k < 4; k++)
                {
                    int nr = cr + dr[k];
                    int nc = cc + dc[k];

                    // everytime when we arrive at a new cell
                    // check if it's within the grid
                    // check if it has fresh oragne inside
                    if(nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1)
                    {
                        // rot the fresh orange
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }
            
        }
    }

    // if its impossible for all fresh oranges to become rotten
    if (freshCount > 0) return -1; 

    return minutes;
}


// Dijkstra’s algorithm
// Commonly used to find the shortest path between nodes in a weighted graph.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

int main()
{
    // number of placers
    int n = 5;

    unordered_map<string, int> id;

    // map a place name by its index
    id["Changi Airport"] = 0;
    id["Serangoon"] = 1;
    id["Pasir Ris"] = 2;
    id["Bukit Timah"] = 3;
    id["CCK"] = 4;
    id["Sembawang"] = 5;

    // build graph using adjency list: 
    // graph[u {v, distance}
    vector<vector<pair<int, int>>> graph(n);

    // a function that add edges between different places
    auto addEdge = [&](string A, string B, int dist)
    {
        graph[id[A]].push_back({id[B], dist});
    };

    addEdge("Changi Airport", "Serangoon", 4);
    addEdge("Serangoon", "Changi Airport", 4);

    addEdge("Changi Airport", "Pasir Ris", 3);
    addEdge("Pasir Ris", "Changi Airport", 3);

    addEdge("Serangoon", "Pasir Ris", 1);
    addEdge("Pasir Ris", "Serangoon", 1);   

    addEdge("Bukit Timah", "Serangoon", 2);
    addEdge("Serangoon", "Bukit Timah", 2);

    addEdge("Bukit Timah", "Pasir Ris", 4);
    addEdge("Pasir Ris", "Bukit Timah", 4);

    addEdge("CCK", "Pasir Ris", 3);
    addEdge("Pasir Ris", "CCK", 3);

    addEdge("Bukit Timah", "CCK", 2);
    addEdge("CCK", "Bukit Timah", 2);

    addEdge("Bukit Timah", "Sembawang", 1);
    addEdge("Sembawang", "Bukit Timah", 1);

    addEdge("CCK", "Sembawang", 6);
    addEdge("Sembawang", "CCK", 6);


    // Dijlkstra Algortithm 
    string start = "Changi Airport";

    // step1: assume that the starting is infintely from all other places
    //distances -> stores the distances from starting point to all other places
    vector<int> distance(n, INT_MAX);

    // shortest istance between he starting point and the starting point itself must be 0
    distance[id[start]] = 0;

    // min-heap -> prority queue that has to priotize smaller distances
    // it stores (distance, transit node)
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

    pq.push({0, id[start]});

    while (!pq.empty()) {
        // path: "start" > "v" > "w"
        // currDist is the distance between "start" and "v"

        // algotithm: 
        // every node has to take turn to serve as the transit node
        // explore all neighbouring nodes from the transit node

        // in the first repetition, the starting node serves as the transit node
        // which means "start" = "v"

        auto[currDist, v] = pq.top();
        pq.pop();

        // skip taking "v" as the transit node if currDist > distances[v]
        // skip current repetition
        if(currDist > distance[v]) continue;

        // loop throughtall nodes w that are connected to node v (transit node)
        for(auto &[w, weight]: graph[v]) {
            // the path distance start > v > w
            int pathDistance = currDist+ weight;

            if(pathDistance < distance[w]) {
                distance[w] = pathDistance;

                // node w has to beomce the next transit node
                pq.push({pathDistance, w});
            }
        }




    }

}

/*

graph (adjacency list) - a 2D vector

[
    0 [(1, 4), (2, 3)]
    1 [(0, 4), (2, 1), (3, 2)]
    2 [(0, 3), (1, 1), (3, 4), (4, 3)]
    3 [(1, 2), (2, 4), (4, 2), (5, 1)]
    4 [(2, 3), (3, 2), (5, 6)]
    5 [(3, 1), (4, 6)]
]

*/


///////////////////////////////


/*
Leetcode 743: network-delay-time
https://leetcode.com/problems/network-delay-time/

Scenario:
A server sends an update (security patch, configuration, command) to all devices in a network.
Each device = node
Each network link = edge
Transmission latency = weight

Question:
How long will it take before every device receives the update?
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) 
{
    // n - total number of nodes
    // k - source node

    // establish an adjacency list for the graph
    // graph[u] = {v, weight}
    vector<vector<pair<int, int>>> graph(n + 1);

    // loop through [times] vector for data it takes to build the adjacency list (graph)
    for(auto &t : times)
    {
        int u = t[0], v = t[1], w = t[2];
        graph[u].push_back({v, w});
    }

    vector<int> distances(n + 1, INT_MAX);
    distances[k] = 0;

    // k(source node), u(transit node), v(destination node)
    // signal path: k > u > v
    // In Dijktra, every node has to take turn to serve as the transit node
    // in the first iteration, node k also serves as the transit node (k = u)

    // min-heap (a priority queue that has to prioritize smaller numbers)
    // min-heap: {currDist, u}
    // currDist (distance between k and u)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    // in the beginning when we have k = u, currDist = 0
    pq.push({0, k});

    // step 2: visit all direct neighbours of a transit node
    while(!pq.empty())
    {
        auto[currDist, u] = pq.top();
        pq.pop();

        // if a node had previosly served as a transit node, skip it
        if(currDist > distances[u]) continue;

        // loop through all direct neighbours of the transit node u
        for(auto &[v, weight] : graph[u])
        {
            int newDist = currDist + weight;

            if(newDist < distances[v])
            {
                distances[v] = newDist;

                // node v has to wait in the pq to serve as the next transit node u
                // basically, all nodes have to take turn to serve as the transit node
                pq.push({newDist, v});
            }
        }
    }

    // Dijkstra comes to an end when all nodes have taken turn to serve as the transit node

    // find the max of distances vector (minimax problem)
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (distances[i] == INT_MAX) return -1; // unreachable node
        ans = max(ans, distances[i]);
    }
    return ans;
}  





/*
Example 1: 
times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2

how does the graph look like?

graph (adjacency list) - 2D vector

[
    [],                    row 0
    [],                    row 1
    [(1, 1), (3, 1)],      row 2
    [(4, 1)],              row 3
    [],                    row 4
]
*/


// Leetcode 1631. Path With Minimum Effort
// https://leetcode.com/problems/path-with-minimum-effort/description/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;


int minimumEffortPath(vector<vector<int>>& heights)
{
    // evaluate row and column number
    int m = heights.size(), n = heights[0].size();


    // create an m x n effort matrix and set all initial values to positive infinity
    // The 2D vector effort stores the minimum effort required to reach each cell from the starting cell (0,0).

    // It is exactly like the distance array in Dijkstra’s algorithm, 
    // but instead of storing shortest distances, it stores the minimum maximum height differences encountered along the path.
    vector<vector<int>> efforts(m, vector<int>(n, INT_MAX));

    // create a priority queue that prioritizes smaller numbers
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

    // start from the top left cell
    // push to pq {currEffort, row# of a transit node u, col# of a transit node u}

    // consider path: "start" > "u" > "v"
    // currEffort - effort from "start" > "u"
    // starting node first serves as the transit node, "start" = "u", currEffort = 0
    pq.push({0, 0, 0});
    efforts[0][0] = 0;

    // directional vector
    // UP, DOWN, LEFT, RIGHT
    vector<pair<int, int>> directions = {
        {-1, 0},
        {1, 0},
        {0, -1},
        {0, 1},
    };

    // Dijkstra starts
    while(!pq.empty()) {
        // step1: elect a node as a transit node
        auto top = pq.top();

        int currEffort = top[0]; // effort required to travel from k > u 
        int ux = top[1]; // current transit node's x coordinate
        int uy = top[2]; // current transit node's y coordinate

        // step2: visit all transit node's direct neighbours
        // by moving UP, DOWN, LEFT, RIGHT
        for(auto [dx, dy] : directions)
        {

            // identift the x and y coordinates of destination node v 
            int vx = ux + dx;
            int vy = uy + dy;

            // only consider node v within bound

        }



    }

    
    
}




