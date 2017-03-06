class Solution {
public:

    const char gene[4] = {'A', 'C', 'G', 'T'};
    string addv;

    vector<string> findRepeatedDnaSequences(string s) {
        addv = string(11, '\0');
        vector<string> result;
        unsigned dict[1<<20] = {0};
        int len = s.length();
        int digit = 0;
        int i = 0, j;
        for (i = 0; i < 10 && i < len; i++)
        {
            digit <<= 2;
            if (s[i] == 'C') digit++;
            else if (s[i] == 'G') digit += 2;
            else if (s[i] == 'T') digit += 3;
        }
        if (i == 10)
        {
            dict[digit] = 1;
            for ( ; i < len; i++)
            {
                digit = (digit & 0x3ffff) << 2;
                if (s[i] == 'C') digit++;
                else if (s[i] == 'G') digit += 2;
                else if (s[i] == 'T') digit += 3;
                if (dict[digit] == 1)
                {
                    dict[digit] = 2;
                    for (j = 0; j < 10; j++)
                    {
                        addv[j] = gene[(digit>>((9-j)<<1))&3];
                    }
                    result.push_back(addv);
                }
                else if (dict[digit] == 0)
                {
                    dict[digit] = 1;
                }
            }
        }
        return result;
    }
};
