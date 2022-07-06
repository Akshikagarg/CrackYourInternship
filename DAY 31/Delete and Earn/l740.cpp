class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maximum_element;
        unordered_map<int, int> frequency;
        
        for(int num : nums) {
            frequency[num]++;
            maximum_element = max(maximum_element, num);
        }
        vector<int>dp(maximum_element + 1, 0);
        
        for(int num = 1; num <= maximum_element; num++) {
            int skip = dp[num - 1];
            int take = num * frequency[num];
            if(num >= 2) take += dp[num - 2];
            dp[num] = max(skip, take); 
        }
        return dp[maximum_element];
    }
};
