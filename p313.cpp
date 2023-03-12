class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if (n == 1)
            return 1;
        vector<int> res;
        int mem[170] = { 0 };
        res.reserve((size_t)n);
        res.emplace_back(1);
        for (int k = 1; k < n; ++k)
        {
            auto it = res.end() - 1;
            int back = res.back();
            long long back64 = (long long)back;
            long long minimum = 2147483647;
            for (size_t i = 0; i < primes.size(); ++i)
            {
                int p = primes[i];
                auto jt = res.begin() + mem[i];
                long long pro = (long long)(*jt) * (long long)p;
                if (pro <= back)
                {
                    int t = back / p + 1;
                    it = lower_bound(res.begin(), it + 1, t);
                    mem[i] = it - res.begin();
                    pro = (long long)(*it) * (long long)p;
                }
                else
                {
                    it = jt;
                }
                if (pro < minimum)
                {
                    minimum = pro;
                }
            }
            res.emplace_back((int)minimum);
        }
        return res.back();
    }
};