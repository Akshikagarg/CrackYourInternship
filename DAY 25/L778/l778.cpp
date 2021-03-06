class Solution {
public:
    vector<int> DIR = {1, 0, -1, 0, 1};
    int n, result = 0;
    int swimInWater(vector<vector<int>>& g) {
        n = g.size();
        vector<vector<bool>> vis(n, vector<bool>(n));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({g[0][0], {0, 0}});
        while(!pq.empty()){
            pair<int, pair<int, int>> A = pq.top();
            pq.pop();
            int cost = A.first, r = A.second.first, c = A.second.second;
            result = max(result, cost);
            if(r == n - 1 && c == n - 1) return result;
            for(int k = 0; k < 4; k++){
                int newR = r + DIR[k], newC = c + DIR[k + 1];
                if(newR == n || newC == n || newC < 0 || newR < 0 || vis[newR][newC])
                    continue;
                vis[newR][newC] = 1;
                pq.push({g[newR][newC], {newR, newC}});
            }
        }
        return result;
    }
};
