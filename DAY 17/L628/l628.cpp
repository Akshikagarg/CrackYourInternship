class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int k=nums.size();
         sort(nums.begin(), nums.end());
        return max(nums[0] * nums[1] * nums[k - 1], nums[k - 1] * nums[k - 2] * nums[k - 3]);
    }
};
