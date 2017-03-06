bool cmp(string &a, string &b) {
    return a+b > b+a;
}

class Solution {
public:

    string int2str(int n) {
        char temp[12];
        sprintf (temp, "%d", n);
        return temp;
    }

    string largestNumber(vector<int>& nums) {
        string *vstr = new string[nums.size()];
        int i, maxnum = 0;
        for (i = 0; i < nums.size(); i++)
        {
            vstr[i] = int2str(nums[i]);
            if (nums[i] > maxnum)
            {
                maxnum = nums[i];
            }
        }
        if (maxnum == 0) return "0";
        sort(vstr, vstr+nums.size(), cmp);
        string result = vstr[0];
        for (i = 1; i < nums.size(); i++)
        {
            result += vstr[i];
        }
        return result;
    }
};
