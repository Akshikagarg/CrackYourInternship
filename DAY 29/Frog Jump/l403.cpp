class Solution{
    private:
    bool helper(vector<int>& stones,map<int,int>& m,int pos,int jump,vector<vector<int>>& dp){
        
        if(pos==stones.size()-1) 
            return true; //last rock reached 
        if(dp[pos][jump]!= -1)
            return dp[pos][jump];
        
        if(m.find(stones[pos]+jump)==m.end() || jump==0)
            return false; //rock not present 
        
        int nextPos=m[stones[pos]+jump]; //find the index of the rock after the jump
        
        //perform the three kind of jumps
        bool l=helper(stones,m,nextPos,jump-1,dp);
        bool c=helper(stones,m,nextPos,jump,dp);
        bool r=helper(stones,m,nextPos,jump+1,dp);
        
        if(!l && !c && !r)
            return dp[pos][jump]=0; //if all three jumps are not valid return false
        
        //if any jump is valid return true
        return dp[pos][jump]=1;

    }
    public:
    bool canCross(vector<int>& stones) 
    {
        map<int,int> m;
        for(int i=0;i<stones.size();i++)
            m[stones[i]]=i;
        
        vector<vector<int>> dp(stones.size()+1,vector<int>(stones.size()+1,-1)); 
        return helper(stones,m,0,1,dp);        
    }
    
};
