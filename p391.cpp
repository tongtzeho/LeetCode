struct Rectangle {
    int left, down, right, up;
};

int cmp(const void *a, const void *b)
{
    Rectangle *ra = (Rectangle*)a, *rb = (Rectangle*)b;
    if (ra->left != rb->left) return ra->left-rb->left;
    if (ra->down != rb->down) return ra->down-rb->down;
    return ra->right-rb->right;
}

class LineTree {
public:
    map<int, pair<int, int>> tree;
    map<int, pair<int, int>>::iterator iter, jter;
    bool check(int down, int up, int left)
    {
        iter = tree.find(down);
        if (iter == tree.end()) return false;
        if (iter->second.second != left) return false;
        if (iter->second.first < up) return false;
        else if (iter->second.first == up)
        {
            tree.erase(iter);
        }
        else
        {
            tree.insert(pair<int, pair<int, int>>(up, pair<int, int>(iter->second.first, left)));
            tree.erase(iter);
        }
        return true;
    }
    void add(int down, int up, int right)
    {
        tree.insert(pair<int, pair<int, int>>(down, pair<int, int>(up, right)));
        jter = iter = tree.find(down);
        if (jter != tree.begin())
        {
            jter--;
            if (jter->second.second == right)
            {
                jter->second.first = up;
                tree.erase(iter);
                iter = jter;
            }
            else
            {
                jter = iter;
            }
        }
        jter++;
        if (jter != tree.end() && jter->second.second == right)
        {
            iter->second.first = jter->second.first;
            tree.erase(jter);
        }
    }
};

class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        LineTree tree;
        int size = rectangles.size();
        struct Rectangle *rect = (struct Rectangle*)malloc(sizeof(struct Rectangle)*size);
        int i;
        for (i = 0; i < size; i++)
        {
            rect[i].left = rectangles[i][0];
            rect[i].down = rectangles[i][1];
            rect[i].right = rectangles[i][2];
            rect[i].up = rectangles[i][3];
        }
        qsort(rect, size, sizeof(rect[0]), cmp);
        int minleft = rect[0].left;
        int maxtop = rect[0].down;
        i = 0;
        while (i < size && rect[i].left == minleft)
        {
            if (rect[i].down == maxtop)
            {
                tree.add(rect[i].down, rect[i].up, rect[i].right);
                maxtop = rect[i].up;
            }
            else
            {
                return false;
            }
            i++;
        }
        for ( ; i < size; i++)
        {
            if (!tree.check(rect[i].down, rect[i].up, rect[i].left))
            {
                return false;
            }
            tree.add(rect[i].down, rect[i].up, rect[i].right);
        }
        return tree.tree.size() == 1;
    }
};
