class Solution {
public:

    vector<string> result;
    
    char *original;
    char *expression;
    int len;
    long long *stack;
    char *ops;
    int stacksize;

    long long calculate() {
        stacksize = 0;
        int i;
        char prevops = '\0';
        long long tmp = 0;
        for (i = 0; ; i++)
        {
            if (expression[i] >= '0' && expression[i] <= '9')
            {
                tmp = (tmp<<3)+(tmp<<1)+expression[i]-'0';
            }
            else
            {
                if (prevops != '*')
                {
                    ops[stacksize] = prevops;
                    stack[stacksize++] = tmp;
                }
                else
                {
                    stack[stacksize-1] *= tmp;
                }
                tmp = 0;
                if (expression[i] == '\0') break;
                prevops = expression[i];
            }
        }
        tmp = stack[0];
        for (i = 1; i < stacksize; i++)
        {
            if (ops[i] == '+') tmp += stack[i];
            else tmp -= stack[i];
        }
        return tmp;
    }

    void f(const int x, const int y, const int z) {
        if (x == len)
        {
            expression[y] = '\0';
            if (calculate() == z)
            {
                result.push_back(expression);
            }
            return;
        }
        if (x == 0)
        {
            expression[y] = original[x];
            f(x+1, y+1, z);
        }
        else
        {
            if (expression[y-1] != '0' || (y >= 2 && expression[y-2] != '+' && expression[y-2] != '-' && expression[y-2] != '*'))
            {
                expression[y] = original[x];
                f(x+1, y+1, z);
            }
            expression[y] = '+';
            expression[y+1] = original[x];
            f(x+1, y+2, z);
            expression[y] = '-';
            expression[y+1] = original[x];
            f(x+1, y+2, z);
            expression[y] = '*';
            expression[y+1] = original[x];
            f(x+1, y+2, z);
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        len = num.length();
        original = (char*)malloc(sizeof(char)*len);
        int i;
        for (i = 0; i < len; i++)
        {
            original[i] = num[i];
        }
        expression = (char*)malloc(sizeof(char)*(len<<1));
        stack = (long long*)malloc(sizeof(long long)*(len));
        ops = (char*)malloc(sizeof(char)*(len));
        f(0, 0, target);
        return result;
    }
};