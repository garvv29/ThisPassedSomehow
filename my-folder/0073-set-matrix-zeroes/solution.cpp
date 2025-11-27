class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool colzero = false, rowzero = false;

        // Check first row
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[0][j] == 0) {
                rowzero = true;
                break;
            }
        }

        // Check first column
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] == 0) {
                colzero = true;
                break;
            }
        }

        // Mark rows & columns
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }

        // Fill matrix (except first row/col)
        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 1; j < matrix[0].size(); j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Zero out first row if needed
        if (rowzero) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[0][j] = 0;
            }
        }

        // Zero out first column if needed
        if (colzero) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][0] = 0;
            }
        }
    }
};

