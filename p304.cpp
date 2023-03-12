class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = (int)matrix.size();
        n = (int)matrix[0].size();
        const std::vector<int>& line0 = matrix[0];
        sum[0] = line0[0];
        for (int j = 1; j < n; ++j)
        {
            sum[j] = sum[j - 1] + line0[j];
        }
        for (int i = 1; i < m; ++i)
        {
            const std::vector<int>& line = matrix[i];
            int lineBase = i * n;
            sum[lineBase] = sum[lineBase - n] + line[0];
            for (int j = 1; j < n; ++j)
            {
                int index = lineBase + j;
                sum[index] = line[j] - sum[index - 1 - n] + sum[index - n] + sum[index - 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        --row1;
        --col1;
        if (row1 >= 0)
        {
            if (col1 >= 0)
                return sum[row1 * n + col1] - sum[row1 * n + col2] - sum[row2 * n + col1] + sum[row2 * n + col2];
            else
                return sum[row2 * n + col2] - sum[row1 * n + col2];
        }
        else
        {
            if (col1 >= 0)
                return sum[row2 * n + col2] - sum[row2 * n + col1];
            else
                return sum[row2 * n + col2];
        }
    }

private:
    int sum[40001];
    int n;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */