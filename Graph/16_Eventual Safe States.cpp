// A directed graph of V vertices and E edges is 
// given in the form of an adjacency list adj. 
// Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

// A node is a terminal node if there are no outgoing edges. 
// A node is a safe node if every possible path starting from 
// that node leads to a terminal node.

// You have to return an array containing all the safe nodes of the 
// graph. The answer should be sorted in ascending order.


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool solve(vector<int>&vis, vector<int>&pathvis,vector<int>&check,int src, vector<int>adj[]){
        vis[src] = 1;
        pathvis[src] = 1;
        check[src] = 0;
        for(auto it : adj[src]){
            if(vis[it] == 0){
                if(solve(vis,pathvis,check,it,adj)==true){
                    check[src] = 0;
                    return true;
                }
            }
            else if(pathvis[it]){
                    check[src] = 0;
                    return true;
                }
        }
        check[src] = 1;
        pathvis[src] = 0;
        return false;
    }
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>pathvis(V,0);
        vector<int>check(V,0);
        for(int i=0; i<V; i++){
            if(vis[i] == 0){
                solve(vis,pathvis,check,i,adj);
            }
        }
        vector<int>ans;
        for(int i=0; i<V; i++){
            if(check[i]==1)
                ans.push_back(i);
        }
        return ans;
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
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends