class Solution {
public:

    vector<int> number;
    vector<char> ops;
    vector<int> result;

    int g(int &n1, char &ops, int &n2)
    {
        if (ops == '+') return n1+n2;
        else if (ops == '-') return n1-n2;
        else return n1*n2;
    }

    void f(vector<int> &numberstack, vector<char> &opsstack, int x)
    {
        vector<int> newnumberstack = numberstack;
        vector<char> newopsstack = opsstack;
        if (x == ops.size())
        {
            while (!newopsstack.empty())
            {
                int newnumbertop = g(newnumberstack[newnumberstack.size()-2], newopsstack.back(), newnumberstack[newnumberstack.size()-1]);
                newnumberstack.pop_back();
                newopsstack.pop_back();
                newnumberstack[newnumberstack.size()-1] = newnumbertop;
            }
            result.push_back(newnumberstack[0]);
            return;
        }
        else
        {
            newnumberstack.push_back(number[x+1]);
            newopsstack.push_back(ops[x]);
            f(newnumberstack, newopsstack, x+1);
            newopsstack.pop_back();
            newnumberstack.pop_back();
            while (!newopsstack.empty())
            {
                int newnumbertop = g(newnumberstack[newnumberstack.size()-2], newopsstack.back(), newnumberstack[newnumberstack.size()-1]);
                newnumberstack.pop_back();
                newopsstack.pop_back();
                newnumberstack[newnumberstack.size()-1] = newnumbertop;
                newnumberstack.push_back(number[x+1]);
                newopsstack.push_back(ops[x]);
                f(newnumberstack, newopsstack, x+1);
                newopsstack.pop_back();
                newnumberstack.pop_back();
            }
        }
    }

    vector<int> diffWaysToCompute(string input) {
        number.clear();
        ops.clear();
        result.clear();
        int curnumber = 0;
        int len = input.length();
        int i;
        for (i = 0; i < len; i++)
        {
            if (input[i] >= '0' && input[i] <= '9')
            {
                curnumber = curnumber*10+input[i]-'0';
            }
            else
            {
                number.push_back(curnumber);
                curnumber = 0;
                ops.push_back(input[i]);
            }
        }
        number.push_back(curnumber);
        vector<int> numberstack;
        vector<char> opsstack;
        numberstack.push_back(number[0]);
        f(numberstack, opsstack, 0);
        return result;
    }
};
