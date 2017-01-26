int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == -2147483648 && divisor == -1)) return 2147483647;
        if (dividend == 0) return 0;
        if (dividend == -2147483648 && divisor == 1) return -2147483648;
        bool negative = (dividend < 0) ^ (divisor < 0);
        unsigned ua = dividend, ub = divisor;
        if (dividend < 0 && dividend != -2147483648) ua = -dividend;
        if (divisor < 0 && divisor != -2147483648) ub = -divisor;
        if (ua < ub) return 0;
        unsigned result = 0;
        int i;
        for (i = 1; i <= 32; i++)
        {
            unsigned temp = (ua >> (32-i));
            if (temp >= ub)
            {
                result = (result << 1) + 1;
                ua -= (ub << (32-i));
            }
            else result <<= 1;
        }
        if (negative) return -(int)result;
        else return result;
}