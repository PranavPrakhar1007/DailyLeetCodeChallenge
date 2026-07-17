#pragma GCC optimize("O3,unroll-loops")
class Solution {
public:
    bool prime(int n) {
        if (n <= 1) return false;
        if (n == 2 || n == 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        return true;
    }

    int diagonalPrime(vector<vector<int>>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int maxi = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i][i] > maxi && prime(nums[i][i])) {
                maxi = nums[i][i];
            }
            if (nums[i][n - i - 1] > maxi && prime(nums[i][n - i - 1])) {
                maxi = nums[i][n - i - 1];
            }
        }
        
        return maxi;
    }
};