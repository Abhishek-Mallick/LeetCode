//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    void printList(Node* n) {
        while (n) {
            cout << n->data;
            n = n->next;
        }
        cout << endl;
    }
    
    int length(Node* n) {
        int ret = 0;
        while (n) {
            ret++;
            n = n->next;
        }
        return ret;
    }

    Node* reverse(Node* head) {
        Node* prev =  NULL;
        Node* current = head;
        Node* next =  NULL;

        while (current !=  NULL) {
            next = current->next; // storing next node
            current->next = prev; // linking current node to previous
            prev = current; // updating prev
            current = next; // updating current
        }

        return prev;
    }

    Node* subLinkedList(Node* l1, Node* l2) {
        
        while (l1 !=  NULL && l1->data == 0) {
            l1 = l1->next;
            // removing trailing zeroes from l1
        }

        while (l2 !=  NULL && l2->data == 0) {
            l2 = l2->next;
            // removing trailing zeroes from l2
        }

        int n1 = length(l1);
        int n2 = length(l2);

        if (n1 == 0 && n2 == 0) {
            return new Node(0);
        }

        if (n2 > n1) {
            std::swap(l1, l2);
            // making sure l1 list has the bigger number
        }

        if (n1 == n2) {
            Node* t1 = l1;
            Node* t2 = l2;
            while (t1->data == t2->data) {
                // finding which number is greater
                t1 = t1->next;
                t2 = t2->next;

                if (t1 ==  NULL) {
                    return new Node(0);
                    // returning zero if both numbers are same
                }
            }

            if (t2->data > t1->data) {
                std::swap(l1, l2);
                // making sure l1 list has the bigger number
            }
        }

        l1 = reverse(l1);
        l2 = reverse(l2);

        Node* res =  NULL;
        Node* t1 = l1;
        Node* t2 = l2;

        while (t1 !=  NULL) {
            int small = 0;
            if (t2 !=  NULL) {
                small = t2->data;
                // 'small' holds the next digit of number to be subtracted
            }

            if (t1->data < small) {
                t1->next->data -= 1;
                t1->data += 10;
                // taking carry
            }

            Node* n = new Node(t1->data - small);
            // creating new node for storing difference
            n->next = res;
            res = n;

            t1 = t1->next;
            if (t2 !=  NULL) {
                t2 = t2->next;
            }
        }

        while (res->next !=  NULL && res->data == 0) {
            res = res->next;
            // removing trailing zeroes from result list
        }
        return res;
    }
};


//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends