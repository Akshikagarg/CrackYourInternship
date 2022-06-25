class Solution{
  public:
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
        vector<long long int>ans;
        long long int totalproduct=1;
        int countzero=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                countzero++;
            }
            else
            {
            totalproduct*=nums[i];
            }
            
        }
        if(countzero>0)
        {
           if(countzero==1)
           {
                for(int i=0;i<n;i++)
                {
                    if(nums[i]==0)
                      ans.push_back(totalproduct);
                      else
                      {
                         ans.push_back(0); 
                      }
                }
                
            }
            else
            {
                for(int i=0;i<n;i++)
                {
                     ans.push_back(0);
                }
            }
        }
               
        
        else
        {
            for(int i=0;i<n;i++)
        {
            long long int temp=totalproduct/nums[i];
            ans.push_back(temp);
        }
        }
        return ans;
    }
};

