struct Counter {
public:
    int cnt[26];
    bool operator== (const Counter& c) const    
    {
        int i;
        for (i = 0; i < 26; i++)
        {
            if (cnt[i] != c.cnt[i]) return false;
        }
        return true;
    }
};

struct HashFunc  
{  
    size_t operator()(const Counter &c) const   
    {
        int result = 0, i;
        for (i = 0; i < 26; i++)
        {
            result += c.cnt[i]<<i;
        }
        return hash<int>()(result);
    }  
};

struct EqualKey  
{  
    bool operator () (const Counter &c1, const Counter &c2) const  
    {  
        int i;
        for (i = 0; i < 26; i++)
        {
            if (c1.cnt[i] != c2.cnt[i]) return false;
        }
        return true;
    }  
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<Counter, vector<string>, HashFunc, EqualKey> dict;
        unordered_map<Counter, vector<string>, HashFunc, EqualKey>::iterator iter;
        int i, j;
        int size = strs.size();
        int len;
        Counter c;
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < 26; j++)
            {
                c.cnt[j] = 0;
            }
            len = strs[i].length();
            for (j = 0; j < len; j++)
            {
                c.cnt[strs[i][j]-'a']++;
            }
            iter = dict.find(c);
            if (iter != dict.end())
            {
                iter->second.push_back(strs[i]);
            }
            else
            {
                dict.insert(pair<Counter, vector<string>>(c, vector<string>(1, strs[i])));
            }
        }
        vector<vector<string>> result(dict.size());
        i = 0;
        for (iter = dict.begin(); iter != dict.end(); iter++)
        {
            result[i++] = iter->second;
        }
        return result;
    }
};