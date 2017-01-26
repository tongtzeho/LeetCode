class Solution {
public:

    const char d2s[10][6] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    const unsigned len[10] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};

    void f(unsigned pos, string &digits, vector<string> &result, string curstring)
    {
        for (int i = 0; i < len[digits[pos]-'0']; i++)
        {
            if (pos == digits.length()-1) result.push_back(curstring+d2s[digits[pos]-'0'][i]);
            else f(pos+1, digits, result, curstring+d2s[digits[pos]-'0'][i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.length() == 0) return result;
        f(0, digits, result, "");
        return result;
    }
};