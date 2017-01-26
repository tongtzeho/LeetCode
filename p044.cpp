class Solution {
public:
    bool isMatch(string s, string p) {
        int l1 = s.length();
        int l2 = p.length();
        vector<pair<int, int>> starstr;
        int i, j, k;
        int begin = -1;
        int end = -1;
        for (i = 0; i < l2; i++)
        {
            if (p[i] == '*')
            {
                end = i;
                if (begin == -1) begin = i;
            }
            else
            {
                if (end != -1)
                {
                    starstr.push_back(pair<int, int>(begin, end));
                    begin = end = -1;
                }
            }
        }
        if (end != -1)
        {
            starstr.push_back(pair<int, int>(begin, end));
        }
        if (starstr.empty())
        {
            if (l1 != l2) return false;
            for (i = 0; i < l1; i++)
            {
                if (p[i] != '?' && s[i] != p[i]) return false;
            }
            return true;
        }
        if (l1 < starstr[0].first) return false;
        for (i = 0; i < starstr[0].first; i++)
        {
            if (p[i] != '?' && s[i] != p[i]) return false;
        }
        if (l1 < starstr[0].first+l2-starstr.back().second-1) return false;
        for (i = starstr.back().second+1; i < l2; i++)
        {
            if (p[i] != '?' && s[i-l2+l1] != p[i]) return false;
        }
        int nextbegin = starstr[0].first, nextend = l1-l2+starstr.back().second+1;
        for (i = 0; i < starstr.size()-1; i++)
        {
            string pat = p.substr(starstr[i].second+1, starstr[i+1].first-starstr[i].second-1);
            string str = s.substr(nextbegin, nextend-nextbegin);
            //printf ("%d %d %d %d %s %s\n", starstr[i].second, starstr[i+1].first, nextbegin, nextend, str.c_str(), pat.c_str());
            for (j = 0; j < str.length(); j++)
            {
                for (k = 0; k < pat.length(); k++)
                {
                    if (j+k >= str.length() || (pat[k] != '?' && str[j+k] != pat[k])) break;
                }
                if (k == pat.length()) break;
            }
            if (j == str.length()) return false;
            nextbegin += j+pat.length();
        }
        return true;
    }
};