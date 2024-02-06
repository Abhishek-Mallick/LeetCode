//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    int findLevel(Node *root, int k, int level) {
    if (root == NULL) return -1;
    if (root->data == k) return level;
    // Recursively call the function on the left child with increased level
    int l = findLevel(root->left, k, level + 1);
    // If the node is found on the left side, return its level
    // Otherwise, continue searching on the right child
    return (l != -1) ? l : findLevel(root->right, k, level + 1);
}

// Function to find the lowest common ancestor of two nodes and the distance between the two nodes
Node *findDistU(Node *root, int a, int b, int &d1, int &d2, int &dist, int lvl) {
    if (root == NULL) return NULL;
    if (root->data == a) {
        // If the first node is found, store its level and return the node
        d1 = lvl;
        return root;
    }
    if (root->data == b) {
        // If the second node is found, store its level and return the node
        d2 = lvl;
        return root;
    }

    // Recursively call the function on the left and right children
    Node *l = findDistU(root->left, a, b, d1, d2, dist, lvl + 1);
    Node *r = findDistU(root->right, a, b, d1, d2, dist, lvl + 1);

    if (l and r) {
        // If both nodes are found on different subtrees, calculate the distance
        dist = d1 + d2 - 2 * lvl;
    }
    // Return the node found or NULL if not found
    return (l != NULL) ? l : r;
}


    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        int d1 = -1, d2 = -1, dist;
    // Find the lowest common ancestor of the two nodes and calculate the distance
    Node *lca = findDistU(root, a, b, d1, d2, dist, 1);
    if (d1 != -1 and d2 != -1) {
        // If both nodes are found, return the distance between them
        return dist;
    }

    if (d1 != -1) {
        // If only the first node is found, find its distance to the second node
        dist = findLevel(lca, b, 0);
        return dist;
    }
    if (d2 != -1) {
        // If only the second node is found, find its distance to the first node
        dist = findLevel(lca, a, 0);
        return dist;
    }
    // Return -1 if both nodes are not found
    return -1;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends