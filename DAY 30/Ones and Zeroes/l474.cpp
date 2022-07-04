class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        vector<int> ones(len,0),zeroes(len,0);
        int k=0;
        for(string &s:strs)
        {   
            int one=0;
            for(char ch:s)
            {
                if(ch=='1')
                one++;
            }
            ones[k]=one;
            zeroes[k]=s.length()-one;
            k++;
        }
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        // dp[m][n] ----> when we can take m zeroes and n ones whats the max subset size possible
        for(int i=0;i<len;i++)
        {
            int count0,count1;
            count0=zeroes[i];
            count1=ones[i];
            for(int j=m;j>=count0;j--)
            {
                for(int k=n;k>=count1;k--)
                {
                    dp[j][k]=max(1+dp[j-count0][k-count1],dp[j][k]);
                }
            }
        }
        return dp[m][n];
    }
};
