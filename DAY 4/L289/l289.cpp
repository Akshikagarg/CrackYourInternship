class Solution {
public:
void gameOfLife(vector<vector<int>>& board) {
int m = board.size(), n = board[0].size();
for(int i=0;i<m;i++)
{
 for(int j=0;j<n;j++)
{
int cnt = 0;
if(i+1>=0 && i+1<m && board[i+1][j] > 0) cnt++;
if(i-1>=0 && i-1<m && board[i-1][j] > 0) cnt++;
if(i+1>=0 && i+1<m && j+1>=0 && j+1<n && board[i+1][j+1] > 0) cnt++;
if(i+1>=0 && i+1<m && j-1>=0 && j-1<n && board[i+1][j-1] > 0) cnt++;
if(i-1>=0 && i-1<m && j-1>=0 && j-1<n && board[i-1][j-1] > 0) cnt++;
if(i-1>=0 && i-1<m && j+1>=0 && j+1<n && board[i-1][j+1] > 0) cnt++;
if(j+1>=0 && j+1<n && board[i][j+1] > 0) cnt++;
if(j-1>=0 && j-1<n && board[i][j-1] > 0) cnt++;
if(board[i][j] == 1 && (cnt < 2 || cnt > 3)) board[i][j] = 2;
else if(board[i][j] == 0 && cnt == 3) board[i][j] = -1;
}
}
for(int i=0;i<m;i++)
{
 for(int j=0;j<n;j++)
{
if(board[i][j] == 2) board[i][j] = 0;
else if(board[i][j] == -1) board[i][j] = 1;
}
}
}
};
