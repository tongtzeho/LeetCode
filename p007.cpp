class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648 || x == 0) return 0;
        bool negative = x < 0;
        if (negative) x = -x;
        long long y = 0;
        int dx = 0;
        while (x > 0)
        {
            dx = x/10;
            y = (y<<3)+(y<<1)+x-(dx<<3)-(dx<<1);
            x = dx;
        }
        if (negative) y = -y;
        if (y < -2147483648 || y > 2147483647) return 0;
        return (int)y;
    }
};
