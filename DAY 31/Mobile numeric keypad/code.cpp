class Solution{
 # define ll long long

public:
long long solve(vector<vector<int>>arr, int n, int curr, vector<vector<ll>>&dp){
    
    if(n==0) return 1;
       
    if(dp[curr][n]!=-1) return dp[curr][n];
    
    ll count=0;
    for(int i=0;i<arr[curr].size();i++) count+=solve(arr, n-1, arr[curr][i], dp);
    
    return dp[curr][n] = count;
}
long long getCount(int N)
{
 vector<vector<int>>arr = {{0, 8},{1, 2, 4}, {1, 2, 3, 5},
                           {2, 3, 6}, {1, 4, 5, 7}, {2, 4, 5, 6, 8},
                           {3, 5, 6, 9}, {4, 7, 8}, {5, 7, 8, 9, 0},{6, 8, 9}};
 
 ll res = 0;
 
 vector<vector<ll>>dp(10, vector<ll>(N+1, -1));
 for(int i=0;i<=9;i++) res += solve(arr, N-1, i, dp);
     
 return res;
}


};
