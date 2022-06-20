class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> res;
        unordered_map<string,vector<string>> S;
     
        for(auto s : strs)
        {
            string skey = s;
            sort(skey.begin(),skey.end());  
            S[skey].push_back(s);
        }
        
        for( auto vec : S)
        {
            res.push_back(vec.second);
        }
        return res;
    }
};
