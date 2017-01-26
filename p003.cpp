class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if (len == 0) return 0;
        bool used[256] = {0};
        int lastend = 0;
        int i, j;
        used[s[0]] = true;
        for (i = 1; i < len; i++)
        {
            if (!used[s[i]])
            {
                lastend = i;
                used[s[i]] = true;
            }
            else
            {
                break;
            }
        }
        int result = lastend+1;
        if (i == len) return result;
        for (i = 1; i < len; i++)
        {
            used[s[i-1]] = false;
            if (lastend < i)
            {
                lastend = i;
                used[s[i]] = true;
            }
            for (j = lastend+1; j < len; j++)
            {
                if (!used[s[j]])
                {
                    lastend = j;
                    used[s[j]] = true;
                }
                else
                {
                    break;
                }
            }
            if (lastend-i+1 > result)
            {
                result = lastend-i+1;
            }
            if (result >= len-i-1) return result;
        }
        return result;
    }
};
