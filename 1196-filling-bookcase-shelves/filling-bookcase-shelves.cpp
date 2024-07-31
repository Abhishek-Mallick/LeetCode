class Solution {
public:
    int newShelfWidth;
    int rec(int bookId, vector<vector<int>>& books, int currShelfWidth, int currShelfHeight,vector<vector<int>>& dp) {
        int totalBooks = books.size();
        int maxHeight = max(currShelfHeight, books[bookId][1]);
        if(bookId == totalBooks - 1) {
            if(books[bookId][0] <= currShelfWidth)
                return maxHeight; // i.e you have space to fit in so take curr maxHeight
            else
                return currShelfHeight + books[bookId][1];
        }

        if(dp[bookId][currShelfWidth] != -1)
            return dp[bookId][currShelfWidth];
        
        // case 1
        int sameShelf = INT_MAX;
        if(currShelfWidth - books[bookId][0] >= 0)
            sameShelf = rec(bookId + 1,books,currShelfWidth - books[bookId][0], maxHeight,dp);
    
        // case 2
        int diffShelf = INT_MAX;
        diffShelf = currShelfHeight + rec(bookId + 1,books,newShelfWidth-books[bookId][0],books[bookId][1],dp);
        return dp[bookId][currShelfWidth] = min(sameShelf, diffShelf);
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        newShelfWidth = shelfWidth;
        vector<vector<int>> dp(books.size(), vector<int>(shelfWidth+1,-1));
        return rec(0,books,shelfWidth,0,dp);
    }
};