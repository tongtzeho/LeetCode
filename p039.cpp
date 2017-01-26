class Solution {
public:

    vector<vector<int>> result;
    int len;
    int *num;
    int *multi;

    void f(int target, int pos) {
        if (target == 0)
        {
            int newlen = 0;
            for (int i = 0; i < pos; i++)
            {
                newlen += multi[i];
            }
            vector<int> newv(newlen);
            newlen = 0;
            for (int i = 0; i < pos; i++)
                for (int j = 0; j < multi[i]; j++)
                    newv[newlen++] = num[i];
            result.push_back(newv);
            return;
        }
        if (pos >= len)
        {
            return;
        }
        f(target, pos+1);
        int val = num[pos];
        target -= val;
        while (target >= 0)
        {
            multi[pos]++;
            f(target, pos+1);
            target -= val;
        }
        multi[pos] = 0;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        len = candidates.size();
        num = new int[len];
        multi = new int[len];
        for (int i = 0; i < len; i++)
        {
            num[i] = candidates[i];
            multi[i] = 0;
        }
        f(target, 0);
        return result;
    }
};