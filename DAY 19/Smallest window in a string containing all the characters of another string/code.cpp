class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
         unordered_map<int,int>m;
        
        for(int i=0;i<p.size();i++)  m[p[i]]++;
        int count=m.size();
        int i=0;
        int mn=s.size();
        string ans="-1";
        for(int j=0;j<s.size();j++){
         if(m.find(s[j])!=m.end()){
             m[s[j]]--;
             if(m[s[j]]==0) count--;
         } 
         
         if(count==0)    {
            
            
          while(count==0)  {
               if(mn>j-i+1){
                ans=s.substr(i,j-i+1);
                mn=j-i+1;
             }
             if(m.find(s[i])!=m.end())  {
                 m[s[i]]++;
                 if(m[s[i]]==1) count++;
             }
             i++; 
         }
         }
        }
        
          return ans; 
        
    
    }
};
