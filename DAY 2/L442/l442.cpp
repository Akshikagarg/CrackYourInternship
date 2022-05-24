class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
       vector<int> ans;
        sort(nums.begin(), nums.end());
        int l=0; int h=1;
        
        if(nums.size() == 0 || nums.size() == 1){
            return ans;
        }
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[l] == nums[h]){
                ans.push_back(nums[l]);
            }
            l++; h++;
        }
        return ans;
    
        
    }
};
