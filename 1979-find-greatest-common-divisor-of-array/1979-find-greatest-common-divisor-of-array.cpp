class Solution {
public:
    int fgcd(int a,int b)
    {
        if(a==0) return b;
        else if(b==0) return a;
        if(a<=b)
        {
            return fgcd(a,b%a);
        }
        else
        {
            return fgcd(a%b,b);
        }
    }
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin(),nums.end());
        int large = *max_element(nums.begin(),nums.end());
        int gcd = fgcd(small,large);
        return gcd;
    }
};