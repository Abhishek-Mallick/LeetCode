//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void printInorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution
{
public:
void getLeafHeightRecur(Node *node, vector<int> &leaf_height, int pathLen)
    {
        //Base case: If the node is NULL, return.
        if (node == NULL)
            return;
        
        pathLen++; //Increment the path length by 1.
        
        //If the node is a leaf node (i.e., both left and right child are NULL), add the path length to the `leaf_height` vector.
        if (node->left == NULL && node->right == NULL)
        {
            leaf_height.push_back(pathLen);
        }
        //If the node is not a leaf node, recursively call the function on its left and right child.
        else
        {
            getLeafHeightRecur(node->left, leaf_height, pathLen);
            getLeafHeightRecur(node->right, leaf_height, pathLen);
        }
    }
    int getCount(Node *root, int k)
    {
        vector<int> leaf_height;
        //Get the path length to each leaf node by calling the recursive function.
        getLeafHeightRecur(root, leaf_height, 0);
        sort(leaf_height.begin(), leaf_height.end()); //Sort the `leaf_height` vector in non-decreasing order.
        
        int cnt = 0; //Initialize a counter variable to keep track of the number of paths.
        for (int i = 0; i < leaf_height.size(); i++)
        {
            //If subtracting the current path length from `k` results in a negative value, return the count.
            if (k - leaf_height[i] < 0)
                return cnt;
            else
                cnt++; //Increment the counter by 1.
            
            k -= leaf_height[i]; //Subtract the current path length from `k`.
        }
        
        return cnt; //Return the count.
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    scanf("%d", &t);
    cin.ignore();
    while (t--)
    {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        int res = obj.getCount(root, k);
        cout << res << "\n";
    }
    return 0;
}

// } Driver Code Ends