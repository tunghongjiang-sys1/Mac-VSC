#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

void maxPathSum(Node* node,
                int currentSum,
                int& maxSum,
                vector<int>& currentPath,
                vector<int>& maxPath) {
    if (node == NULL) return;

    currentSum += node->data;
    currentPath.push_back(node->data);

    if (node->left == NULL && node->right == NULL) {
        if (currentSum > maxSum) {
            maxSum = currentSum;
            maxPath = currentPath;
        }
    }

    maxPathSum(node->left, currentSum, maxSum, currentPath, maxPath);
    maxPathSum(node->right, currentSum, maxSum, currentPath, maxPath);

    currentPath.pop_back(); // backtrack
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(9);

    int maxSum = INT_MIN;
    vector<int> currentPath, maxPath;

    maxPathSum(root, 0, maxSum, currentPath, maxPath);

    cout << "Maximum Path Sum: " << maxSum << endl;
    cout << "Path: ";
    for (int val : maxPath)
        cout << val << " ";

    return 0;
}