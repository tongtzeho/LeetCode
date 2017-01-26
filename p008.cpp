class Solution {
public:
    int myAtoi(string str) {
        long long result = 0;
        int i;
        for (i = 0; i < str.length(); i++)
        {
            if (str[i] == ' ') continue;
            else if (str[i] == '-' || str[i] == '+' || (str[i] >= '0' && str[i] <= '9')) break;
            else return 0;
        }
        if (i == str.length()) return 0;
        if (str[i] == '-')
        {
            i++;
            for (; i < str.length(); i++)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    result = (result<<3)+(result<<1)-(str[i]-'0');
                    if (result < -2147483648) return -2147483648;
                }
                else
                {
                    return result;
                }
            }
            return result;
        }
        else
        {
            if (str[i] == '+') i++;
            for (; i < str.length(); i++)
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    result = (result<<3)+(result<<1)+(str[i]-'0');
                    if (result > 2147483647) return 2147483647;
                }
                else
                {
                    return result;
                }
            }
            return result;
        }
    }
};
