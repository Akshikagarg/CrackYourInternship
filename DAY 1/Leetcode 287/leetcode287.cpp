class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> count;
        int size = nums.size();
        for(int i=0; i<size; i++){
            count[nums[i]]++;
        }
        
        for(int i=0; i<size; i++){
            int current = nums[i];
            if(count[current]>1){
                return current;
            }
        }
        return {};
    }
};
