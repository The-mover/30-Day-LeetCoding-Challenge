class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if( matrix.size() == 0 || matrix[0].size() == 0 ) return 0;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> sum(n+2, vector<int>(m+2, 0));
        
        for(int i=0; i<n; i++) {
            sum[i][0] = matrix[i][0] - '0';
        }
        for(int i=0; i<m; i++) {
            sum[0][i] = matrix[0][i] - '0';
        }
        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if( matrix[i][j] == '1' ) {
                    int mn = min(sum[i-1][j], min(sum[i][j-1], sum[i-1][j-1]));
                    sum[i][j] = mn + 1;
                } else {
                    sum[i][j] = 0;
                }
            }
        }
        int mx = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                mx = max(mx, sum[i][j]);
            }
        }
        return mx * mx;
        
    }
};