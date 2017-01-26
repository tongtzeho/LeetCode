class Solution {
public:

    int *place;
    bool *y0;
    bool *yx;
    bool *y_x;
    string emptyboard;

    void f(vector<vector<string>> &result, const int n, const int p)
    {
        int i;
        if (n == p)
        {
            vector<string> str(n, emptyboard);
            for (i = 0; i < n; i++)
            {
                str[i][place[i]] = 'Q';
            }
            result.push_back(str);
            if (place[0] < n>>1)
            {
                vector<string> str;
                for (i = 0; i < n; i++)
                {
                    str.push_back(emptyboard);
                }
                for (i = 0; i < n; i++)
                {
                    str[i][n-1-place[i]] = 'Q';
                }
                result.push_back(str);
            }
        }
        for (i = 0; i < n; i++)
        {
            if ((!y0[i]) && (!yx[i+p]) && (!y_x[i-p+(n-1)]))
            {
                place[p] = i;
                y0[i] = true;
                yx[i+p] = true;
                y_x[i-p+(n-1)] = true;
                f(result, n, p+1);
                y_x[i-p+(n-1)] = false;
                yx[i+p] = false;
                y0[i] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        if (n == 0) return result;
        place = new int[n];
        y0 = new bool[n];
        yx = new bool[(n<<1)+1];
        y_x = new bool[(n<<1)+1];
        int i;
        emptyboard = "";
        for (i = 0; i < n; i++)
        {
            emptyboard += ".";
            y0[i] = false;
        }
        for (i = 0; i < (n<<1)+1; i++)
        {
            yx[i] = y_x[i] = false;
        }
        for (i = 0; i < (n+1)>>1; i++)
        {
            place[0] = i;
            y0[i] = true;
            yx[i] = true;
            y_x[i+n-1] = true;
            f(result, n, 1);
            y_x[i+n-1] = false;
            yx[i] = false;
            y0[i] = false;
        }
        return result;
    }
};