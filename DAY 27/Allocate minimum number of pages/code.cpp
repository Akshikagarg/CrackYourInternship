class Solution 
{
  public:
  bool isValid(int nums[],int n,int k,int mid){
       int numberOfStudents = 1;
       int sum1 = 0;
       
       for(int i=0; i<n; i++){
           sum1 = sum1 + nums[i];
           
           if(sum1>mid){
              numberOfStudents++;
              sum1=nums[i];
           }
           
           if(numberOfStudents>k){
               return false;
           }
       }
       return true;
       
   }
   
   int findPages(int nums[], int n, int k){
       
       if(n<k){
           return -1;
       }
       
       int sum = 0;
       for(int i=0; i<n; i++){
           sum = sum + nums[i];
       }
       
       int max = nums[0];
       
       for(int i=1; i<n; i++){
           if(nums[i]>nums[i-1]){
               max = nums[i];
           }
       }
       
       int low = max;
       int high = sum;
       
       int ans = -1;
       
       while(low<=high){
           int mid = low + (high-low)/2;
           
           if(isValid(nums,n,k,mid)==true){
               ans = mid;
               high = mid - 1;
           }
           else{
               low = mid + 1;
           }
       }
       
       return ans;
       
       
   }
};
