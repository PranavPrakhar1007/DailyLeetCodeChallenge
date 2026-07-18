#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("popcnt")
class Solution {
public:
    int kthGrammar(int n, int k) {
        return __builtin_popcount(k - 1) & 1;
    }
};