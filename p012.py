class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num >= 3000: return "MMM"+self.intToRoman(num-3000)
        elif num >= 2000: return "MM"+self.intToRoman(num-2000)
        elif num >= 1000: return "M"+self.intToRoman(num-1000)
        elif num >= 900: return "CM"+self.intToRoman(num-900)
        elif num >= 500: return "D"+self.intToRoman(num-500)
        elif num >= 400: return "CD"+self.intToRoman(num-400)
        elif num >= 300: return "CCC"+self.intToRoman(num-300)
        elif num >= 200: return "CC"+self.intToRoman(num-200)
        elif num >= 100: return "C"+self.intToRoman(num-100)
        elif num >= 90: return "XC"+self.intToRoman(num-90)
        elif num >= 50: return "L"+self.intToRoman(num-50)
        elif num >= 40: return "XL"+self.intToRoman(num-40)
        elif num >= 30: return "XXX"+self.intToRoman(num-30)
        elif num >= 20: return "XX"+self.intToRoman(num-20)
        elif num >= 10: return "X"+self.intToRoman(num-10)
        elif num == 9: return "IX"
        elif num >= 5: return "V"+self.intToRoman(num-5)
        elif num == 4: return "IV"
        elif num == 3: return "III"
        elif num == 2: return "II"
        elif num == 1: return "I"
        return ""
        