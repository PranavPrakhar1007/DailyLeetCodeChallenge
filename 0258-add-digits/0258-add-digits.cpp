class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num>0)
        {
            int rem = num%10;
            sum+=rem;
            num/=10;
        }
        while(sum>=10)
        {
            int sum1 = 0;
            while(sum>0)
            {
                int rem = sum%10;
                sum1+=rem;
                sum/=10;
            }
            sum = sum1;
        }
        return sum;
    }
};