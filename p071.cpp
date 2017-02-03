class Solution {
public:
    string simplifyPath(string path) {
        vector<pair<int, int>> resultlst;
        int i = 0, j, len = path.length();
        int resultlen = 0;
        while (i < len)
        {
            j = i+1;
            while (j < len && path[j] != '/')
            {
                j++;
            }
            if (j > i+1)
            {
                if (j == i+3 && path[i+1] == '.' && path[i+2] == '.')
                {
                    if (!resultlst.empty())
                    {
                        resultlen -= resultlst.back().second;
                        resultlst.pop_back();
                    }
                }
                else if (j != i+2 || path[i+1] != '.')
                {
                    resultlst.push_back(pair<int, int>(i, j-i));
                    resultlen += j-i;
                }
            }
            i = j;
        }
        if (resultlst.empty()) return "/";
        else
        {
            string result(resultlen, '/');
            resultlen = 0;
            for (i = 0; i < resultlst.size(); i++)
                for (j = 0; j < resultlst[i].second; j++)
                    result[resultlen++] = path[resultlst[i].first+j];
            return result;
        }
    }
};