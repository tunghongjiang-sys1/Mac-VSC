////////////////////////////////////////////////////////////
// Singly Linked List with Append and Insert at Position
////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

struct Node 
{
    string data;
    Node * next;

    // constructor
    // to initialize data as input
    // to initialize next ptr as null 
    Node (const string& input) : data(input), next(nullptr) {}
};


class LinkedList 
{
private:
    Node * head;

public:
    // constructor
    // to initialize head ptr as null
    LinkedList() : head(nullptr) {}

    void append(const string& input)
    {
        // create a new Node
        // set newNode ptr to point to the newly created node
        Node * newNode = new Node(input);

        // check if the linked list is currently empty
        if(head == nullptr)
        {
            // set head ptr to point to the same node that newNode ptr is pointing at
            head = newNode;
        
        } else
        {
            // else if it is not empty
            // traverse the linked list to get to the destination where the new node has to be added
            
            // Declare current ptr and set it to point to the same node head ptr is pointing at
            Node * current;
            current = head;

            // move current ptr to point to the same node the next ptr of the current node is pointing at
            // while the next ptr of the current node is not pointing to null, keep shifting current ptr
            while(current -> next != nullptr)
            {
                current = current -> next;
            }

            current -> next = newNode;
        }  
    }

    void DisplayNodesData()
    {
        Node * current;
        current = head;

        while(current != nullptr)
        {
            cout << current -> data << endl;
            current = current -> next;
        }
    }

    void InsertNodeAtPos(const string& NodeData, int pos)
    {
        // create a new Node
        // create a new ptr called NewNode and set it to point to the just created node
        Node * NewNode = new Node(NodeData);

        // if the list is currently empty or pos is 0
        // add the new node to the forefront position
        if(head == nullptr || pos == 0)
        {
            NewNode -> next = head;
            head = NewNode;   
            return;
        }

        // if it is some other positions,
        // we will have to traverse the list to get to where the node has to be inserted
        Node * current;
        current = head;
        int index = 0;

        while(index < pos - 1 && current->next != nullptr)
        {
            current = current -> next;
            index++;
        }

        // Once the location is identified, insert the new node
        NewNode -> next = current ->  next;
        current -> next = NewNode;        
    }
};


int main()
{   
    LinkedList LL;
    LL.append("make a sandwich");
    LL.append("make another sandwich");
    LL.append("Eat all the sandwiches");
    LL.append("pour a glass of milk");

    LL.DisplayNodesData();

    cout << endl;

    LL.InsertNodeAtPos("purchase a ticket to lady gaga's concert", 2);
    LL.DisplayNodesData();

    return 0;
}


////////////////////////////////////////////////////////////
// Circular Linked List + Josephus Problem
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

struct NodeInt {
    int data;
    NodeInt * next;

    // Constructor
    NodeInt(int val) : data(val), next(nullptr) {}
};


// Function to build a circular linked list
// The function has to return the head ptr of a circular linked list
// n = number of nodes
NodeInt * CircularLinkedList(int n)
{
    // create a new node ptr called head
    // Set head to point to a new node that holds an integer 1
    NodeInt * head = new NodeInt(1);

    NodeInt * current = head;

    for(int i = 2; i <= n; i++)
    {
        current -> next = new NodeInt(i);
        current = current -> next;
    }
 
    // last node's next ptr has to return to point to the first node
    current -> next = head;

    return head;
}


// Function to solve Josephus problem with sample size n, and step k
int Josephus(int n, int k)
{
    // declare a circular linked list to begin with
    NodeInt * head = CircularLinkedList(n);
    NodeInt * prev = nullptr;
    NodeInt * current = head;
    
    // the while loop repeats for as long as it has more than 1 node in the circular linked list
    while(current -> next != current)
    {
        // move k-1 steps forward
        for(int count = 1; count < k; count++)
        {
            prev = current;
            current = current -> next;
        }

        // Remove the k-th node
        prev -> next = current -> next;
        cout << "Player " << current -> data << " is eliminated." << endl;
        delete current;

        current = prev -> next;
    }

    // identify current node (last node remaining)
    int survivor = current -> data;
    delete current;
    return survivor;
}


int main()
{
    int n, k;

    cout << "Enter the number of players(n): ";
    cin >> n;

    cout << "Enter the step count(k): ";
    cin >> k;

    int survivor_number = Josephus(n, k);
    cout << "The last man standing is player " << survivor_number << endl;

    return 0;
}


////////////////////////////////////////////////////////////
// Doubly Linked List
////////////////////////////////////////////////////////////

#include <iostream>
using namespace std; 

class NodeDLL 
{
public:
    int data;
    NodeDLL * prev;
    NodeDLL * next;

    // Constructor function
    NodeDLL(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
public:
    NodeDLL * head;
    NodeDLL * tail;
    int size;

    // Constructor function
    DoublyLinkedList()
    {
        head =  nullptr;
        tail =  nullptr;
        size = 0;
    }

    // Function that inserts a node at any given position
    void InsertNodeAtPos(int data, int position)
    {
        if (position < 0 || position > size)
        {
            cout << "Invalid position" << endl;
            return; 
        }
    
        NodeDLL * NewNode = new NodeDLL(data);

        // If a new node has to be inserted as the head node
        if(position == 0)
        {
            NewNode -> next = head;
            if(head) head -> prev = NewNode;
            head = NewNode;
            if(tail == nullptr) tail = NewNode;
        } 
        else
        {
            // Traverse the linked list to get the position
            NodeDLL * current = head;

            for(int i = 0; i < position - 1; i++)
            {
                current = current -> next;
            }
            
            NewNode -> next = current -> next;
            NewNode -> prev = current;
            if(current -> next) current -> next -> prev = NewNode;
            current -> next = NewNode;

            if(NewNode -> next == nullptr) tail = NewNode;                
        }   
        size++;
    }
};


////////////////////////////////////////////////////////////
// LRU Cache using Doubly Linked List + Hash Map
////////////////////////////////////////////////////////////

#include <iostream>
#include <unordered_map>
using namespace std;

struct NodeLRU {
    int key;
    int value;
    NodeLRU * prev;
    NodeLRU * next;

    // Constructor
    NodeLRU(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};

class LRUCache 
{
private:
    unordered_map<int, NodeLRU*> cache;

    NodeLRU * head;
    NodeLRU * tail;
    int capacity;

    void RemoveNode(NodeLRU * node)
    {
        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
    }

    void AddToHead(NodeLRU * node)
    {
        node -> next = head -> next;
        node -> prev = head;
        head -> next -> prev = node;
        head -> next = node;
    }

    void MoveToHead(NodeLRU * node)
    {
        RemoveNode(node);
        AddToHead(node);
    }

public:
    //constructor function
    LRUCache(int c) : capacity(c)
    {
        head = new NodeLRU(-1, -1);
        tail = new NodeLRU(-1, -1);
        head -> next = tail;
        tail -> prev = head;
    }

    int get(int key)
    {
        if(cache.find(key) == cache.end())
            return -1;

        NodeLRU* node = cache[key];
        MoveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if(cache.find(key) != cache.end())
        {
            NodeLRU * node = cache[key];
            node -> value = value;
            MoveToHead(node);
        }
        else
        {
            if(cache.size() == capacity)
            {
                NodeLRU * lru = tail->prev;
                cache.erase(lru->key);
                RemoveNode(lru);
                delete lru;
            }

            NodeLRU * newNode = new NodeLRU(key, value);
            cache[key] = newNode;
            AddToHead(newNode);
        }
    }
};
