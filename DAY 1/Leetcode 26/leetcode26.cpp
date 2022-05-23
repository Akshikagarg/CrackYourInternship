class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        int count = 1;
        int i=0, j=1;
        while(j<size){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                count++;
                i++;
            }
            else if(nums[j]==nums[i]){
                j++;
            }
        }
        return count;
    }
};
