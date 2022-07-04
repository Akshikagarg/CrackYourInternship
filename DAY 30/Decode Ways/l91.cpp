class Solution {
public:
    
    int numDecodings(string s) {
        int n=s.size();
        if(n==0 || s[0]=='0')return 0;
        if(n==1)return 1;
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            int idx=s[i]-'0';
            int ans1=0,ans2=0;
            if(idx!=0){
                ans1=dp[i+1];
            }
            if(i<n-1){
                int idx2=s[i+1]-'0';
                int num=idx*10+idx2;
                if(num>=10 && num<=26){
                    ans2=dp[i+2];
                }
            }
            dp[i]=ans1+ans2;
        }
        
        return dp[0];
       
    }
};
