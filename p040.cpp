class Solution {
public:

    set<int> *mem;

    bool f(const int *a, const int pos, const int target, const int len, vector<vector<int>> &result, vector<int> &s)
    {
        if (target == 0)
        {
            result.push_back(s);
            return true;
        }
        if (mem[pos].find(target) != mem[pos].end()) return false;
        bool ret = false;
        if (pos < len-1)
        {
            if (target >= a[pos+1])
            {
                s.push_back(a[pos+1]);
                ret |= f(a, pos+1, target-a[pos+1], len, result, s);
                s.pop_back();
            }
        }
        for (int i = pos+2; i < len; i++)
        {
            if (a[i] != a[i-1])
            {
                if (target >= a[i])
                {
                    s.push_back(a[i]);
                    ret |= f(a, i, target-a[i], len, result, s);
                    s.pop_back();
                }
                else
                {
                    break;
                }
            }
        }
        if (!ret) mem[pos].insert(target);
        return ret;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int len = candidates.size();
        int *a;
        vector<vector<int>> result;
        vector<int> s;
        if (len == 0) return result;
        a = new int[len];
        mem = new set<int>[len];
        for (int i = 0; i < len; i++)
        {
            a[i] = candidates[i];
        }
        sort(a, a+len);
        if (target >= a[0])
        {
            s.push_back(a[0]);
            f(a, 0, target-a[0], len, result, s);
            s.pop_back();
            for (int i = 1; i < len; i++)
                if (a[i] != a[i-1])
                {
                    if (target >= a[i])
                    {
                        s.push_back(a[i]);
                        f(a, i, target-a[i], len, result, s);
                        s.pop_back();
                    }
                    else
                    {
                        break;
                    }
                } 
        }
        return result;
    }
};