class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (words.empty() || !words[0].length()) return result;
        int size = words.size();
        int len = words[0].length();
        int slen = s.length()-len;
        unordered_map<string, int*> dict;
        int i, j, backlen = (size-1)*len, k = 0;
        int *tmp;
        int *zeronum = new int[len];
        int dictsize;
        for (i = 0; i < len; i++)
        {
            zeronum[i] = 0;
        }
        for (i = 0; i < size; i++)
        {
            if (dict.find(words[i]) == dict.end())
            {
                dict.insert(pair<string, int*>(words[i], new int[len]));
                tmp = dict[words[i]];
                for (j = 0; j < len; j++)
                    tmp[j] = 1;
            }
            else
            {
                tmp = dict[words[i]];
                for (j = 0; j < len; j++)
                    tmp[j]++;
            }
        }
        dictsize = dict.size();
        for (i = 0; i <= slen; i++)
        {
            string sub2 = s.substr(i, len);
            if (dict.find(sub2) != dict.end())
            {
                if (dict[sub2][k]-- == 0) zeronum[k]--;
                if (dict[sub2][k] == 0) zeronum[k]++;
                if (zeronum[k] == dictsize)
                {
                    result.push_back(i-backlen);
                }
            }
            if (i-backlen >= 0)
            {
                string sub1 = s.substr(i-backlen, len);
                if (dict.find(sub1) != dict.end())
                {
                    if (dict[sub1][k]++ == 0) zeronum[k]--;
                    if (dict[sub1][k] == 0) zeronum[k]++;
                }
            }
            k++;
            if (k == len)
            {
                k = 0;
            }
        }
        return result;
    }
};