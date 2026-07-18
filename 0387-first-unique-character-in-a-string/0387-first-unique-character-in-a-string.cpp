#pragma GCC optimize("O3,unroll-loops")
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}();

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = 1e5;
        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.find(c);
            if (first != string::npos && first == s.rfind(c)) {
                ans = min(ans, first);
            }
        }
        return ans == 1e5 ? -1 : ans;
    }
};