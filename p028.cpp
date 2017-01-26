class Solution {
public: 
    int strStr(string haystack, string needle) {
        int hl = haystack.length();
        int nl = needle.length();
        if (nl == 0) return 0;
        if (nl > hl) return -1;
        int *next = new int[nl];
        next[0] = -1;
        int i, j, k;
        j = 0;
        k = -1;
        while (j < nl-1)
        {
            if (k == -1 || needle[j] == needle[k])
            {
                j++;
                k++;
                next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
        i = j = 0;
        while (i < hl)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                i++;
                j++;
                if (j == nl) return i-nl;
            }
            else
            {
                j = next[j];
            }
        }
        return -1;
    }
};
