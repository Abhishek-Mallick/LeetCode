//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node *result = NULL;
        while(node1!=NULL&&node2!=NULL)
        {
            // comparing values of nodes to determine order of merging
            if(node1->data<=node2->data)
            {
                // merging node1 with the result list
                Node *temp = node1->next;
                node1->next = result;
                result = node1;
    
                // moving to the next node in node1 list
                node1=temp;
            }else{
                // merging node2 with the result list
                Node *temp = node2->next;
                node2->next=result;
                result = node2;
    
                // moving to the next node in node2 list
                node2=temp;
            }
        }
    
        //Check if any list finished first and merge remaining nodes
    
        while(node1!=NULL)
        {
            // merging remaining nodes in node1 list with the result list
            Node *temp = node1->next;
            node1->next = result;
            result= node1;
            node1 = temp;
        }
    
        while(node2!=NULL)
        {
            // merging remaining nodes in node2 list with the result list
            Node *temp = node2->next;
            node2->next = result;
            result = node2;
            node2 = temp;
        }
        // returning the final merged list
        return result;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends