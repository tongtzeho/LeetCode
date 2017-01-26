class Solution {
public:

    bool **mem;

    bool f(const string &s, const string &p, const unsigned int x, const unsigned int y)
    {
        if (x >= s.length() && y >= p.length()) return true;
        if (y >= p.length()) return false;
        if (mem[x][y]) return false;
        mem[x][y] = true;
        if (p[y] == '.')
        {
            if (y == p.length()-1 || p[y+1] != '*') return x < s.length() && f(s, p, x+1, y+1);
            else return (x < s.length() && f(s, p, x+1, y)) || f(s, p, x, y+2) || (x < s.length() && f(s, p, x+1, y+2));
        }
        else
        {
            if (y == p.length()-1 || p[y+1] != '*') return x < s.length() && s[x] == p[y] && f(s, p, x+1, y+1);
            else return (x < s.length() && s[x] == p[y] && (f(s, p, x+1, y) || f(s, p, x+1, y+2))) || f(s, p, x, y+2);
        }
    }

    bool isMatch(string s, string p) {
        if (s.length() == 0 && p.length() == 0) return true;
        else if (p.length() == 0) return false;
        mem = new bool*[s.length()+1];
        int i, j;
        for (i = 0; i <= s.length(); i++)
        {
            mem[i] = new bool[p.length()];
            for (j = 0; j < p.length(); j++)
            {
                mem[i][j] = false;
            }
        }
        return f(s, p, 0, 0);
    }
};
