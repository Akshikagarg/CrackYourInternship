int merge_sort(vector<int>&nums,int i,int j);
 int merge(vector<int> &nums,int i,int j,int mid);
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int x=merge_sort(nums,0,nums.size()-1);
        return(x);
    }
    int merge_sort(vector<int>&nums,int i,int j){
        if(i>=j){
            return(0);
        }
        int mid=i+(j-i)/2;
        int inv=merge_sort(nums,i,mid);
        inv+=merge_sort(nums,mid+1,j);
        inv+=merge(nums,i,j,mid);
        return(inv);
    }
    int merge(vector<int> &nums,int i,int j,int mid){
        int cnt=0;
        int q=mid+1;
        for(int p=i;p<=mid;p++){
            while(q<=j&&nums[p]>2*(long long)nums[q]){
                q++;
            }
            cnt+=(q-(mid+1));
        }
        vector<int>b;
        int low=i;
        int high=mid+1;
        while(low<=mid&&high<=j){
            if(nums[low]<nums[high]){
                b.push_back(nums[low]);
                low++;
            }
            else{
                b.push_back(nums[high]);
                high++;
            }
        }
        while(low<=mid){
            b.push_back(nums[low]);
            low++;
            
        }
        while(high<=j){
            b.push_back(nums[high]);
            high++;
        }
        for(int m=i;m<=j;m++){
            nums[m]=b[m-i];
        }
        return(cnt);
    }
};
