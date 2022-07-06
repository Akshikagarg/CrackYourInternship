class NumMatrix {
public:
    vector<vector<int>> a;
    NumMatrix(vector<vector<int>>& matrix) {
        a=matrix;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j]=a[i][j]+a[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum=0;
        for(int i=row1;i<=row2;i++){
            int temp=0;
            if(col1-1>=0) temp=a[i][col1-1];
            sum+=a[i][col2]-temp;
        }
        return sum;
    }
};
