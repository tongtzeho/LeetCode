class Solution {
public:
    string longestPalindrome(string s) {
    	char str[1024];
    	int len = s.length();
    	int i, j, k;
    	for (i = 0; i < len; i++)
    	{
    		str[i] = s[i];
		}
        int ansstart = 0, ansend = 0;
        int curstart = 0, curend = 0;
        for (k = len/2; k < len; k++)
        {
        	if (ansend-ansstart > (len-k)*2) break;
        	i = k;
        	curstart = curend = i;
        	j = i-1;
        	while (j >= 0 && i*2-j < len)
        	{
        		if (str[j] == str[i*2-j])
        		{
        			curstart = j;
        			curend = i*2-j;
				}
				else
				{
					break;
				}
				j--;
			}
			if (curend-curstart > ansend-ansstart)
			{
				ansstart = curstart;
				ansend = curend;
			}
			if (i >= 1 && str[i] == str[i-1])
			{
				curstart = i-1;
				curend = i;
				j = i-2;
				while (j >= 0 && i*2-1-j < len)
				{
					if (str[j] == str[i*2-1-j])
					{
						curstart = j;
						curend = i*2-1-j;
					}
					else
					{
						break;
					}
					j--;
				}
				if (curend-curstart > ansend-ansstart)
				{
					ansstart = curstart;
					ansend = curend;
				}
			}
			if (i*2+1 == len) continue;
			i = len-1-k;
        	curstart = curend = i;
        	j = i-1;
        	while (j >= 0 && i*2-j < len)
        	{
        		if (str[j] == str[i*2-j])
        		{
        			curstart = j;
        			curend = i*2-j;
				}
				else
				{
					break;
				}
				j--;
			}
			if (curend-curstart > ansend-ansstart)
			{
				ansstart = curstart;
				ansend = curend;
			}
			if (i >= 1 && str[i] == str[i-1])
			{
				curstart = i-1;
				curend = i;
				j = i-2;
				while (j >= 0 && i*2-1-j < len)
				{
					if (str[j] == str[i*2-1-j])
					{
						curstart = j;
						curend = i*2-1-j;
					}
					else
					{
						break;
					}
					j--;
				}
				if (curend-curstart > ansend-ansstart)
				{
					ansstart = curstart;
					ansend = curend;
				}
			}
		}
		return s.substr(ansstart, ansend-ansstart+1);
    }
};