class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        int dp[][] = new int[triangle.size()][triangle.get(triangle.size()-1).size()];
        for(int el[] : dp)
            Arrays.fill(el,Integer.MAX_VALUE);
        return sumfind(triangle,0,0,dp);
    }
    private int sumfind(List<List<Integer>> triangle,int row,int col,int dp[][])
    {
        if(row == triangle.size())
            return 0;
        
        if(dp[row][col] != Integer.MAX_VALUE)
            return dp[row][col];
        
        int min = Math.min(sumfind(triangle,row+1,col,dp),sumfind(triangle,row+1,col+1,dp));
        dp[row][col] = triangle.get(row).get(col)+min;
        
        return dp[row][col];
    }
}