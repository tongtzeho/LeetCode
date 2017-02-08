class Solution {
public:

    vector<vector<string>> result;
    int endid, size, len;
    vector<int> *reach;
    unordered_set<int> unvisit, tmp;
    unordered_set<int>::iterator iter;
    int *path;
    int pathsize;
    int shortest;
    vector<string> addv;

    bool diffequal1(const string &st1, const string &st2)
    {
        int i, result = 0;
        for (i = 0; i < len; i++)
        {
            if (st1[i] != st2[i])
            {
                result++;
                if (result >= 2) return false;
            }
        }
        return result == 1;
    }
    
    void f(const int x, vector<string>& wordList)
    {
        int i;
        path[pathsize++] = x;
        if (pathsize == shortest)
        {
            for (i = 1; i < shortest-1; i++)
            {
                addv[i] = wordList[path[i]];
            }
            result.push_back(addv);
        }
        else
        {
            for (i = 0; i < reach[x].size(); i++)
            {
                f(reach[x][i], wordList);
            }
        }
        pathsize--;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        len = beginWord.length();
        size = wordList.size();
        endid = shortest = -1;
        int i, j, k;
        reach = new vector<int>[size+1];
        path = new int[size+1];
        for (i = 0; i < size; i++)
        {
            if (endWord == wordList[i])
            {
                endid = i;
            }
            else
            {
                unvisit.insert(i);
            }
        }
        if (endid == -1) return result;
        pathsize = 1;
        path[0] = endid;
        k = 1;
        while (pathsize > 0)
        {
            tmp.clear();
            k++;
            for (i = 0; i < pathsize; i++)
            {
                if (diffequal1(wordList[path[i]], beginWord))
                {
                    shortest = k;
                    reach[size].push_back(path[i]);
                }
            }
            if (shortest != -1) break;
            for (iter = unvisit.begin(); iter != unvisit.end(); iter++)
            {
                bool ins = false;
                for (i = 0; i < pathsize; i++)
                {
                    if (diffequal1(wordList[path[i]], wordList[*iter]))
                    {
                        reach[*iter].push_back(path[i]);
                        ins = true;
                    }
                }
                if (ins) tmp.insert(*iter);
            }
            pathsize = 0;
            for (iter = tmp.begin(); iter != tmp.end(); iter++)
            {
                path[pathsize++] = *iter;
                unvisit.erase(*iter);
            }
        }
        if (shortest == -1) return result;
        pathsize = 0;
        addv = vector<string>(shortest);
        addv[0] = beginWord;
        addv.back() = endWord;
        f(size, wordList);
        return result;
    }
};