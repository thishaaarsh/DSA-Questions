// Given a binary grid of n*m. Find the distance of the 
// nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, 
// where i1, j1 are the row number and column number of the 
// current cell, and i2, j2 are the row number and column number 
// of the nearest cell having value 1.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m =grid[0].size();
	    int vis[n][m];
	    //int ans[n][m];
	    vector<vector<int>>ans(n,vector<int>(m,0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0; i<n; i++){
	        for(int j=0;j<m; j++){
	            if(grid[i][j] == 1){
	                q.push({{i,j},0});
	                vis[i][j] = 1;
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }
	    int drow[] = {1,0,-1,0};
	    int dcol[] = {0,1,0,-1};
	    while(!q.empty()){
	        int r = q.front().first.first;
	        int c = q.front().first.second;
	        int dis = q.front().second;
	        q.pop();
	        ans[r][c] = dis;
	        for(int i=0; i<4; i++){
	            int nrow = r + drow[i];
	            int ncol = c + dcol[i];
	            if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and grid[nrow][ncol] == 0 and !vis[nrow][ncol]){
	                q.push({{nrow,ncol},dis+1});
	                vis[nrow][ncol] = 1;
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends