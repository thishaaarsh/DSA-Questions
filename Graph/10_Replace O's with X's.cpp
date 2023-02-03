// Given a matrix mat of size N x M where every element is either O or X.
// Replace all O with X that are surrounded by X.
// A O (or a set of O) is considered to be surrounded 
// by X if there are X at locations just below, just above, just left and just right of it.


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void dfs(int n , int m, vector<vector<char>> mat, vector<vector<int>> &vis ){
        vis[n][m] = 1;
        int delrow[] = {1,0,-1,0};
        int delcol[] = {0,1,0,-1};
        for(int i=0; i<4; i++){
            int nrow = n + delrow[i];
            int ncol = m + delcol[i];
            if(nrow >=0 and ncol >=0 and nrow < mat.size() and ncol < mat[0].size() and !vis[nrow][ncol] and
            mat[nrow][ncol] == 'O'){
                dfs(nrow,ncol,mat,vis);
            }
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0; i<n; i++){
            if(vis[i][0] == 0 and mat[i][0] == 'O'){
                dfs(i,0,mat,vis);
            }
            if(vis[i][m-1] == 0 and mat[i][m-1] =='O'){
                dfs(i,m-1,mat,vis);
            }
        }
        for(int i=0; i<m; i++){
            if(vis[0][i] == 0 and mat[0][i] == 'O'){
                dfs(0,i,mat,vis);
            }
            if(vis[n-1][i] == 0 and mat[n-1][i] == 'O' ){
                dfs(n-1,i,mat,vis);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j] == 0  and mat[i][j] == 'O'){
                    mat[i][j] = 'X';
                }
            }
        }
        return mat;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        for(int i = 0;i < n;i++)
            for(int j=0; j<m; j++)
                cin>>mat[i][j];
        
        Solution ob;
        vector<vector<char>> ans = ob.fill(n, m, mat);
        for(int i = 0;i < n;i++) {
            for(int j = 0;j < m;j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends