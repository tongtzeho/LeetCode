class Solution {
public:

    unordered_set<int> notselect;
    unordered_set<int>::iterator iter, jter;
    int len;
    
    int getdiff(string &s1, string &s2) {
        int result = 0, i;
        for (i = 0; i < len; i++)
        {
            if (s1[i] != s2[i])
            {
                result++;
                if (result >= 2) return 2;
            }
        }
        return result;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        len = beginWord.length();
        int size = wordList.size();
        int endid = -1;
        int *oldarr = new int[size+1];
        int *newarr = new int[size+1];
        int *tmp;
        int oldsize = 0, newsize = 0;
        int i;
        for (i = 0; i < size; i++)
        {
            int diff = getdiff(beginWord, wordList[i]);
            if (diff == 1)
            {
                if (wordList[i] == endWord) return 2;
                oldarr[oldsize++] = i;
            }
            else if (diff == 2)
            {
                if (wordList[i] == endWord) endid = i;
                notselect.insert(i);
            }
        }
        int result = 2;
        while (oldsize > 0)
        {
            result++;
            newsize = 0;
            for (iter = notselect.begin(); iter != notselect.end(); )
            {
                for (i = 0; i < oldsize; i++)
                {
                    if (getdiff(wordList[*iter], wordList[oldarr[i]]) == 1)
                    {
                        if (*iter == endid) return result;
                        newarr[newsize++] = *iter;
                        jter = iter;
                        iter++;
                        notselect.erase(jter);
                        break;
                    }
                }
                if (i == oldsize)
                {
                    iter++;
                }
            }
            tmp = oldarr;
            oldarr = newarr;
            newarr = tmp;
            oldsize ^= newsize;
            newsize ^= oldsize;
            oldsize ^= newsize;
        }
        return 0;
    }
};
