class Solution {
public:
    int alternateDigitSum(int n) {
        int sz = to_string(n).size();
        int start = 1;
        if(sz%2==0) start = -1;
        int sum = 0;
        while(n>0)
        {
            int rem = n%10;
            sum = sum + rem*start;
            start = start*(-1);
            n/=10;
        }
        return sum;
    }
};