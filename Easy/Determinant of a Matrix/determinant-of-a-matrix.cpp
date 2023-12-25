//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    void getCofactor(vector<vector<int>> & matrix,vector<vector<int>>&temp,int p,int q,int n)
    {
        int i = 0, j = 0;
        for (  int row = 0; row < n; row++)
        {
            for (  int col = 0; col < n; col++)
            {
                //copying only those elements into temporary matrix 
                //which are not in given row and column.
                if (row != p && col != q)
                {
                    temp[i][j++] = matrix[row][col];

                    //if row is filled, we increase row index and
                    //reset column index.
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
    }

    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        int D = 0; 

        //base case
        if (n == 1)
            return matrix[0][0];

        //creating a list to store Cofactors.
        vector<vector<int> > temp(n, vector<int>(n)); 
        int sign = 1; 

        //iterating for each element of first row.
        for (  int i = 0; i < n; i++)
        {
            //getting Cofactor of matrix[0][i].
            getCofactor(matrix, temp, 0, i, n);
            D += sign * matrix[0][i] * determinantOfMatrix(temp, n - 1);

            //terms are to be added with alternate sign so changing the sign.
            sign = -sign;
        }
        //returning the determinant.
        return D;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends