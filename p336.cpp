class Solution {
public:

    bool ispalin(string &str, int x, int y) {
        while (y > x)
        {
            if (str[x] != str[y])
            {
                return false;
            }
            x++;
            y--;
        }
        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<int> addv(2, 0);
        vector<vector<int>> result;
        int i, j;
        int size = words.size();
        int *len = (int*)malloc(sizeof(int)*size);
        for (i = 0; i < size; i++)
        {
            len[i] = words[i].length();
        }
        for (i = 0; i < size; i++)
        {
            for (j = 0; j < size; j++)
            {
                if (i != j)
                {
                    int i1, j1;
                    if (len[i] > len[j])
                    {
                        i1 = 0;
                        j1 = len[j]-1;
                        while (j1 >= 0)
                        {
                            if (words[i][i1] != words[j][j1])
                            {
                                break;
                            }
                            i1++;
                            j1--;
                        }
                        if (j1 < 0 && ispalin(words[i], len[j], len[i]-1))
                        {
                            addv[0] = i;
                            addv[1] = j;
                            result.push_back(addv);
                        }
                    }
                    else if (len[i] < len[j])
                    {
                        i1 = 0;
                        j1 = len[j]-1;
                        while (i1 < len[i])
                        {
                            if (words[i][i1] != words[j][j1])
                            {
                                break;
                            }
                            i1++;
                            j1--;
                        }
                        if (i1 == len[i] && ispalin(words[j], 0, len[j]-len[i]-1))
                        {
                            addv[0] = i;
                            addv[1] = j;
                            result.push_back(addv);
                        }
                    }
                    else if (i < j)
                    {
                        i1 = 0;
                        j1 = len[j]-1;
                        while (j1 >= 0)
                        {
                            if (words[i][i1] != words[j][j1])
                            {
                                break;
                            }
                            i1++;
                            j1--;
                        }
                        if (j1 < 0)
                        {
                            addv[0] = i;
                            addv[1] = j;
                            result.push_back(addv);
                            addv[0] = j;
                            addv[1] = i;
                            result.push_back(addv);
                        }
                    }
                }
            }
        }
        return result;
    }
};
