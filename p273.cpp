class Solution {
public:

    const string number_english[20] = {"Zero ", "One ", "Two ", "Three ", "Four ", "Five ", "Six ", "Seven ", "Eight ", "Nine ", "Ten ", "Eleven ", "Twelve ", "Thirteen ", "Fourteen ", "Fifteen ", "Sixteen ", "Seventeen ", "Eighteen ", "Nineteen "};
    
    const string number_english_ten[10] = {"", "", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};

    string f(int num) {
        string result;
        if (num >= 100)
        {
            result += number_english[num/100]+"Hundred ";
            num %= 100;
        }
        if (num >= 20)
        {
            result += number_english_ten[num/10];
            num %= 10;
            if (num > 0)
            {
                result += number_english[num];
            }
        }
        else if (num > 0)
        {
            result += number_english[num];
        }
        return result;
    }

    string numberToWords(int num) {
        if (!num) return "Zero";
        string result;
        if (num >= 1000000000)
        {
            result += f(num/1000000000)+"Billion ";
            num %= 1000000000;
        }
        if (num >= 1000000)
        {
            result += f(num/1000000)+"Million ";
            num %= 1000000;
        }
        if (num >= 1000)
        {
            result += f(num/1000)+"Thousand ";
            num %= 1000;
        }
        if (num > 0)
        {
            result += f(num);
        }
        result[result.length()-1] = '\0';
        return result;
    }
};