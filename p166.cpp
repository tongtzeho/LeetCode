class Solution {
public:

    unordered_map<long long, int> dict;
    unordered_map<long long, int>::iterator iter;

    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        dict.clear();
        char *result = (char*)malloc(sizeof(char)*10000);
        int pos = 0;
        long long a = numerator, b = denominator;
        if (a < 0 ^ b < 0) result[pos++] = '-';
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        sprintf (result+pos, "%lld", a/b);
        if (a % b == 0) return result;
        pos = strlen(result);
        result[pos++] = '.';
        a %= b;
        dict.insert(pair<long long, int>(a, pos));
        while (a > 0)
        {
            a = (a*10) % b;
            pos++;
            iter = dict.find(a);
            if (iter != dict.end())
            {
                int findpos = iter->second;
                result[findpos] = '(';
                result[pos+1] = ')';
                result[pos+2] = '\0';
                for (iter = dict.begin(); iter != dict.end(); iter++)
                {
                    if (iter->second >= findpos)
                    {
                        result[iter->second+1] = iter->first*10/b+'0';
                    }
                    else
                    {
                        result[iter->second] = iter->first*10/b+'0';
                    }
                }
                return result;
            }
            else
            {
                dict.insert(pair<long long, int>(a, pos));
            }
        }
        for (iter = dict.begin(); iter != dict.end(); iter++)
        {
            result[iter->second] = iter->first*10/b+'0';
        }
        result[pos] = '\0';
        return result;
    }
};