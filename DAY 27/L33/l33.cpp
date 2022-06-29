class Solution {
public:
    int binarySearch(vector<int>& nums, int first, int last, int target){     
        // function for binary search
        int medium = first + (last-first)/2;
            while(first<=last){
                if(nums[medium]>target){
                    last = medium-1;
                }
                else if(nums[medium]<target){
                    first = medium+1;
                }
                else{
                    return medium;
                }
                medium = first + (last-first)/2;
            }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n= nums.size();                                           
        if(n==1 && nums[0]==target) return 0;            // Two important cases 
        else if(n==1 && nums[0]!=target) return -1;
        int start=0;                                     // finding the unknown pivot index 
        int end = n-1;
        int mid = (start+end)/2;
        while(start<end)
        {                        
            if(nums[mid]>=nums[0]){
                start = mid+1;
            }
            else{
                end = mid;
            }
            mid = (start+end)/2;       
        }
        if(target>=nums[0] && target<=nums[start-1]){               
            // if the target lies between the index 0 to pivot
            return binarySearch(nums,0,start-1,target);             
        } 
        else if(target>=nums[start] && target<=nums[n-1]){          
            // if the target lies between the pivot and index n-1   
            return binarySearch(nums,start,n-1,target);
        }
        else{                                                       
            // for all other cases  
            return -1;
        }
    }
};
