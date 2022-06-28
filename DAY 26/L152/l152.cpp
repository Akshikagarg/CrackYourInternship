class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int ans = INT_MIN;
        
        int currMAX = 1;
        int currMIN = 1;        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                currMAX = currMIN = 1;
            
            int t = currMAX;
            currMAX = max({nums[i],currMAX*nums[i],currMIN*nums[i]});
            currMIN = min({nums[i],t*nums[i],currMIN*nums[i]});
            ans = max(currMAX,ans);
        }
        return ans;
    }
};
