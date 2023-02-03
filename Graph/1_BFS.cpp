//BFS connected graph
//Space => O(n)
//Time => O(n)+O(2E)

#include <bits/stdc++.h>
using namespace std;


vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        queue<int>q;
        vis[0] = 1;
        q.push(0);
        vector<int>ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto x : adj[node]){
                if(vis[x] == 0){
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
        return ans;
}

int main(){
    
}