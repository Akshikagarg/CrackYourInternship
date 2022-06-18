class Solution {
  
public:
    
    void helper(vector<string> &v,int n,int left, int right,string b){
        if(left == n and right == n){
            v.push_back(b);
            return;
        }
        else {
            if(left < n){
                helper(v,n,left+1,right,b + "(");
            }
            if(right < left){
                helper(v,n,left,right+1,b + ")");
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string b = "";
        helper(v,n,0,0,b);
        return v;
    }
};
