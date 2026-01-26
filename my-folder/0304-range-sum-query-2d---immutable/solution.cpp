class NumMatrix {
    vector<vector<int>> summ;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        summ=vector<vector<int>>(r+1,vector<int>(c+1,0));

        for(int i=0;i<r;i++)
        {
            int prefix=0;
            for(int j=0;j<c;j++)
            {
                prefix+=matrix[i][j];
                int above= summ[i][j+1];
                summ[i+1][j+1]=prefix+above;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        row1++;
        col1++;
        row2++;
        col2++;
        int br = summ[row2][col2];
        int a = summ[row1-1][col2];
        int l = summ[row2][col1-1];
        int tl = summ[row1-1][col1-1];
        return br-a-l+tl;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
