// // Given an undirected graph with V vertices. 
// We say two vertices u and v belong to a single province 
// if there is a path from u to v or v to u. 
// Your task is to find the number of provinces.

// // Note: A province is a group of directly or 
// indirectly connected cities and no other cities outside of the group.


//time=> O(N)+O(V+2E)   space=>O(N)+O(N)


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node, vector<int>ls[], int vis[]){
        vis[node] = 1;
        for(auto x: ls[node]){
            if(vis[x] == 0){
                dfs(x,ls,vis);
            }
        }
    }
  
  
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>ls[V];
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j] == 1 and i!=j){
                    ls[i].push_back(j);
                    ls[j].push_back(i);
                }
            }
        }
        
        int ans = 0;
        int vis[V] = {0};
        for(int i=0; i<V; i++){
            if(!vis[i]){
                ans++;
                dfs(i,ls,vis);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends