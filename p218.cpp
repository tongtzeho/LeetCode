class Solution {
public:

    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int, int>> result;
        int size = buildings.size();
        if (!size)
        {
            return result;
        }
        multiset<int> height;
        multiset<int>::iterator iter;
        map<int, vector<int>> right_height;
        map<int, vector<int>>::iterator jter;
        int i, j, k = 0, sizetmp;
        int prevheight = 0, curheight;
        for (i = 0; i < size; i++)
        {
            right_height.insert(pair<int, vector<int>>(buildings[i][0], vector<int>()));
            right_height.insert(pair<int, vector<int>>(buildings[i][1], vector<int>()));
        }
        for (jter = right_height.begin(); jter != right_height.end(); jter++)
        {
            sizetmp = jter->second.size();
            for (j = 0; j < sizetmp; j++)
            {
                iter = height.find((jter->second)[j]);
                height.erase(iter);
            }
            while (k < size && buildings[k][0] == jter->first)
            {
                height.insert(buildings[k][2]);
                right_height[buildings[k][1]].push_back(buildings[k][2]);
                k++;
            }
            if (height.empty())
            {
                curheight = 0;
            }
            else
            {
                iter = height.end();
                iter--;
                curheight = *iter;
            }
            if (curheight != prevheight)
            {
                result.push_back(pair<int, int>(jter->first, curheight));
                prevheight = curheight;
            }
        }
        return result;
    }
};