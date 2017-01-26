struct MyPoint {
    int x, y;
};

/*bool cmp(const MyPoint &p1, const MyPoint &p2)
{
    return p1.y > p2.y;
}*/

int cmp (const void *p1, const void *p2) {
    return (*(MyPoint*)p2).y - (*(MyPoint*)p1).y;
}

class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        MyPoint *p = new MyPoint[size];
        int i;
        for (i = 0; i < size; i++)
        {
            p[i].x = i;
            p[i].y = height[i];
        }
        //sort(p, p+size, cmp);
        qsort(p, height.size(), sizeof(p[0]), cmp);
        int l = p[0].x<p[1].x?p[0].x:p[1].x;
        int r = p[0].x+p[1].x-l;
        int result = p[1].y*(r-l);
        for (i = 2; i < size; i++)
        {
            if (p[i].x < l) l = p[i].x;
            else if (p[i].x > r) r = p[i].x;
            if (p[i].y*(r-l) > result)
            {
                result = p[i].y*(r-l);
            }
            if ((p[i].y-1)*size <= result) return result;
        }
        return result;
    }
};
