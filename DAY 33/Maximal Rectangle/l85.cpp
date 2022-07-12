class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        int m=matrix.size(), n=matrix[0].size(), ans=0;
        stack<int>s;
        vector<int>dp(n,0);
        int i, j; 
        
        for( i=0; i<m; i++)
        {
            for( j=0; j<n; j++)
            {
                if(matrix[i][j]!='0') dp[j]+=1;
                else dp[j]=0;
            }
    
            j=0;
            while(j<n)
            {
                while(!s.empty() && dp[s.top()]>=dp[j])
                {
                    int top=s.top();
                    s.pop();
                    ans= max( ans, dp[top]*( s.empty() ? j : j-s.top()-1 )  );
                }
                s.push(j++);
            }
            while(!s.empty() )
            {
                int top=s.top();
                s.pop();
                ans= max( ans, dp[top]*( s.empty() ? j : j-s.top()-1 )  );
            }
        }
        
        return ans;
    }
};
