//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return (node);
}

Node* buildTree(string str)
{
	// Corner Case
	if (str.length() == 0 || str[0] == 'N')
		return NULL;

	// Creating vector of strings from input
	// string after spliting by space
	vector<string> ip;

	istringstream iss(str);
	for (string str; iss >> str; )
		ip.push_back(str);

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
		if (i >= ip.size())
			break;
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
//User function Template for C++

/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution
{
    public:
    int countinchild(Node* root)
    {
        // as node exists.
        if (root == NULL)
            return 0;

        int numberofnodes = 0; // to count total nodes.
        int sum = 0; // to count total candies present.

        queue<Node*> q;
        q.push(root);

        while (q.size() != 0) {
            Node* f = q.front();
            q.pop();

            numberofnodes++;
            sum += f->key;

            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }

        // as either less than 0 or greater, it will be
        // counted as move as explained in the approach.

        return abs(numberofnodes - sum);
    }

    int distributeCandy(Node* root)
    {
        int moves = 0;

        // as 0 node and 0 value.
        if (root == NULL)
            return 0;

        // as leaf node don't have to pass any candies.
        if (!root->left && !root->right)
            return 0;

        // queue to iterate on tree .
        queue<Node*> q;
        q.push(root);

        while (q.size() != 0) {
            Node* f = q.front();
            q.pop();

            // total pass from left child
            moves += countinchild(f->left);
            // total pass from right child
            moves += countinchild(f->right);

            if (f->left)
                q.push(f->left);
            if (f->right)
                q.push(f->right);
        }

        return moves;
    }
};

//{ Driver Code Starts.
int main() {

	int t;
	cin >> t;
	getchar();

	while (t--)
	{

		string str;
		getline(cin, str);

		Node *root = buildTree(str);
		Solution ob;
		cout << ob.distributeCandy(root) << "\n";

	}

	return 0;
}

// } Driver Code Ends