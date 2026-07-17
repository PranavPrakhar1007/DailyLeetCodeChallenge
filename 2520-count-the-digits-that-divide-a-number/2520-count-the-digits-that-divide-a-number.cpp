class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        int n = num;
        while(num)
        {
            int digit = num%10;
            if(n%digit==0)cnt++;
            num/=10;
        }
        return cnt;
    }
};