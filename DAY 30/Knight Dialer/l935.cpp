class Solution {
public:
    #define mod 1000000007
    typedef long long ll;
    
    vector<vector<int>> dir = {{4,6,-1}, {6,8,-1},{7,9,-1},{4,8,-1},{3,0,9},
                               {-1,-1,-1},{0,7,1},{6,2,-1},{1,3,-1},{2,4,-1}};  
 // dir[i] represents the options that we have to jump to if starting from 'i' digit
    
    ll solve(int start, int n, vector<vector<int>> &dp){
        
        if(start == -1) return 0; // can't jump out here coz either out of bound or */#
        if(n == 1) return 1; // base case

        if(dp[start][n] != -1) return dp[start][n];
        
        ll res = 0;
        for(int i = 0; i<dir[start].size(); i++)
            res = (res + solve(dir[start][i],n-1,dp)) %mod; // jumping to possible option
        
        return dp[start][n] = res;
        }
        
    int knightDialer(int n) {

        ll ans = 0;
        for(int i = 0; i< 10; i++){  // for all possible starting points
            vector<vector<int>> dp(10,vector<int>(n+1,-1));
            ans += solve(i,n,dp);
            ans %= mod;
        }
    
        return ans;
    }
};
