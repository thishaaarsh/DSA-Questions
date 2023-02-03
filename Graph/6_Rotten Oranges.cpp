// Given a grid of dimension nxm where each cell in the grid 
// can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the minimum time 
// required to rot all oranges. A rotten orange at index [i,j] 
// can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] 
// (up, down, left and right) in unit time.


//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int vis[n][m];
        int cntfr = 0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                else{
                    vis[i][j] = 0;
                }
                if(grid[i][j] == 1)
                    cntfr++;
            }
        }
        
        int delr[] = {-1,0,1,0};
        int delc[] = {0,1,0,-1};
        int ans = 0;
        int cnt = 0;
        while(q.empty()==false){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            ans = max(ans,t);
            q.pop();
            for(int i=0; i<4; i++){
                int nr = r + delr[i];
                int nc = c + delc[i];
                if(nr >= 0 && nr < n and nc >=0 and nc < m and grid[nr][nc] == 1 and vis[nr][nc] == 0){
                    int tm = t+1;
                    q.push({{nr,nc},tm});
                    vis[nr][nc] = 2;
                    cnt++;
                }
            }
        }
        // for(int i=0; i<n; i++){
        //     for(int j=0; j<m; j++){
        //         if(vis[i][j] != 2 and grid[i][j] == 1){
        //             return -1;
        //         }
        //     }
        // }
        if(cnt != cntfr) return -1;
        else
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends