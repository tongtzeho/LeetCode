class Solution {
public:

    void f(vector<string> &result, char *c, const int pos, const int len, const int leftbracnum, const int halflen)
    {
        if (pos == len)
        {
            if (leftbracnum == 0)
            {
                c[pos] = '\0';
                result.push_back(c);   
            }
            return;
        }
        else
        {
            if (leftbracnum < halflen)
            {
                c[pos] = '(';
                f(result, c, pos+1, len, leftbracnum+1, halflen);
            }
            if (leftbracnum > 0)
            {
                c[pos] = ')';
                f(result, c, pos+1, len, leftbracnum-1, halflen);
            }
        }
    }

    vector<string> generateParenthesis(int n) {
        char *newstring = new char[n*2+1];
        vector<string> result;
        f(result, newstring, 0, n*2, 0, n);
        return result;
    }
};