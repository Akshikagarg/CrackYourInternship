public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node,vector<int> adj1[],vector<bool> &vis){
        vis[node]=true;
        for(auto nbr:adj1[node]){
            if(!vis[nbr]){
                dfs(nbr,adj1,vis);
            }
        }
    }
	
    void dfs(int node,vector<int> adj[],vector<bool> &visited,stack<int> &st){
        visited[node]=true;
        for(auto nbr:adj[node]){
            if(!visited[nbr]){
                dfs(nbr,adj,visited,st);
            }
        }
        st.push(node);
    }	
	
    int kosaraju(int n, vector<int> adj[])
    {
        stack<int> st;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        
        // transpose matrix
        vector<int> adj1[n];
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                adj1[it].push_back(i);
            }
        }
        
        int count=0;
        vector<bool> vis(n,false);
        while(!st.empty()){
            int cur=st.top();
            st.pop();
            if(!vis[cur]){
                count++;
                dfs(cur,adj1,vis);
            }
        }
        return count;
    }
