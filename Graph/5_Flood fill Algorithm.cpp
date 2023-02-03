// An image is represented by a 2-D array of integers, 
// each integer representing the pixel value of the image.

// Given a coordinate (sr, sc) representing the starting 
// pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

// To perform a "flood fill", consider the starting pixel, 
// plus any pixels connected 4-directionally to the starting pixel 
// of the same color as the starting pixel, plus any pixels connected 
// 4-directionally to those pixels (also with the same color as the starting pixel), 
// and so on. Replace the color of all of the aforementioned pixels with the newColor.

//time => O(n*m) space => 

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int delrow[4] = {1,0,-1,0};
    int delcol[4] = {0,1,0,-1};
    void dfs(int sr, int sc, int iniclr, int newcolor,vector<vector<int>>&ans){
        int n = ans.size();
        int m = ans[0].size();
        ans[sr][sc] = newcolor;
        for(int i=0; i<4;i++){
            int nrow = sr + delrow[i];
            int ncol = sc + delcol[i];
            if(nrow >= 0 and nrow<n and ncol >= 0 and ncol < m and ans[nrow][ncol] == iniclr and ans[nrow][ncol] != newcolor){
                dfs(nrow,ncol,iniclr,newcolor,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newcolor) {
        // Code here 
        int iniclr = image[sr][sc];
        vector<vector<int>>ans = image;
        dfs(sr,sc,iniclr,newcolor,ans);
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
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends