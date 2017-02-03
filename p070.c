int climbStairs(int n) {
    if (n&1) return (int)((exp(log((sqrt(5) + 1) / 2)*(n+1)) - exp(log((sqrt(5) - 1) / 2)*(n+1)))/sqrt(5) + 1e-4);
    else return (int)((exp(log((sqrt(5) + 1) / 2)*(n+1)) + exp(log((sqrt(5) - 1) / 2)*(n+1)))/sqrt(5) + 1e-4);
}
