//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool solve(int src, vector<int> &vis,  vector<int> &pathvis,  vector<int> adj[] ){
        vis[src] = 1;
        pathvis[src] = 1;
        for(auto it : adj[src]){
            if(vis[it] == 0){
                if(solve(it,vis,pathvis,adj) == true) return true;
            }
            else{
                if(pathvis[it]) return true;
            }
        }
        pathvis[src] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V,0);
        vector<int> pathvis(V,0);
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                if(solve(i,vis,pathvis,adj) == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends