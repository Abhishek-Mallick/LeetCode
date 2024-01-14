//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution
{   
    public:
    struct Trie 
    { 
        bool leaf; 
        Trie* children[2]; 
    }; 
      

    Trie* getNewTrieNode() 
    { 
        Trie* node = new Trie; 
        node->children[0] = node->children[1] = NULL; 
        node->leaf = false; 
        return node; 
    } 
      
    /* function to insert a row in Trie*/
    bool insert(Trie*& head, vector<int> arr, int N) 
    { 
        Trie* curr = head; 
      
        for (int i = 0; i < N; i++) 
        { 
            /*creating a new path if it don not exist*/
            if (curr->children[arr[i]] == NULL) 
                curr->children[arr[i]] = getNewTrieNode(); 
      
            curr = curr->children[arr[i]]; 
        } 
      
        /*if the row already exist return false*/
        if (curr->leaf) 
            return false; 
      
        /* making leaf node tree and return true*/
        return (curr->leaf = true); 
    } 


    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        Trie* head = getNewTrieNode(); 
        vector<int> ans;
        //int M = matrix.size();
        //int N = matrix[0].size();
        /*inserting into Trie and checking for dulpicates*/
        for (int i = 0; i < M; i++) 
      
            // If already exists 
            if (!insert(head, matrix[i], N)) 
                ans.push_back(i); 
        
        return ans;
      
    } 
};


//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--) 
    {
        int row, col;
        cin>> row>> col;
        vector<vector<int> > matrix(row); 
        for(int i=0; i<row; i++)
        {
            matrix[i].assign(col, 0);
            for( int j=0; j<col; j++)
            {
                cin>>matrix[i][j];
            }
        }
        
        Solution ob;
        vector<int> ans = ob.repeatedRows(matrix, row, col);


        for (int i = 0; i < ans.size(); ++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}



// } Driver Code Ends