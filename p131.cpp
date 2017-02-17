class Solution {
public:

    vector<vector<string>> result;
    vector<string> cur;
    vector<int> *jumpto;
    bool *success;
    int *size;

    void f(const string &s, const int x, const int len) {
        if (x == len)
        {
            result.push_back(cur);
            return;
        }
        int i;
        for (i = 0; i < size[x]; i++)
        {
            cur.push_back(s.substr(x, jumpto[x][i]-x));
            f(s, jumpto[x][i], len);
            cur.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        result.clear();
        cur.clear();
        int len = s.length();
        if (!len) return result;
        jumpto = new vector<int>[len];
        success = new bool[len+1];
        size = new int[len];
        int i, j, k;
        for (i = 0; i < len; i++)
        {
            success[i] = false;
        }
        success[i] = true;
        for (i = len-1; i >= 0; i--)
        {
            for (j = len; j > i; j--)
            {
                if (success[j])
                {
                    for (k = i; k < (i+j)>>1; k++)
                    {
                        if (s[k] != s[i+j-k-1])
                        {
                            break;
                        }
                    }
                    if (k == (i+j)>>1)
                    {
                        success[i] = true;
                        jumpto[i].push_back(j);
                    }
                }
            }
        }
        if (success[0])
        {
            for (i = 0; i < len; i++)
            {
                if (success[i])
                {
                    size[i] = jumpto[i].size();
                }
            }
            f(s, 0, len);
        }
        return result;
    }
};
