class Solution {
public:
    bool wordPattern(string pattern, string str) {
        string arr[26];
        int i;
        for (i = 0; i < 26; i++)
        {
            arr[i] = "";
        }
        unordered_map<string, int> str_pat;
        stringstream ss;
        ss << str;
        string word;
        i = 0;
        while (ss >> word)
        {
            if (i >= pattern.length())
            {
                return false;
            }
            if (arr[pattern[i]-'a'] == "")
            {
                arr[pattern[i]-'a'] = word;
            }
            else if (arr[pattern[i]-'a'] != word)
            {
                return false;
            }
            if (str_pat.find(word) == str_pat.end())
            {
                str_pat[word] = pattern[i]-'a';
            }
            else if (str_pat[word] != pattern[i]-'a')
            {
                return false;
            }
            i++;
        }
        return i == pattern.length();
    }
};
