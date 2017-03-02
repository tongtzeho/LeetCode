class Solution {
public:

    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int size = envelopes.size();
        if (!size) return 0;
        map<int, set<int>> autosort;
        map<int, set<int>>::iterator iter;
        set<int>::iterator jter;
        int i, j;
        for (i = 0; i < size; i++)
        {
            int w = envelopes[i].first;
            int h = envelopes[i].second;
            iter = autosort.find(w);
            if (iter == autosort.end())
            {
                autosort.insert(pair<int, set<int>>(w, set<int>()));
                autosort[w].insert(h);
            }
            else
            {
                iter->second.insert(h);
            }
        }
        int widthsize = autosort.size();
        int **height = (int**)malloc(sizeof(int*)*widthsize);
        int *heightsize = (int*)malloc(sizeof(int)*widthsize);
        i = 0;
        for (iter = autosort.begin(); iter != autosort.end(); iter++)
        {
            heightsize[i] = iter->second.size();
            height[i] = (int*)malloc(sizeof(int)*heightsize[i]);
            j = 0;
            for (jter = iter->second.begin(); jter != iter->second.end(); jter++)
            {
                height[i][j++] = *jter;
            }
            i++;
        }
        int result = 0;
        while (widthsize > 0)
        {
            int rightheight = 0;
            result++;
            for (i = widthsize-1; i >= 0; i--)
            {
                int newrightheight = height[i][heightsize[i]-1];
                if (newrightheight >= rightheight)
                {
                    for (j = heightsize[i]-1; j >= 0; j--)
                    {
                        if (height[i][j] >= rightheight)
                        {
                            heightsize[i]--;
                        }
                        else
                        {
                            break;
                        }
                    }
                    rightheight = newrightheight;
                }
            }
            while (widthsize > 0 && heightsize[widthsize-1] == 0)
            {
                widthsize--;
            }
        }
        return result;
    }
};
