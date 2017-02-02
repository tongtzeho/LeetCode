class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int left = 0, right, i, j, k;
        int lencnt, wordcnt, tmplen;
        int size = words.size();
        vector<string> result;
        string addstr(maxWidth, ' ');
        while (left < size)
        {
            for (i = 0; i < maxWidth; i++)
            {
                addstr[i] = ' ';
            }
            lencnt = wordcnt = 0;
            for (right = left; right < size; right++)
            {
                tmplen = words[right].length();
                if (lencnt+tmplen+wordcnt <= maxWidth)
                {
                    lencnt += tmplen;
                    wordcnt++;
                }
                else
                {
                    break;
                }
            }
            if (wordcnt == 1)
            {
                for (i = 0; i < words[left].length(); i++)
                {
                    addstr[i] = words[left][i];
                }
            }
            else if (right == size)
            {
                k = 0;
                for (i = left; i < right; i++)
                {
                    for (j = 0; j < words[i].length(); j++)
                    {
                        addstr[k++] = words[i][j];
                    }
                    k++;
                }
            }
            else
            {
                int rightslot = (maxWidth-lencnt)/(wordcnt-1);
                int leftslot = rightslot+1;
                int leftslotcnt = maxWidth-lencnt-rightslot*(wordcnt-1);
                k = 0;
                for (i = left; i < right; i++)
                {
                    for (j = 0; j < words[i].length(); j++)
                    {
                        addstr[k++] = words[i][j];
                    }
                    if (i-left < leftslotcnt)
                    {
                        k += leftslot;
                    }
                    else
                    {
                        k += rightslot;
                    }
                }
            }
            result.push_back(addstr);
            left = right;
        }
        return result;
    }
};