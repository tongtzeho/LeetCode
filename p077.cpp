class Solution {
public:

    int *tmp;
    
    void f(vector<vector<int>> &result, const int n, const int k, int *index, const int pos, const int val)
    {
        if (pos == k)
        {
            for (int i = 0; i < k; i++)
            {
                result[*index][i] = tmp[i];
            }
            (*index)++;
            return;
        }
        for (int i = val; i <= n-k+pos+1; i++)
        {
            tmp[pos] = i;
            f(result, n, k, index, pos+1, i+1);
        }
    }    

    vector<vector<int>> combine(int n, int k) {
        int size;
        if (n == 0)
        {
            return vector<vector<int>>();
        }
        size = 1;
        int i, j;
        for (i = 1; i <= k; i++)
            size = (size)*(n-k+i)/i;
        vector<vector<int>> result(size, vector<int>(k));
        if (k == 0)
        {
            return result;
        }
        tmp = (int*)malloc(sizeof(int)*k);
        i = 0;
        f(result, n, k, &i, 0, 1);
        return result;
    }
};