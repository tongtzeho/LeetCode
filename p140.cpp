class Solution {
public:
    vector<int> *reach;
    vector<string> result;
    int *split;
    int splitsize;
    unordered_set<string> dict;
    int len;
    char *str;
    bool *mem;
    
    void f(const int x)
    {
        int i, j = 1, k = 0;
        split[splitsize++] = x;
        if (x == len)
        {
            string addv(len+splitsize-2, ' ');
            for (i = 0; i < len; i++)
            {
                if (i == split[j])
                {
                    j++;
                    k++;
                }
                addv[k++] = str[i];
            }
            result.push_back(addv);
        }
        else
        {
            k = reach[x].size();
            for (i = 0; i < k; i++)
            {
                if (mem[reach[x][i]]) f(reach[x][i]);
            }
        }
        splitsize--;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        len = s.length();
        if (!len) return result;
        int size = wordDict.size();
        if (!size) return result;
        int i, j;
        for (i = 0; i < size; i++)
        {
            dict.insert(wordDict[i]);
        }
        str = new char[len];
        reach = new vector<int>[len];
        mem = new bool[len+1];
        for (i = 1; i <= len; i++)
        {
            mem[i] = false;
        }
        mem[0] = true;
        for (i = 0; i < len; i++)
        {
            str[i] = s[i];
            if (!mem[i])
            {
                continue;
            }
            for (j = 1; j <= len-i; j++)
            {
                if (dict.find(s.substr(i, j)) != dict.end())
                {
                    reach[i].push_back(i+j);
                    mem[i+j] = true;
                }
            }
        }
        if (!mem[len]) return result;
        for (i = len-1; i >= 0; i--)
        {
            if (!mem[i])
            {
                continue;
            }
            size = reach[i].size();
            mem[i] = false;
            for (j = 0; j < size; j++)
            {
                if (mem[reach[i][j]])
                {
                    mem[i] = true;
                    break;
                }
            }
        }
        split = new int[len+1];
        splitsize = 0;
        f(0);
        return result;
    }
};