class Solution
{
    public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int len = INT_MAX;
        for(int i=0;i<strs.size();i++){
            int temp = strs[i].length();
            len = min(len, temp); // finding minimum length string in the vector
        }
        
        int start = 0;
        string ans = "";
        while(start < len){
            char ch = strs[0][start];
            for(int i=1;i<strs.size();i++){
                if(strs[i][start] != ch) // if characters don't match then we return the ans
                    return ans;
            }
            start++; // else, increment the start
            ans += ch; // and add character ch to ans string 
        }
        
        return ans;
        
    }
};
