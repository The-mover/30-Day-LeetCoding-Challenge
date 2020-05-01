class Solution {
private:
    int dp[1005][1005];
    int rec(int i, int j, int n, int m, string &text1, string &text2) {
        if( i == n || j == m ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        int res = 0;
        if( text1[i] == text2[j] ) {
            res = 1 + rec(i+1, j+1, n, m, text1, text2);
        } else {
            int val1 = rec(i+1, j, n, m, text1, text2); 
            int val2 = rec(i, j+1, n, m, text1, text2);
            
            res = max(val1, val2);
        }
        dp[i][j] = res;
        return dp[i][j];
    }
    
public:
    int longestCommonSubsequence(string text1, string text2) {
        //vector<vector<int>> dp(1001, vector<int> (1001, 0));
        int n = text1.size();
        int m = text2.size();
        memset(dp, -1, sizeof dp);
        int ans = rec(0, 0, n, m, text1, text2);
        return ans;
    }
};