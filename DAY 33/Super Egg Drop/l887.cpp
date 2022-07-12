class Solution {
public:
    int dp[101][10001];
    
    int func(int e , int f)
    {
         //base case	 
          if(f==0 || f==1)
            return f;  
        if(e==1)
            return f;
        
         if(dp[e][f]!=-1)
             return dp[e][f];
         
        int ans=INT_MAX;
        
        int lo=1 , h=f;
        
        while(lo<h)
        {
            int mid= (lo + (h-lo)/2);
            int val1 , val2;
            if(dp[e-1][mid-1] != -1) val1 = dp[e-1][mid-1];     // left call check
            else
            {
                val1 = func(e-1,mid-1);
                dp[e-1][mid-1] = val1;
            }
            if(dp[e][f-mid] != -1) val2 = dp[e][f-mid];     //right call check
            else
            {
                val2 = func(e,f - mid);
                dp[e][f-mid] = val2;
            }
            int temp= 1 + max(val1 , val2);
            if(val1>val2)
            
                h=mid;
            
            else
            
                lo=mid+1;
            
            
            ans = min( ans , temp);
            
            
        }
        
        return dp[e][f]=ans;
        
        
        
    }
    int superEggDrop(int e, int f) {
        memset(dp , -1 , sizeof(dp));
        
        return func(e , f);
        
    }
};
