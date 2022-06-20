class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int k=t.size();
        unordered_map<char,int>m;
        if(n<k){
            return "";
        }
        for(int i=0;i<k;i++){
            m[t[i]]++;
        }
        int left=0;
        int right=0;
        int pos=0;
        int cnt=t.size();
        int size=INT_MAX;
        for(right=0;right<n;right++)
        {
            if(m[s[right]]>0)
            {
                cnt--;
            }
            m[s[right]]--;
            while(cnt==0)
            {
                if(right-left+1<size)
                { //finding min substring
                    size=right-left+1;
                    pos=left;
                }
                m[s[left]]++;
                if(m[s[left]]>0) cnt++;
                left++;
            }
        }
        if(size==INT_MAX){ //If there is no satisfying case
            return "";
        }
        
        string ans=s.substr(pos,size);
        return ans;
    }
};
