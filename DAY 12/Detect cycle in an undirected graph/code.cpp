// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
 public:
   // Function to detect cycle in an undirected graph.

   
  bool helper(int src,vector<bool> &vis,vector<int> adj[],int parent){
        vis[src] = true;
        for(auto x : adj[src])
        {
            if(!vis[x])
            {
                if(helper(x,vis,adj,src)) return true;
            }
            else if(x != parent) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(helper(i,vis,adj,-1)){
                    return true;
                }
            }
        }
        return false;
    }
};
// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
