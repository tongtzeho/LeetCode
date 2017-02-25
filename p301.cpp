class Solution {
public:

    unordered_set<string> resultset;
    unordered_set<string>::iterator iter;
    string addstring;
    char *src;
    bool *mem;
    int len;
    int leftcnt;
    int rightcnt;
    int removeleft;
    int removeright;

    void fromright2left(int pos, int stacksize, int removednum) {
        while (pos >= 0 && src[pos] != '(')
        {
            if (src[pos] == ')' && mem[pos])
            {
                stacksize++;
            }
            pos--;
        }
        if (pos < 0)
        {
            if (removednum == removeleft)
            {
                int i, j = 0;
                for (i = 0; i < len; i++)
                {
                    if (mem[i])
                    {
                        addstring[j++] = src[i];
                    }
                }
                resultset.insert(addstring);
            }
            return;
        }
        if (src[pos] == '(')
        {
            if (stacksize == 0)
            {
                if (removednum < removeleft)
                {
                    mem[pos] = false;
                    fromright2left(pos-1, 0, removednum+1);
                    mem[pos] = true;
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (removednum < removeleft)
                {
                    mem[pos] = false;
                    fromright2left(pos-1, stacksize, removednum+1);
                    mem[pos] = true;
                }
                fromright2left(pos-1, stacksize-1, removednum);
            }
        }
    }

    void fromleft2right(int pos, int stacksize, int removednum) {
        while (pos < len && src[pos] != ')')
        {
            if (src[pos] == '(')
            {
                stacksize++;
            }
            pos++;
        }
        if (pos == len)
        {
            if (removednum == removeright) fromright2left(len-1, 0, 0);
            return;
        }
        if (src[pos] == ')')
        {
            if (stacksize == 0)
            {
                if (removednum < removeright)
                {
                    mem[pos] = false;
                    fromleft2right(pos+1, 0, removednum+1);
                    mem[pos] = true;
                }
                else
                {
                    return;
                }
            }
            else
            {
                if (removednum < removeright)
                {
                    mem[pos] = false;
                    fromleft2right(pos+1, stacksize, removednum+1);
                    mem[pos] = true;
                }
                fromleft2right(pos+1, stacksize-1, removednum);
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        len = s.length();
        if (len == 0)
        {
            result.push_back("");
            return result;
        }
        src = new char[len];
        int i;
        removeright = 0;
        int stacksize = 0;
        for (i = 0; i < len; i++)
        {
            src[i] = s[i];
            if (src[i] == '(')
            {
                stacksize++;
            }
            else if (src[i] == ')')
            {
                if (stacksize == 0)
                {
                    removeright++;
                }
                else
                {
                    stacksize--;
                }
            }
        }
        removeleft = stacksize;
        leftcnt = rightcnt = 0;
        if (len-removeright-removeleft == 0)
        {
            result.push_back("");
            return result;
        }
        addstring = string(len-removeright-removeleft, ' ');
        mem = new bool[len];
        for (i = 0; i < len; i++)
        {
            mem[i] = true;
        }
        fromleft2right(0, 0, 0);
        result = vector<string>(resultset.size());
        i = 0;
        for (iter = resultset.begin(); iter != resultset.end(); iter++, i++)
        {
            result[i] = *iter;
        }
        return result;
    }
};