class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
         unordered_map<int,int>mp;
       int sum=0;
       int maxi=0;
       int i;
       
       for(i=0 ;i<n ;i++)
       {
           sum += A[i];
           if(sum==0) maxi=i+1;
           else 
           {
               if(mp.find(sum)!=mp.end()) maxi = max(maxi,i-mp[sum]);
               else mp[sum] = i;
           }
       }
       return maxi;
    }
};
