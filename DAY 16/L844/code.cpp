class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        for(auto i:s)
        {
            if(i!='#') s1.push(i);
            else if(!s1.empty()) s1.pop();
        }
        for(auto i:t)
        {
            if(i!='#') s2.push(i);
            else if(!s2.empty())
                s2.pop();
        }
        string x,y;
        x=y="";
        while(!s1.empty())
        {
            x+=s1.top();
            s1.pop();
        }
        while(!s2.empty())
        {
            y+=s2.top();
            s2.pop();
        }
        return (x==y)?true:false;
        
        
    }
};
