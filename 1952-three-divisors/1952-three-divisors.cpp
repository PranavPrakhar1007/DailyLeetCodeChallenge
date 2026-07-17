class Solution {
public:
    bool isThree(int n) {
        if (n <4)
            return false;
        int chksqrt = sqrt(n);
        int num = chksqrt * chksqrt;
        if (num != n)
            return false;
        for (int i = 2; i * i <= chksqrt; i++) {
            if (chksqrt % i == 0)
                return false;
        }
        return true;
    }
};