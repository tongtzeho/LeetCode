class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        vector<pair<int, int>> v[2];
        v[0].push_back(pair<int, int>(1, 1));
        int i, j;
        for (i = 3; i <= n; i++)
        {
            vector<pair<int, int>> *dst = &v[i&1], *src = &v[(i+1)&1];
            dst->clear();
            int val = (*src)[0].first;
            int cnt = 0;
            for (j = 0; j < src->size(); j++)
            {
                if (val == (*src)[j].first)
                {
                    cnt++;
                }
                else
                {
                    dst->push_back(pair<int, int>(cnt, val));
                    val = (*src)[j].first;
                    cnt = 1;
                }
                if (val == (*src)[j].second)
                {
                    cnt++;
                }
                else
                {
                    dst->push_back(pair<int, int>(cnt, val));
                    val = (*src)[j].second;
                    cnt = 1;
                }
            }
            dst->push_back(pair<int, int>(cnt, val));
        }
        int len = v[n&1].size()*2;
        char *result = new char[len+1];
        result[len] = '\0';
        for (i = 0; i < len>>1; i++)
        {
            result[(i<<1)] = v[n&1][i].first+'0';
            result[(i<<1)+1] = v[n&1][i].second+'0';
        }
        return result;
    }
};