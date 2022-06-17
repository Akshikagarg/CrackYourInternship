class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& a, int n) 
    {
        // code here 
        int c=0;
        for(int i=0;i<n;i++)
        {
            if(a[c][i]==1) c=i;
        }
        for(int i=0;i<n;i++)
        {
            if(i!=c && (a[c][i]==1 || a[i][c]==0)) return -1;
        }
        return c;
    }
};
