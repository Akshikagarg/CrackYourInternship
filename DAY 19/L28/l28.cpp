class Solution {
public:

void computeLPS(string needle,vector<int>&lps)
{
    int length=0;
    int i=1;
    lps[0]=0;
    while(i<needle.size())
    {
        if(needle[i]==needle[length])  //compare char with its previous index
        {
            lps[i]=length+1;    // compute lps that contain length of longest prefix and suffix match
            length++;
            i++;
        }
        else
        {
            if(length!=0)        // if length is not zero then again compute lps of string before current index
            {
                length=lps[length-1];
            }
            else
            {
              lps[i]=0;          //if length is 0 then initialise lps of current index as 0 and increament i
                i++;   
            }
        }
    }
    
    
}
int strStr(string haystack, string needle)
{
    vector<int> lps(needle.size(),0);
    
    computeLPS(needle,lps);    // calling longest prefix sufix function
    int j=0;
    int i=0;
    while(i<haystack.size())
    {
        if(haystack[i]==needle[j])
        {
            i++; 
            j++;
        }
        else
        {
            if(j!=0)
                j=lps[j-1];
            else 
                i++;
        }
        if(j==needle.size()) 
            return i-needle.size();
    }
    return -1;
    
}
};
