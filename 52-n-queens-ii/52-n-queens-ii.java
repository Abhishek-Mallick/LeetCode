class Solution {
    
    private Set<Integer> colIndex = new HashSet<Integer>();
    private Set<Integer> degree45 = new HashSet<Integer>();
    private Set<Integer> degree135 = new HashSet<Integer>();
    
    private int count = 0;
    
    public int totalNQueens(int n) {
        validCounter(n,0);
        return count;
    }
    
    public void validCounter(int n, int row)
    {
        if(row == n)
        {
            count++;
            return;
        }
        else
        {
            for(int col=0;col<n;col++)
            {
                if(validPosition(row,col))
                {
                    colIndex.add(col);
                    degree135.add(row-col);
                    degree45.add(row+col);
                    
                    validCounter(n,row+1);  //recursive calling
                    
                    colIndex.remove(col);
                    degree135.remove(row-col);
                    degree45.remove(row+col);
                }
            }
        }
    }
    private boolean validPosition(int row,int col)
    {
        if(colIndex.contains(col) || degree135.contains(row-col) || degree45.contains(row+col))
            return false;
        else
            return true;
    }
}