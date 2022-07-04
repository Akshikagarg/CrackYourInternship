class Solution {
public:
    int countSquares(vector<vector<int>>& m) {
        
        for(int i = 1; i < m.size(); i++)
        {
            for(int j = 1; j < m[0].size(); j++)
            {
                if(m[i][j] == 1)
                {
                    m[i][j] = min(m[i-1][j], min( m[i-1][j-1], m[i][j-1]))+1;
                }
            }
        }
        int res = 0;
        for(int i = 0; i < m.size(); i++)
        {
            for(int j = 0; j < m[0].size(); j++)
            {
                res += m[i][j];
            }
        }
        return res;
    }
};
