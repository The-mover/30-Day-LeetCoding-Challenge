class Solution {
private:
    int const inf = 2e9 + 5;
    int cal(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if( i == n || j == m ) return inf;
        if( i == n-1 && j == m-1 ) return grid[i][j];
        if( dp[i][j] != -1 ) return dp[i][j];
        dp[i][j] = grid[i][j] + min(cal(i+1, j, n, m, grid, dp), cal(i, j+1, n, m, grid, dp));
        return dp[i][j];
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        if( !grid.size() || !grid[0].size() ) return 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n+2, vector<int> (m+2, -1));
        int ans = cal(0, 0, n, m, grid, dp);
        return ans;
    }
};