class Solution {
public:

    const char mem[4][10][6] = {{"", "M", "MM", "MMM", "", "", "", "", "", ""}, {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}};

    string intToRoman(int num) {
        char result[20] = "";
        strcat(result, mem[0][num/1000]);
        strcat(result, mem[1][num/100%10]);
        strcat(result, mem[2][num/10%10]);
        strcat(result, mem[3][num%10]);
        return result;
    }
};