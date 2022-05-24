class Solution {
public:
    vector<vector<int>> twosum(vector<int> &nums, int target, int start)
    {
        vector<vector<int>> res;
        int left = start;
        int right = nums.size()-1;
        vector<int> ans;
        while(left < right)
        {
            if(left!=start && nums[left]==nums[left-1]){
                left++;
                continue;
            }
            int sum = nums[left]+nums[right];
            if(sum==target)
            {
                ans.push_back(nums[left]);
                ans.push_back(nums[right]);
                res.push_back(ans);
                ans.pop_back();
                ans.pop_back();
                left++; right--;
            }
            else if(sum > target){
                right--;
            }
            else{
                left++;
            }
        }
        
        return res;   
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++){
            if(i!=0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int t = 0-nums[i];
            vector<vector<int>> res = twosum(nums,t,i+1);
                
            
            for(auto &it:res){
                it.push_back(nums[i]);
                ans.push_back(it);
            }
        }
        return ans; 
    }
};
