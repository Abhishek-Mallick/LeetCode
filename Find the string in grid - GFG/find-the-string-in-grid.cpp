//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool search(vector<vector<char>> grid,int row,int col,string word,int x[],int y[])
    {
        int R = grid.size();
		int C = grid[0].size();
	    // If first character of word doesn't match with
	    // given starting point in grid.
	    if (grid[row][col] != word[0])
	      return false;
	 
	    int len = word.size();
	 
	    // Search word in all 8 directions starting from (row,col)
	    for (int dir = 0; dir < 8; dir++)
	    {
	        // Initialize starting point for current direction
	        int k, rd = row + x[dir], cd = col + y[dir];
	 
	        // First character is already checked, match remaining
	        // characters
	        for (k = 1; k < len; k++)
	        {
	            // If out of bound break
	            if (rd >= R || rd < 0 || cd >= C || cd < 0)
	                break;
	 
	            // If not matched,  break
	            if (grid[rd][cd] != word[k])
	                break;
	 
	            //  Moving in particular direction
	            rd += x[dir], cd += y[dir];
	        }
	 
	        // If all character matched, then value of must
	        // be equal to length of word
	        if (k == len)
	            return true;
	    }
	    return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int row = grid.size();
	    int col = grid[0].size();
	    
	    int del_row[] = {-1,-1,-1,0,1,1,1,0};
	    int del_col[] = {-1,0,1,1,1,0,-1,-1};
	    
	    vector<vector<int>> ans;
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(search(grid,i,j,word,del_row,del_col))
	                ans.push_back({i,j});
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends