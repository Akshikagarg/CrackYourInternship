class Solution {
public:

    vector<long long> dp;

    int solve(vector<int> &nums, int capacity, int pos)
    {
        if(pos == nums.size())
            return INT_MAX;
            
        if(dp[pos]!=-1)
            return dp[pos];
    
        int cost1, cost2;
        int rem_space = capacity;
        int ans=INT_MAX;
        int i;
        
        for(i=pos; i<nums.size(); i++)
        {
            if(i==pos and nums[i] <= rem_space)
                rem_space-=nums[i];
            else if(nums[i]+1 <= rem_space)
                rem_space -= (nums[i]+1);
            else 
                break;
                
            cost1 = rem_space*rem_space;
            cost2 = solve(nums, capacity, i+1);
            int total_cost = cost1+cost2;
            
            ans = min(ans, total_cost);
        }
        
        if(i==nums.size())  
            return dp[pos] = 0;
        else 
            return dp[pos] = ans;
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        dp.assign(nums.size(), -1);
        return solve(nums, k, 0);
    } 
