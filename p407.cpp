class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int r = heightMap.size();
        if (r == 0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mem;
        int result = 0;
        int maxbound = 0;
        int c = heightMap[0].size();
        int **height = (int**)malloc(sizeof(int*)*r);
        int i, j;
        for (i = 0; i < r; i++)
        {
            height[i] = (int*)malloc(sizeof(int)*c);
            for (j = 0; j < c; j++)
            {
                height[i][j] = heightMap[i][j];
            }
        }
        for (i = 0; i < r; i++)
        {
            mem.push(pair<int, int>(height[i][0], i*c));
            height[i][0] = -1;
            mem.push(pair<int, int>(height[i][c-1], i*c+c-1));
            height[i][c-1] = -1;
        }
        for (j = 1; j < c-1; j++)
        {
            mem.push(pair<int, int>(height[0][j], j));
            height[0][j] = -1;
            mem.push(pair<int, int>(height[r-1][j], (r-1)*c+j));
            height[r-1][j] = -1;
        }
        while (!mem.empty())
        {
            int h = mem.top().first;
            int x = mem.top().second/c;
            int y = mem.top().second%c;
            mem.pop();
            if (h > maxbound)
            {
                maxbound = h;
            }
            if (x > 0 && height[x-1][y] >= 0)
            {
                mem.push(pair<int, int>(height[x-1][y], (x-1)*c+y));
                if (height[x-1][y] < maxbound)
                {
                    result += maxbound-height[x-1][y];
                }
                height[x-1][y] = -1;
            }
            if (x < r-1 && height[x+1][y] >= 0)
            {
                mem.push(pair<int, int>(height[x+1][y], (x+1)*c+y));
                if (height[x+1][y] < maxbound)
                {
                    result += maxbound-height[x+1][y];
                }
                height[x+1][y] = -1;
            }
            if (y > 0 && height[x][y-1] >= 0)
            {
                mem.push(pair<int, int>(height[x][y-1], x*c+y-1));
                if (height[x][y-1] < maxbound)
                {
                    result += maxbound-height[x][y-1];
                }
                height[x][y-1] = -1;
            }
            if (y < c-1 && height[x][y+1] >= 0)
            {
                mem.push(pair<int, int>(height[x][y+1], x*c+y+1));
                if (height[x][y+1] < maxbound)
                {
                    result += maxbound-height[x][y+1];
                }
                height[x][y+1] = -1;
            }
        }
        return result;
    }
};