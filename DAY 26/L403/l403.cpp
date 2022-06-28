class Solution {
public:
    map<int,bool> mp;
    int last;
    map<pair<int,int>,bool> ump;
    bool solve(int pos,int k)
       {
        if(pos==last) return true;
        if(k<=0||pos>last) return false;
        if(ump.find({pos,k})!=ump.end())
        {
               return ump[{pos,k}];
        }
        
        if(mp[pos]==1){
            return ump[{pos,k}] = solve(pos+k,k)||solve(pos+k-1,k-1)||solve(pos+k+1,k+1);
        }
        else {
          return ump[{pos,k}] = false;  
        }
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        last = stones[n-1];
        for(int it : stones){
            mp[it]=1;
        }
        if(stones[1]==1)
            return solve(1,1);
       
      return  false;  
    }
};
