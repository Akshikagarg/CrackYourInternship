class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(),n = t.size();
        
        long long dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        
        for(int i =0;i<=m;i++)
            dp[i][0] = 1;
        
        for(long long i = 1;i<=m;i++){
            for(long long j = 1;j<=n;j++){
                if(s[i-1] == t[j-1])
                    dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])%1000000007;
                else
                    dp[i][j] = dp[i-1][j];
            }
        } 
        
        return dp[m][n];
    }
};
