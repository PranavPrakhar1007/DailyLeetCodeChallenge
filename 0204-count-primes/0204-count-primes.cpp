class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        int cnt = n / 2;
        vector<bool> sieve(n, false);
        for (int i = 3; i * i < n; i += 2) {
            if (!sieve[i]) {
                for (int j = i * i; j < n; j += i * 2) {
                    if (!sieve[j]) {
                        cnt--;
                        sieve[j] = true;
                    }
                }
            }
        }
        return cnt;
    }
};