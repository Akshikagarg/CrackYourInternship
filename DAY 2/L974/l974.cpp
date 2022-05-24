class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) 
    {
        vector<int> counts(k,0);
        int sum=0;
        for(int x:nums)
        {
            sum += (x%k + k) % k;
            counts[sum % k]++;
        }
        int r=counts[0];
        for(int c:counts)
            r+=(c*(c-1))/2;
            return r;
    }
};
