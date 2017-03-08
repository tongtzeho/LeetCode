class Solution {
public:

    vector<vector<int>> result;
    vector<int> addv;
    int sum;
    int k;

    void f(int cursize, int cursum, int curbig) {
        if ((((19-k+cursize) * (k-cursize)) >> 1) + cursum < sum) return;
        if (((((curbig << 1) + k + 1 - cursize) * (k - cursize)) >> 1) + cursum > sum) return;
        if (cursize == k-1)
        {
            addv[cursize] = sum-cursum;
            result.push_back(addv);
            return;
        }
        int i;
        for (i = curbig+1; i <= 10-k+cursize; i++)
        {
            addv[cursize] = i;
            f(cursize+1, cursum+i, i);
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        result.clear();
        addv = vector<int>(k, 0);
        sum = n;
        this->k = k;
        f(0, 0, 0);
        return result;
    }
};
