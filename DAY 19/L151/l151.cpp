string reverseWords(string s) {
        int n = s.length();
        stack<string> st;
        
        string ans = "";
        for(int i = 0; i < n; i++){
            string temp = "";
            if(s[i] == ' '){
                continue;
            }
            while(s[i] != ' ' && i < n){
                temp += s[i];
                i++;
            }
            st.push(temp);
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
            if(!st.empty()){
                ans += " ";
            }
        }
        return ans;
    }
