class Solution{
    public:
    
    int dirs[4][2] = {{0, -1}, {0, 1} , {-1, 0}, {1, 0}};
    vector<vector<bool>> vis;
    int n;
    void solve(int i, int j, vector<string> &ans, vector<vector<int>> &m, string pth) {
        if(i == n - 1 && j == n - 1) {
            ans.push_back(pth);
            return;
        }
        
        vis[i][j] = true;
        
        for(auto d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            if(ni >= 0 && nj >= 0 && ni < n & nj < n && m[ni][nj] && !vis[ni][nj]) {
                char c;
                if(d[0] == 0 && d[1] == 1) c = 'R';
                if(d[0] == 0 && d[1] == -1) c = 'L';
                if(d[0] == 1 && d[1] == 0) c = 'D';
                if(d[0] == -1 && d[1] == 0) c = 'U';
                solve(ni, nj, ans, m, pth + c);
            } 
        }
        
        vis[i][j] = false;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int N) {
        n = N;
        vector<string> ans;
        vis.resize(n, vector<bool> (n, false));
        if(m[0][0] == 0) return ans;
        solve(0, 0, ans, m, "");
        return ans;
    }
};
