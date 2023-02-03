// Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) 
// consisting of '0's (Water) and '1's(Land). Find the number of islands.

// Note: An island is surrounded by water and is formed by 
// connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions4

// Space=>O(^2) Time => (n^2)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    void bfs(int row,int col,vector<vector<int>>&vis,vector<vector<char>>& grid){
        vis[row][col] = 1;
        queue<pair<int,int>>q;
        q.push({row,col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=-1; i<=1; i++){
                for(int j=-1; j<=1; j++){
                    int nrow = row+i;
                    int ncol = col+j;
                    if(nrow >= 0 and nrow < n and ncol >=0 and ncol<m and 
                    vis[nrow][ncol] == 0 and grid[nrow][ncol] == '1'){
                        bfs(nrow,ncol,vis,grid);
                    }
                }
            }
        }
        
    }
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' and !vis[i][j]){
                    bfs(i,j,vis,grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends