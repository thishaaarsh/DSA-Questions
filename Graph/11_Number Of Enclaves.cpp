// You are given an n x m binary matrix grid, where 0 represents 
// a sea cell and 1 represents a land cell.

// A move consists of walking from one land cell to another 
// adjacent (4-directionally) land cell or walking off the boundary of the grid.

// Find the number of land cells in grid for which we cannot 
// walk off the boundary of the grid in any number of moves.


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int vis[n][m] = {0};
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i,j});
                        vis[i][j] = 1;
                    }
                }
            }
        }
        int delcol[] = {1,0,-1,0};
        int delrow[] = {0,1,0,-1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow >=0 and ncol >= 0 and nrow < n and ncol < m and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1 and vis[i][j] == 0)
                    ans++;
            }
        }
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends