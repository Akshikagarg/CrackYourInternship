class Solution {
public:

int findMaxValueOfEquation(vector<vector<int>>& nums, int k) {
  priority_queue<pair<int,int>>pq;
  int ans=INT_MIN;
  for(int i=0;i<nums.size();i++){
      
      while(!pq.empty() && (nums[i][0] - pq.top().second )> k){
          pq.pop();
      }
      
      if(!pq.empty()){
          ans=max(ans,pq.top().first + nums[i][1]+nums[i][0] );
      }
      pq.push({nums[i][1]-nums[i][0],nums[i][0]});
          
  }
  return ans;
}
};
