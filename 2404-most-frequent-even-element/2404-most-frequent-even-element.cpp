#pragma GCC optimize("O3,unroll-loops")
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int count[100001] = {0};
        int ans = -1;
        int maxFreq = 0;
        
        for (int x : nums) {
            if ((x & 1) == 0) {
                count[x]++;
                if (count[x] > maxFreq) {
                    maxFreq = count[x];
                    ans = x;
                } else if (count[x] == maxFreq && x < ans) {
                    ans = x;
                }
            }
        }
        return ans;
    }
};