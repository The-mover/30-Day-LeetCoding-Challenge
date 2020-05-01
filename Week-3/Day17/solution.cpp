class Solution {
private:
    int fx[5] = {+1,-1,+0,+0};
    int fy[5] = {+0,+0,+1,-1};
    
    void bfs(int x, int y, int n, int m, vector<vector<char>>& grid, vector<vector<int>>& vis ) {
        queue<pair<int, int>> Q;
        vis[x][y] = 1;
        Q.push({x, y});
        while( !Q.empty() ) {
            auto top = Q.front();
            Q.pop();
            for(int i=0; i<4; i++) {
                int xx = top.first + fx[i];
                int yy = top.second + fy[i];
                //cout << "ok "<< xx << " " << yy << endl;
                if( xx < 0 || xx == n || yy < 0 || yy == m ) continue;
                if( !vis[xx][yy] && grid[xx][yy] == '1' ) {
                    vis[xx][yy] = 1;
                    Q.push({xx, yy});
                }
            }
        }
    }
    
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if( n == 0 ) return 0;
        int m = grid[0].size();
        vector<vector<int> > vis( n+2 , vector<int> (m+2, 0));
        int ans = 0;
        //cout << vis[0][0] << endl;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if( grid[i][j] == '1' && !vis[i][j] ) {
                    //cout << "vis " << i << " " << j << endl;
                    ans++; 
                    bfs(i, j, n, m, grid, vis);
                }
            }
        }
        return ans;
    }
};