class Solution 
{
   public:
   
   static bool comp(Job& j1, Job& j2){
       return j1.dead < j2.dead;
   }
   
   //Function to find the maximum profit and the number of jobs done.
   vector<int> JobScheduling(Job arr[], int n) 
   { 
       sort(arr, arr + n, comp);
   
       vector<int> res(2,0);
       priority_queue<int, vector<int>, greater<int>> pq;
       pq.push(arr[0].profit);
       
       for(int i = 1; i< n; i++){
           if(arr[i].dead > pq.size())
               pq.push(arr[i].profit);
           else{
               if(pq.top() < arr[i].profit){
                   pq.pop();
                   pq.push(arr[i].profit);
               }
           }
       }
       
       res[0] = pq.size();
       while(!pq.empty()){
           res[1] += pq.top();
           pq.pop();
       }
       
       return res;
       
   } 
};
