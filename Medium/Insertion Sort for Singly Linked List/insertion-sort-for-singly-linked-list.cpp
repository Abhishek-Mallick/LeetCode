//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




// } Driver Code Ends
//User function Template for C++

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* sortedInsert(struct Node* head_ref, struct Node* new_node)
	{
		struct Node* current;
		/* Special case for the head end */
		if (head_ref == NULL || (head_ref)->data >= new_node->data)
		{
			new_node->next = head_ref;
			head_ref = new_node;
		}
		else
		{
			/* Locate the node before the point of insertion */
			current = head_ref;
			while (current->next != NULL &&
			        current->next->data < new_node->data)
			{
				current = current->next;
			}
			new_node->next = current->next;
			current->next = new_node;
		}

		return head_ref;
	}
    Node* insertionSort(struct Node* head_ref)
    {
        struct Node *sorted = NULL;

		// Traverse the given linked list and insert every
		// node to sorted
		struct Node *current = head_ref;
		while (current != NULL)
		{
			// Store next for next iteration
			struct Node *next = current->next;

			// insert current in sorted linked list
			sorted = sortedInsert(sorted, current);

			// Update current
			current = next;
		}

		// Update head_ref to point to sorted linked list
		head_ref = sorted;
		return head_ref;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int n;
		cin >> n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < n; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

        Solution ob;

		head = ob.insertionSort(head);
		printList(head);

		cout << "\n";



	}
	return 0;
}
// } Driver Code Ends